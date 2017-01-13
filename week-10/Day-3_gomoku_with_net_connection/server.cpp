#include "server.h"
using namespace std;

my_server::my_server() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  port = 4321;
  client = NULL;
  SDLNet_ResolveHost(&ip, NULL, port);
  server = SDLNet_TCP_Open(&ip);
}

my_server::~my_server() {
  SDLNet_TCP_Close(server);
  SDLNet_TCP_Close(client);
  SDLNet_Quit();
  SDL_Quit();
}

void my_server::set_port(char* port) {
  SDLNet_TCP_Close(server);
  SDLNet_Quit();
  SDLNet_Init();
  std::string s_port = (port);
  int i_port = atoi(s_port.c_str());
  this->port = (unsigned int) i_port;
  SDLNet_ResolveHost(&ip, NULL, this->port);
  server = SDLNet_TCP_Open(&ip);
}

bool my_server::is_online() {
  client = SDLNet_TCP_Accept(server);
  return (client);
}

void my_server::send_message(std::string new_message) {
  int l = new_message.length();
  SDLNet_TCP_Send(client, new_message.c_str(), l+1);
}


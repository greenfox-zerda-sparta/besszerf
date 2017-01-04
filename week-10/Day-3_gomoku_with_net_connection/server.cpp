#include "server.h"
using namespace std;

my_server::my_server() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  SDLNet_ResolveHost(&ip, NULL, 1234);
  server = SDLNet_TCP_Open(&ip);
  client = NULL;
  text_struct = {"", -1};
  is_send = false;
  listening = false;
  is_online = false;
}

void my_server::set_message(std::string new_message) {
  text_struct.message = new_message.c_str();
  text_struct.m_length = new_message.length() + 1;
  is_send = true;
}


void my_server::run() {
  listening = true;
  while (listening) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      is_online = true;
    }
    if(is_online && is_send) {
      SDLNet_TCP_Send(client, text_struct.message, text_struct.m_length);
      is_send = false;
    }
  }
}

void my_server::stop() {
  SDLNet_TCP_Close(client);
  listening = false;
  is_online = false;
}

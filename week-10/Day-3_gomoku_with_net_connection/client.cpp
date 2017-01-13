#include "client.h"
#include <iostream>

my_client::my_client() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  set_remote_ip("127.0.0.1");
  message[0] = '\0';
  server_port = 1234;
  client = 0;
  socketSet = SDLNet_AllocSocketSet(1);
}

my_client::~my_client() {
  SDLNet_FreeSocketSet(socketSet);
  SDLNet_TCP_Close(client);
  SDLNet_Quit();
  SDL_Quit();
}

void my_client::set_remote_ip(std::string server_ip) {
  int l = server_ip.length();
  for (int i = 0; i < l; ++i) {
    this->server_ip[i] = server_ip[i];
  }
  this->server_ip[l] = '\0';
}

void my_client::set_remote_port(char* port) {
  std::string s_port = (port);
  int i_port = atoi(s_port.c_str());
  unsigned int ui_port = (unsigned int) i_port;
  server_port = ui_port;
}

bool my_client::connect() {
  SDLNet_ResolveHost(&ip, server_ip, server_port);
  client = SDLNet_TCP_Open(&ip);
  if (client == NULL) {
    return false;
  } else {
    SDLNet_TCP_AddSocket(socketSet, client);
    return true;
  }
}

bool my_client::is_socket_active() {
  int activeSockets = SDLNet_CheckSockets(socketSet, 500);
  return (activeSockets != 0);
}

bool my_client::has_message() {
  int gotMessage = SDLNet_SocketReady(client);
  return (gotMessage > 0);
}

std::string my_client::get_message() {
  std::string result = "";
  int serverResponseByteCount = SDLNet_TCP_Recv(client, message, 128);
  if (serverResponseByteCount > 0) {
    int i = 0;
    while(message[i] != '\0') {
      result += message[i];
      ++i;
    }
  }
  message[0] = '\0';
  return result;
}


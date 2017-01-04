#include "client.h"

my_client::my_client(std::string server_ip) {
  this->server_ip = '';
  set_ip(server_ip);
  SDLNet_Init();
  SDLNet_ResolveHost(&ip, this->server_ip, 1234);
  has_message = false;
  message = "";
  listening = false;
}

void my_client::run() {
  client = SDLNet_TCP_Open(&ip);
  listening = true;
  while (listening) {
    if (!has_message) {
      SDLNet_TCP_Recv(client, message, 100);
      has_message = true;
    }
  }
}

std::string my_client::get_message() {
  std::string result = "";
  if (has_message) {
    int i = 0;
    while(message[i] != '\0') {
      result += message[i];
      ++i;
    }
    message = "";
    has_message = false;
  }
  return result;
}

void my_client::stop() {
  listening = false;
  SDLNet_TCP_Close(client);
}

void my_client::set_ip(std::string server_ip) {
  int l = server_ip.length();
  this->server_ip[l + 1];
  for (int i = 0; i < l; ++i) {
    this->server_ip[i] = server_ip[i];
  }
  this->server_ip[l] = '\0';
}

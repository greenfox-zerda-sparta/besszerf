#ifndef SERVER_H_
#define SERVER_H_
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_net.h>

struct to_send {
    char* message;
    int m_length;
};
class my_server {
  public:
    my_server();
    ~my_server();
    bool is_online();
    void send_message(std::string);
    void set_port(char*);
  private:
    unsigned int port;
    TCPsocket server;
    TCPsocket client;
    IPaddress ip;
};

#endif /* SERVER_H_ */

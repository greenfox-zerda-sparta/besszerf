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
    void run();
    void stop();
    void send();
    void set_message(std::string);
  private:
    TCPsocket server;
    TCPsocket client;
    IPaddress ip;
    bool is_send;
    bool listening;
    to_send text_struct;
    bool is_online;
};




#endif /* SERVER_H_ */

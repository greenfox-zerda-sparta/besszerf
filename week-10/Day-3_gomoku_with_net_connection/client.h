#ifndef CLIENT_H_
#define CLIENT_H_
#include <SDL_net.h>
#include <string>

class my_client {
  public:
    my_client();
    ~my_client();
    bool is_socket_active();
    void set_remote_ip(std::string server_ip);
    void set_remote_port(char*);
    bool connect();
    bool has_message();
    std::string get_message();
    SDLNet_SocketSet socketSet;
  private:
    TCPsocket client;
    IPaddress ip;
    unsigned int server_port;
    char server_ip[16];
    char message[128];
};

#endif /* CLIENT_H_ */

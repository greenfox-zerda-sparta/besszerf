#ifndef CLIENT_H_
#define CLIENT_H_
#include <string>

class my_client {
  public:
    my_client(std::string server_ip);
    void run();
    void stop();
    std::string get_message();
    void set_ip(std::string server_ip);
  private:
    TCPsocket client;
    IPaddress ip;
    char* server_ip;
    char message[100];
    bool listening;
    bool has_message;
};



#endif /* CLIENT_H_ */

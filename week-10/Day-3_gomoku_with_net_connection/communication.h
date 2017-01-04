#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_
#include "server.h"
#include "client.h"
#include "game.h"
#include "settings.h"

class Communication {
  public:
    Communication(Game* game, std::string remote_server_ip);
    void handle(coordinate&);
  private:
    my_server server;
    my_client client;
    Game* game;
    void decide_player1();
    bool player1;
    std::string remote_server_ip;
};



#endif /* COMMUNICATION_H_ */

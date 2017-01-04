#include "communication.h"

Communication::Communication(Game* game, std::string remote_server_id) {
  this->game = game;
  player1 = false;
  server.run();
  this->remote_server_ip = remote_server_ip;
  client(remote_server_ip);
  client.run();
  decide_player1();
}

void Communication::decide_player1() {

}


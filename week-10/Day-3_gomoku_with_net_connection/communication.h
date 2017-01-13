#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_
#include "server.h"
#include "gui.h"
#include "client.h"
#include "game.h"
#include "settings.h"
#include <cstdlib>

class Communication {
  public:
    Communication(GUserInterface& gui, Game& game, std::string remote_server_ip);
    void send(std::string);
    std::string receive();
    void run();
    void set_server_port(char* port);
    void set_remote_server_port_to_client(char* port);
    void set_remote_server_ip_to_client(std::string remote_server_ip);
  private:
    my_server server;
    my_client client;
    bool server_is_online;
    bool client_is_online;
    GUserInterface* gui;
    void determine_player();
    bool is_block_send_coordinate;
    std::string remote_server_ip;
    std::string int_to_string(int);
    int string_to_int(std::string);
    std::string coord_to_string(coordinate);
    coordinate string_to_coord(std::string);
    std::string incoming_message;
    data_share shared_data;
    void* run_gui(void* param);
    void connect_other_game();
    bool next_round(coordinate&);
    bool is_new_game_pushed(unsigned int x, unsigned int y);
    bool is_quit_pushed(unsigned int x, unsigned int y);
};



#endif /* COMMUNICATION_H_ */

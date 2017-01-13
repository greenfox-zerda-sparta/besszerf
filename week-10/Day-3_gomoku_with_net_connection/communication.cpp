#include "communication.h"
#include "settings.h"
#include <sstream>
#include <pthread.h>
#include <unistd.h>

Communication::Communication(GUserInterface& gui, Game& game, std::string remote_server_ip) {
  this->gui = &gui;
  shared_data.game = &game;
  incoming_message = "";
  this->remote_server_ip = remote_server_ip;
  client.set_remote_ip(this->remote_server_ip);
  shared_data.coord = {0, 0};
  shared_data.x = -1;
  shared_data.y = -1;
  shared_data.game_over = false;
  shared_data.is_new_game_clicked = false;
  shared_data.is_quit_clicked = false;
  shared_data.quit = false;
  shared_data.player = 0;
  server_is_online = false;
  client_is_online = false;
  is_block_send_coordinate = false;
}

void Communication::run() {
  gui->init(shared_data);
  gui->run();
  connect_other_game();
  determine_player();
  gui->draw_board(shared_data.game->gameboard);
  gui->draw_player_sprite();
  shared_data.x = -1;
  shared_data.y = -1;
  std::string message;
  while (!shared_data.quit) {
    gui->run();
    if(shared_data.x / tile_width > 18 || shared_data.y / tile_height > 18) {
      shared_data.x = -1;
      shared_data.y = -1;
    }
    if (shared_data.game_over) {
      is_new_game_pushed(shared_data.x, shared_data.y);
      is_quit_pushed(shared_data.x, shared_data.y);
      if (shared_data.is_new_game_clicked) {
        shared_data.game_over = false;
        shared_data.is_new_game_clicked = false;
        gui->draw_right_vp();
        shared_data.x = -1;
        shared_data.y = -1;
        gui->draw_board(shared_data.game->gameboard);
      } else if (shared_data.is_quit_clicked) {
        shared_data.quit = true;
        return;
      }
      continue;
    }
    if(is_block_send_coordinate) {
      message = "";
      message = receive();
      if (message != "") {
        coordinate coord = string_to_coord(message);
        next_round(coord);
        is_block_send_coordinate = false;
      }
    }
    if (!is_block_send_coordinate && !shared_data.game_over && shared_data.x != -1) {
      if (shared_data.player == shared_data.game->get_current_player().number) {
        int x = shared_data.x / tile_width;
        int y = shared_data.y / tile_height;
        coordinate coord = {x, y};
        if (next_round(coord) && shared_data.player == shared_data.game->get_current_player().number) {
          continue;
        }
        std::string proba = coord_to_string(coord);
        send(proba);
        is_block_send_coordinate = true; //
      }
    }
    gui->remove_mouse_events();
    shared_data.x = -1;
    shared_data.y = -1;
  }
}

bool Communication::is_new_game_pushed(unsigned int x, unsigned int y) {
  if (x < gui->panel.pos_x + gui->panel.new_game_button.x + gui->panel.new_game_button.width &&
      x > gui->panel.pos_x + gui->panel.new_game_button.x &&
      y < gui->panel.pos_y + gui->panel.new_game_button.y + gui->panel.new_game_button.height &&
      y > gui->panel.pos_y + gui->panel.new_game_button.y) {
    shared_data.is_new_game_clicked = true;
    return true;
  }
  return false;
}

bool Communication::is_quit_pushed(unsigned int x, unsigned int y) {
  if (x < gui->panel.pos_x + gui->panel.quit_button.x + gui->panel.quit_button.width &&
      x > gui->panel.pos_x + gui->panel.quit_button.x &&
      y < gui->panel.pos_y + gui->panel.quit_button.y + gui->panel.quit_button.height &&
      y > gui->panel.pos_y + gui->panel.quit_button.y) {
    shared_data.is_quit_clicked = true;
    return true;
  }
  return false;
}

void Communication::connect_other_game(){
  while(!client_is_online || !server_is_online) {
    if (!server_is_online) {
      if (server.is_online()) {
        server_is_online = true;
      }
    }
    if (!client_is_online) {
      if (client.connect()) {
        client_is_online = true;
      }
    }
  }
}

bool Communication::next_round(coordinate& coord) {
  if(!shared_data.game->next_turn(coord)) {
    gui->run_game_over_routine();
    return false;
  } else {
    gui->draw_right_vp();
    gui->draw_board(shared_data.game->gameboard);
  }
  return true;
}


void Communication::determine_player() {
  while(true) {
    int my_number = rand() % 128000;
    send(int_to_string(my_number));
    std::string message = "";
    message = receive();
    if (string_to_int(message) > my_number) {
      shared_data.player = 2;
      std::cout << "Player 2" << std::endl;
      is_block_send_coordinate = true;
      break;
    } else if (string_to_int(message) < my_number){
      shared_data.player = 1;
      std::cout << "Player 1" << std::endl;
      break;
    }
  }
}

std::string Communication::int_to_string(int x) {
  std::string result = "";
  stringstream z;
  z << x;
  result = z.str();
  return result;
}

int Communication::string_to_int(std::string x) {
  return atoi(x.c_str());
}

std::string Communication::coord_to_string(coordinate coord) {
  std::string result = "";
  stringstream z;
  stringstream s;
  z << (int)coord.first;
  z << " ";
  z << (int)coord.second;
  result = z.str();
  return result;
}

coordinate Communication::string_to_coord(std::string x) {
  coordinate result;
  std::size_t index = x.find(" ");
  std::string first_pos = x.substr(0, index);
  std::string second_pos = x.substr(index + 1);
  int first_p = string_to_int(first_pos);
  int second_p = string_to_int(second_pos);
  result.first = (char)first_p;
  result.second = (char)second_p;
  return result;
}

void Communication::send(std::string message) {
  server.send_message(message);
}

std::string Communication::receive() {
  std::string m = "";
  if (client.is_socket_active() && client.has_message()) {
    m = client.get_message();
  }
  return m;
}


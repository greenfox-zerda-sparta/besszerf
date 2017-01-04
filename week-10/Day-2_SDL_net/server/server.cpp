#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <unistd.h>
using namespace std;

int main( int argc, char* args[] )
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, NULL, 1234);
  TCPsocket server = SDLNet_TCP_Open(&ip);
  TCPsocket client;
  const char* text = "Alma";
  int i = 0;
  bool is_send = false;
  while (1) {
      client = SDLNet_TCP_Accept(server);
      if (client) {
        is_send = true;
      }
      if(is_send) {
        for(; i < 10; ++i) {
          SDLNet_TCP_Send(client, text, 5);
          sleep(3);
        }
      }
      if (i > 9) {
        SDLNet_TCP_Close(client);
        break;
      }
  }
  SDL_Quit();
  return 0;
}





#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  IPaddress ip;
  SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
  TCPsocket client = SDLNet_TCP_Open(&ip);
  char text[100];
  bool quit = false;
  int i = 0;
  while (!quit) {
    SDLNet_TCP_Recv(client, text, 100);
    std::cout << i + 1 << ". " << text << std::endl;
    ++i;
    if (i == 10) quit = true;
  }
  SDLNet_TCP_Close(client);
  SDL_Quit();
  return 0;
}

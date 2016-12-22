#ifndef CLUI_H_
#define CLUI_H_
#include "ui.h"

using namespace std;

class CLUserInterface : public UserInterface{
  public:
    CLUserInterface(Game& game);
    void run();
  private:

};
#endif /* CLUI_H_ */


#ifndef CLUI_H_
#define CLUI_H_
#include "ui.h"

using namespace std;

class CLUserInterface : public UserInterface{
  public:
    CLUserInterface(data_share& data);
    void run();
  private:
    void draw_board();
    data_share* data;

};
#endif /* CLUI_H_ */


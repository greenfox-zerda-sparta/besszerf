#include <string>
#include <iostream>

using namespace std;

struct RectangularCuboid {
  double a;
  double b;
  double c;
};

int get_surface(RectangularCuboid inst) {
  return ((inst.a * inst.b) + (inst.a * inst.c) + (inst.c * inst.b))*2;
}


int get_volume(RectangularCuboid inst) {
  return inst.a * inst.b *inst.c;
}
// Write a function called "get_surface" that takes a RectangularCuboid
// and returns it's surface

// Write a function called "get_volume" that takes a RectangularCuboid
// and returns it's volume

int main() {
  RectangularCuboid brick = {2, 3, 4};
  cout << "Surface is: " << get_surface(brick) << " m2"<< endl;
  cout << "Volume is: " << get_volume(brick) << " m3"<< endl;
  return 0;
}

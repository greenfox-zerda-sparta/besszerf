#include <string>
#include <iostream>

using namespace std;

struct Computer {
  string name;
  long int cpu_speed_hz;
  long int ram_size;
};

void print_computer(Computer inst) {
  cout << inst.name << endl << inst.cpu_speed_hz << endl << inst.ram_size << endl;
}

int main() {
  Computer computer = {"Macbook", 3.2e9, 8e9};

  // Change the name of the computer to "Macbook Pro" and print all the stats
  computer.name = "Macbook Pro";
  print_computer(computer);

  return 0;
}

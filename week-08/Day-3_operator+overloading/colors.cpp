#include <iostream>
#include <string>
#include <cstdint>
#include <cstdlib>
#include <cctype>
#include <exception>
#include <sstream>

using namespace std;

class Color {
  public:
    Color();
    Color(uint8_t red, uint8_t green, uint8_t blue);
    Color(string color) throw ();
    Color(const Color& other);
    Color blend(const Color& other);
    void darken(float how_much);
    void lighten(float how_much);
    void print() const;
  private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t string_to_color(string& color, int position);
    bool is_hexadecimal(string color);
};

Color::Color() {
  red = 0;
  green = 0;
  blue = 0;
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue) {
  this->red = red;
  this->green = green;
  this->blue = blue;
}

Color::Color(string color) throw(){
  if (is_hexadecimal(color)) {
    red = string_to_color(color, 1);
    green = string_to_color(color, 3);
    blue = string_to_color(color, 5);
  } else {
    throw;
  }
}

bool Color::is_hexadecimal(string color) {
  if (color.length() == 7 && color[0] == '#') {
    for (unsigned int i = 1; i < color.length(); ++i) {
      if (! isxdigit(color[i])) {
        return false;
      }
    }
  } else {
    return false;
  }
  return true;
}

uint8_t Color::string_to_color(string& color, int position) {
  stringstream str;
  str << color.substr(position,2);
  int result;
  str >> hex >> result;
  return (uint8_t)result;
}

void Color::print() const {
  cout<< "rgb("  << (int)red << ", " << (int)green << ", " << (int)blue << ")" << endl;
}

Color::Color(const Color& other) {
  red = other.red;
  green = other.green;
  blue = other.blue;
}

void Color::darken(float how_much) {
  if(how_much > 1 || how_much < 0) return;
  red = (float)red*(1-how_much);
  green = (float)green*(1-how_much);
  blue = (float)blue*(1-how_much);
}

void Color::lighten(float how_much) {
  if(how_much > 1 || how_much < 0) return;
  int _red = red + float(255*how_much);
  int _green = green + float(255*how_much);
  int _blue = blue + float(255*how_much);
  red = _red>255?255:_red;
  green = _green>255?255:_green;
  blue = _blue>255?255:_blue;
}

Color Color::blend(const Color& other) {
  uint8_t _red = ((int)red + (int)other.red)/2;
  uint8_t _green = ((int)green + (int)other.green)/2;
  uint8_t _blue = ((int)blue + (int)other.blue)/2;
  return Color(_red, _green, _blue);
}

int main() {
  Color red("#FF1010");
  Color blue("#0000FF");
  Color other = red.blend(blue);
  red.darken(0.8);
  other.print();
  red.print();
  return 0;
}

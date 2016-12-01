#include <iostream>
#include <string>

using namespace std;

const float PI = 3.1415;

class Circle {
  private:
    float radius;

  public:
    Circle(float r) {
      this->radius = r;
    }
    double get_circumference() const {
      return 2*radius*PI;
    }
   double get_area() const {
      return radius*radius*PI;
    }
};

int main() {
    // Create a `Circle` class that takes it's radius as cinstructor parameter
    // It should have a `get_circumference` method that returns it's circumference
    // It should have a `get_area` method that returns it's area
    Circle my_circle(5.5);
    cout << my_circle.get_circumference() << ", " << my_circle.get_area() << endl;
  return 0;
}

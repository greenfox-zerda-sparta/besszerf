#ifndef SHAPE_HPP_
#define SHAPE_HPP_
#include <string>

using namespace std;
// Add a variable to the Shape class. Make it "protected".
//    This should be called mArea.
// Create a function that calculates the areas of the shape.
// Update the shapes Triangle and Square to have variables that represent their dimensions,
//   that you will need to calculate the area. One whould be width, the other height.
// Implement getter and setter functions for them.
// Make sure to call the function that calculates the area and stores it in mArea,
//   in the setter functions.
// Create a constructor that takes the height and width as it's parameters.
// Create a destructor, that destructs the objects.
//
// Write code into the main function that uses these.
// Make sure it demonstrates how the class works by printing out the results.

class Shape {

  public:
    virtual string* getName();
    Shape();
    Shape(float, float);
    virtual ~Shape();
    virtual float get_area();
    const float get_height();
    const float get_width();
    void set_height(float);
    void set_width(float);

  protected:
    float mArea;

  private:
    float calculate_area();
    float height;
    float width;

};

#endif /* SHAPE_HPP_ */

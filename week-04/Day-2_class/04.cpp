#include <iostream>
#include <string>

using namespace std;

class Student {
  private:
    string name;
    unsigned int age;
  public:
    Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }

    string greet() {
      return "Hello my name is: " + this->name;
    }

    void set_name(string new_name) {
        this->name = new_name;
    }
};

int main() {
  // Create a method on student that takes a string as an argument and
  // changes it's name property
  Student first_student("John", 21);
  first_student.set_name("Johnny Walker");
  cout << first_student.greet() << endl;

  return 0;
}

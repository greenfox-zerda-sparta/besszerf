#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    string name;
    unsigned int age;
    Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }
    string greet() {
    cout << "Hello, my name is " << name << endl;
    }

};

int main() {
  // Create a method on the Student class called "greet" that returns a string
  // like: "Hello my name is: <student name>"
  Student first_student("John", 21);
  first_student.greet();
  return 0;
}

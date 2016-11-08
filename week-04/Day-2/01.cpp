#include <iostream>
#include <string>

using namespace std;

class Student {
  public:
    string name;
    unsigned int age;
};

int main() {
  // Create a new instace of the Student class and set it's name to "John" and
  // it's age to 21
  Student first_student;
  first_student.name = "John";
  first_student.age = 21;

  cout << first_student.name << "; " << first_student.age << endl;

  return 0;
}
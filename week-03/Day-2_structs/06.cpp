#include <string>
#include <iostream>

using namespace std;

enum Subject {MATH, HISTORY, ENGLISH, SCIENCE};

string in_words[4] = {"Math", "History", "English", "Science"};

struct Grade {
  Subject subject;
  int value;
};

struct Student {
  string name;
  int age;
  Grade* grades;
  int grade_count;
};

// Create a function the constructs a Student (returns a pointer to a new student)
// It should take it's name and it's age as parameter
// It should allocate 5 grades
// It should set the grade_count to 0

Student* construct(string name, int age) {
  Student* new_student = new Student;
  new_student->name = name;
  new_student->age = age;
  new_student->grades = new Grade[5];
  new_student->grade_count = 0;
  return new_student;
}

// Create a function that takes 3 parameters:
// A reference to a Student
// A Subject
// An int (1-5)
// It should set the last grade's values with the given arguments

void set_grade(Student &student, Subject subject, int grade) {
  student.grades[student.grade_count].subject = subject;
  student.grades[student.grade_count].value = grade;
  student.grade_count++;
}

// Create a function that takes a Student as a reference and returns the subject
// that the student has worst grade in

string worst_subject_of(Student &student) {
  int worst_grade = student.grades[0].value;
  int worst_subject = student.grades[0].subject;
  for (int i = 1; i < student.grade_count; i++) {
    if (student.grades[i].value < worst_grade) {
      worst_grade = student.grades[i].value;
      worst_subject = student.grades[i].subject;
    }
  }
  return in_words[worst_subject];
}

// Create a function that deconstructs a Student
// It should take a pointer that points to the student
// It should deallocate each Grade and the Student itself

void destruct(Student *student) {
  delete[] student->grades;
  delete student;
}

int main() {
  Student* Jesus = construct("Jesus", 2016);
  set_grade(*Jesus, MATH, 5);
  set_grade(*Jesus, SCIENCE, 4);
  cout << " Worst subject for Jesus: " << worst_subject_of(*Jesus) << endl;
  destruct(Jesus);
  return 0;
}
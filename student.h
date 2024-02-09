#ifndef STUDENT_H
#define STUDENT_H
//#include "node.h" unnecessary because i made it a struct instead
using namespace std;


class Student {

public:
  Student();
  Student(const char* fName, const char* lName, int id, float studentGPA);
  ~Student();
  
  char* getFirstName();
  char* getLastName();

  int getStudentId();

  float getGPA();

  void setFirstName(const char*);
  void setLastName(const char*);
  void setStudentId(int);

  void setGPA(float);

private:
  char* firstName;
  char* lastName;
  int studentId;
  float gpa;
};

#endif

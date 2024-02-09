#include "student.h"
#include <cstring>
#include "node.h"
#include "studentlist.h"
using namespace std; 
/*
//https://www.youtube.com/watch?v=gfQ64d7uOw4
I suppose that youtube video is also a source but i mainly used the other one
*/
Student::Student() 
{
    firstName = nullptr;
    lastName = nullptr;
    studentId = 0;
    gpa = 0.0;
}
Student::Student(const char* fName, const char* lName, int id, float studentGPA) 
{
  firstName = new char[strlen(fName) + 1];
  lastName = new char[strlen(lName) + 1];
  strcpy(firstName, fName);
  strcpy(lastName, lName);
  studentId = id;
  gpa = studentGPA;
}
Student::~Student() 
{
    // Cleanup Student name char arrays
    delete[] firstName;
    delete[] lastName;
}

char* Student::getFirstName() 
{
    return firstName;
}

char* Student::getLastName()
 {
    return lastName;
}

int Student::getStudentId()
 {
    return studentId;
}

float Student::getGPA() 
{
    return gpa;
}

void Student::setFirstName(const char* fName) 
{
    if(firstName)
    {
        delete[] firstName;
        firstName = new char[strlen(fName)+1];
        strcpy(firstName, fName);

    }
}

void Student::setLastName(const char* lName) 
{
    if(lastName)
    {
        delete[] lastName;
        lastName = new char[strlen(lName)+1];
        strcpy(lastName, lName);

    }
}

void Student::setStudentId(int id) 
{
    studentId = id;
}

void Student::setGPA(float studentGPA)
{
    gpa = studentGPA;
}

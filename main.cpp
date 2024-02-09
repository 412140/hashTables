#include "student.h"
#include "studentlist.h"
#include "node.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
/*
ghazi abbas
<<<<<<< HEAD
spring sem cpp-ds galbraith
sources:
https://www.youtube.com/watch?v=riO8Rgunc0o
https://www.youtube.com/watch?v=2_3fR-k-LzI


=======
fall semester C++ second part of linked lists/student list project
galbraith

sources:
>>>>>>> d37a35782a09b0286c0fe7cb1952ab4f77a17c9c

*/

int main()
{
 StudentList studentList;

  char cmd[20];
  int studentId;
  float gpa;


  while(true)
  {
    cout << "ennter command: quit, add, print, delete, avg";
    cin >> cmd;
    cin.ignore();
    if(strcmp(cmd, "quit")==0)
    {
<<<<<<< HEAD
      //studentList.quit();
=======
      studentList.quit();
>>>>>>> d37a35782a09b0286c0fe7cb1952ab4f77a17c9c
      break; //got it :) 
    } else if(strcmp(cmd, "add")==0) {
      
      studentList.addStu();
      
    } else if(strcmp(cmd, "print")==0) {
      studentList.printStu();
    
    }  else if(strcmp(cmd, "delete")==0) {
      studentList.delStu();

    
    
    } else if(strcmp(cmd,"avg")==0) {
      studentList.calcAvg();

    } else { cout << "unidentified command word (or my code doesnt work ) Try again." <<endl;}
      
  }
  return 0;
} 
  

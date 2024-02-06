#include "student.h"
#include "studentlist.h"
#include "node.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
/*
ghazi abbas
fall semester C++ second part of linked lists/student list project
galbraith

sources:

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
      studentList.quit();
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
  

#include "student.h"
#include "studentlist.h"
//#include "node.h" implemented as struct in studentlist.cpp
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
/*
ghazi abbas
spring sem cpp-ds galbraith
sources:
https://www.youtube.com/watch?v=riO8Rgunc0o
https://www.youtube.com/watch?v=2_3fR-k-LzI

+ canvas videos 
+ random websites or c++ stl library pages for pretty much everything 
using fstream
*/

int main()
{
 StudentList studentList;

  char cmd[20];
  //int studentId;
  float gpa;


  while(true)
  {
    cout << "ennter command: quit, add, print, delete, avg";
    cin >> cmd;
    cin.ignore();
    if(strcmp(cmd, "quit")==0)
    {
      //studentList.quit();
      break; //got it :) 
    } else if(strcmp(cmd, "add")==0) {
      cout << "How many?: ";
      int num;
      cin >> num;

      for(int z = 0; z < num; z++)
      {
      char* firstName = studentList.genName("first_names.txt");
      char* lastName = studentList.genName("last_names.txt");
      int id = studentList.genId();
      float gpa = studentList.genGpa();
      studentList.addStu(firstName, lastName, id, gpa);
      }
     
    } else if(strcmp(cmd, "print")==0) {
      studentList.printStu();
    
    }  else if(strcmp(cmd, "delete")==0) {
      int id;
      cout << "Enter student ID to delete: ";
      cin >> id;
      studentList.delStu(id);
    
    } else if(strcmp(cmd,"avg")==0) {
      studentList.calcAvg();

    } else { cout << "unidentified command word (or my code doesnt work ) Try again." <<endl;}
      
  }
  return 0;
} 
  

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "student.h"
#include <iostream>
#include <fstream>//https://cplusplus.com/reference/fstream/fstream/
#include <cstdlib>
#include <ctime>

using namespace std;

class StudentList
{
 public:
  StudentList();
  ~StudentList();
 //private:
  static const int SIZE = 100;
  //i thought implementing it here would be valid due to troubleshooting concerns 
  struct Node
  {
    Student* data;
    Node* next;
  
  };

  Node* hashTable[SIZE]= {nullptr};
  int currStu=0;

  int hashFxn(const char* key);

  void addStu(const char* firstName, const char* lastName, int id, float gpa);
  void printStu();
  void delStu(int id);
  void calcAvg();

  void insertToList(Node*& head, Student* student);
  void resizeTable();
  void handleCollisions(int index, Student* newStu);
  void readFile(const char* fileName, char*** names, int* count);  
  void deleteList(Node*& head);
  int genId();
  float genGpa();
  char* genName(const char* fileName);
  
};

#endif

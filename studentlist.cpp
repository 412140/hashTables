#include "studentlist.h"
//includes should carry

//god bless copy and paste because i never want to write "StudentList::" again

StudentList::StudentList()
{
  srand(time(nullptr));
  for(int x=0; x<SIZE; ++x)
  {
    hashTable[x]=nullptr;
  }

}

StudentList::~StudentList()
{
  for(x=0;x<SIZE; ++x)
    {
      deleteList(hashTable[i]);
    }

}

int StudentList::hashFxn(const char* key)
{
  //count letters add it up then divide it and use remainder as value
  int hash=0;//has to be zero
  for(int x = 0; key[x] != '\0'; ++x)
  {
    hash += key[x];

  }
  return hash % SIZE;
  //according to the video this is best practice, not having an extra variable of used memory, which i guess makes sense

}

 void StudentList::addStu(const char* firstName, const char* lastName, int id, float gpa)
{
  //check for resize
  if(currStu >= SIZE/2)
  {
    resizeTable();

  }
  Student* newStudent = new Student(firstName, lastName, id, gpa);
  int index = hashFxn(firstName);
  //collisions
  if(hashTable[index]==nullptr)
  {
    hashTable[index] = new Node;
    hashTable[index]->data = newStudent;
    hashTable[index]->next = nullptr;
    
  } else
  {
    handleCollisions(index, newStudent);
  }
  currStu++;

}

 void StudentList::printStu()
 {
   for(int x=0; x<SIZE; ++x)
   {
     Node* curr = hashTable[x];
     while(curr != nullptr)
     {
       cout << "ID: "<< curr->data->getStudentId()<<
	 ", Name: "<< curr->data->getStudentFirstName()<<
	 " "<< curr->data->getStudentLastName()<<
	 ", GPA:"<<curr->getStudentGPA()<< endl;
       curr=curr->next;
     }
   }
 }

 void StudentList::delStu(int id)
 {
     for (int x = 0; x < tableSize; ++x) 
     {
        Node* current = hashTable[x];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data->getStudentId() == id) {
                if (prev == nullptr) {
                    hashTable[x] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current->data;
                delete current;
                currentStudents--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    cout << "Student with ID " << id << " not found. Or my code broke." << endl;


 }

 void StudentList::calcAvg()
 {
  if (currentStudents == 0) 
  {
    cout << "No students in the list." << endl;
     return;
  }
    float totalGPA = 0.0;
    int count = 0;
    for (int z = 0; z < tableSize; ++z) 
    {
        Node* current = hashTable[z];
        while (current != nullptr) 
        {
            totalGPA += current->data->getGPA();
            count++;
            current = current->next;
        }
    }
    cout << "AVG GPA:" << totalGPA / count << endl;

 }

 void StudentList::insertToList(const char* fileName)
 {
    Node* newNode = new Node;
    newNode->data = student;
    newNode->next = head;
    head = newNode;
 }

 void StudentList::resizeTable()
 {
  Node* newHashTable[tableSize * 2] = {nullptr};
    for (int i = 0; i < tableSize; ++i) 
    {
        Node* current = hashTable[i];
        while (current != nullptr) {
            int newIndex = hashFunction(current->data->getFirstName());
            insertIntoList(newHashTable[newIndex], current->data);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    // Update tableSize
    tableSize *= 2;
    // Free memory of old hashTable
    for (int i = 0; i < tableSize / 2; ++i) 
    {
        hashTable[i] = nullptr;
    }
    // Update hashTable to newHashTable
    for (int i = 0; i < tableSize; ++i) 
    {
        hashTable[i] = newHashTable[i];
    }

 }

void StudentList::handleCollisions(int index, Student* newStu)
 {
  Node* current = hashTable[index];
  while (current->next != nullptr) 
  {
      current = current->next;
  }
  current->next = new Node;
  current->next->data = newStudent;
  current->next->next = nullptr;

 }
 void StudentList::readFile(const char* fileName, char** names, int* count)
 {
    ifstream file(fileName);
    if (!file) 
    {
        cerr << "Error: Unable to open file " << fileName << endl;
        exit(1);
    }
    count = 0;
    string line;
    while (getline(file, line)) 
    {
        count++;
    }
    file.clear(); // Clear eof flag
    file.seekg(0, ios::beg); // Rewind lol
    // Allocate memory for names
    *names = new char*[count];
    // Read names from file
    for (int i = 0; i < count; ++i) 
    {
        getline(file, line);
        (*names)[i] = new char[line.length() + 1];
        strcpy((*names)[i], line.c_str());
    }
    file.close();


 }

 void StudentList::deleteList(Node*& head)
 {
  while (head != nullptr) 
  {
    Node* temp = head;
    head = head->next;
    delete temp->data;
    delete temp;
  }

 }
 int StudentList::genId()
 {
  return rand() % 1000 + 1000;
 }

 float StudentList::genGpa()
 {
  return (rand() % 400) / 100.0;
 }
 char* StudentList::genName(const char* fileName)
 {
  ifstream file(fileName);
    if (!file) 
    {
        cerr << "Error: Unable to open file " << fileName << endl;
        exit(1);
    }
    int count = 0;
    string line;
    while (getline(file, line)) 
    {
        count++;
    }
    file.clear(); // Clear eof flag
    file.seekg(0, ios::beg); // Rewind !
    // Generate random line number
    int randomLine = rand() % count + 1;
    for (int i = 1; i <= randomLine; ++i) 
    {
        getline(file, line);
    }
    // Allocate memory for the name
    char* name = new char[line.length() + 1];
    strcpy(name, line.c_str());
    file.close();
    return name;

 }


 
 


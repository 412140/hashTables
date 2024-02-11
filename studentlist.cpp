#include "studentlist.h"
//includes should carry

//god bless copy and paste because i never want to write "StudentList::" again

StudentList::StudentList() : currStu(0)
{
  srand(time(nullptr));
  for(int x = 0; x < SIZE; ++x) 
  {
    hashTable[x] = nullptr;
  }
}

StudentList::~StudentList()
{
  for(int x=0;x<SIZE; ++x)
    {
      deleteList(hashTable[x]);
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
/* old implementation
 void StudentList::printStu()
 {
  bool isEmpty;
   for(int x=0; x<SIZE; ++x)
   {
     Node* curr = hashTable[x];
     while(curr != nullptr)
     {
      cout << "ID: " << curr->data->getStudentId();
      cout <<", Name: " << curr->data->getFirstName() << " " << curr->data->getLastName();
      cout <<", GPA:"<<curr->data->getGPA() << endl;
      curr = curr->next;
      isEmpty=false;
     }
   }
   if(isEmpty)
   {
    cout << "list empty" << endl;

   }
 }
*/

void StudentList::printStu()
{
  bool isEmpty;
  for(int x =0; x<SIZE;++x)
  {
    Node* curr = hashTable[x];
    while(curr != nullptr)
    {
      char* fN = curr->data->getFirstName();
      char* lN = curr->data->getLastName();
      int id = curr->data->getStudentId();
      float gpa = curr->data->getGPA();

      cout << "ID: " << id << endl;
      cout << ", Name: " << fN;
      cout << lN << endl;
      cout << ", GPA: " <<gpa << endl; 
      curr=curr->next;
      isEmpty=false;
    }


  }
 if(isEmpty){cout << "list empty" << endl;}

}
 void StudentList::delStu(int id)
 {
     for (int x = 0; x < SIZE; ++x) 
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
                currStu--;
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
  if (currStu == 0) 
  {
    cout << "No students in the list." << endl;
     return;
  }
    float totalGPA = 0.0;
    int count = 0;
    for (int z = 0; z < SIZE; ++z) 
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

 void StudentList::insertToList(Node*& head, Student* student)
 {
    Node* newNode = new Node;
    newNode->data = student;
    newNode->next = head;
    head = newNode;
 }

 void StudentList::resizeTable()
 {
   Node* newHashTable[SIZE * 2] = {nullptr};
    for (int i = 0; i < SIZE; ++i) 
    {
        Node* current = hashTable[i];
        while (current != nullptr) 
        {
            int newIndex = hashFxn(current->data->getFirstName());
            // trying to put currents data into the new ht
            Node* newNode = new Node;
            newNode->data = current->data;
            newNode->next = newHashTable[newIndex];
            newHashTable[newIndex] = newNode;
            // Update current to point to the next node
            current = current->next;
        }
    }
    // Free memory of old ht
    for (int i = 0; i < SIZE; ++i) 
    {
        deleteList(hashTable[i]);
    }
    // Update SIZE var
    //SIZE *= 2;
    // Update ht to newHashTable
    for (int i = 0; i < SIZE / 2; ++i) 
    {
        hashTable[i] = nullptr;
    }
    for (int i = 0; i < SIZE; ++i) 
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
  current->next->data = newStu;
  current->next->next = nullptr;

 }
 void StudentList::readFile(const char* fileName, char*** names, int* count)
 {
    ifstream file(fileName);
    if (!file) 
    {
        cerr << "Error: Unable to open file, or my code broke :() " << fileName << endl;
        exit(1);
    }
    *count = 0;
    string line;
    // Count the number of lines in the file
    while (getline(file, line)) 
    {
        (*count)++;
    }
    file.clear(); // Clear eof flag
    file.seekg(0, ios::beg); // Rewind !
    *names = new char*[*count];
    for (int i = 0; i < *count; ++i) 
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


 
 


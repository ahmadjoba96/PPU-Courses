//Course Data Structures - PPU - Dr. Zein Salah
//BY:A7mad_Joba 

#include <iostream>
using namespace std;

class SinglyLinkedList
{
public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  void addAtBeginning(int newValue);
  void addAtEnd(int newValue);
  void readAndCreate();
  void insertIntoSortedList(int newValue);
  void concatenate(SinglyLinkedList &list2); 
  SinglyLinkedList operator+(SinglyLinkedList &list2);
  int getSizeSLL();
  bool isSorted();
  void printOut();
  int getSizeSLLR(); 

private:
  struct Node
  {
    int value;
    Node *next;
  };

  typedef Node *NodePtr;
  NodePtr head;
  int getSizeSLLR(NodePtr node); 
};

SinglyLinkedList::SinglyLinkedList()
{
  head = NULL;
}

SinglyLinkedList::~SinglyLinkedList()
{
  NodePtr curr = head;
  while (curr != NULL)
  {
    NodePtr temp = curr;
    curr = curr->next;
    delete temp;
  }
}

void SinglyLinkedList::addAtBeginning(int newValue)
{
  NodePtr x = new Node;
  x->value = newValue;
  x->next = head;
  head = x;
}

void SinglyLinkedList::addAtEnd(int newValue)
{
  NodePtr x = new Node;
  x->value = newValue;
  x->next = NULL;

  if (head == NULL)
  {
    head = x;
  }
  else
  {
    NodePtr temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = x;
  }
}

void SinglyLinkedList::readAndCreate()
{
  int newValue;
  cin >> newValue;
  while (newValue != 0)
  {
    addAtEnd(newValue);
    cin >> newValue;
  }
}

void SinglyLinkedList::insertIntoSortedList(int newValue)
{
  NodePtr x = new Node;
  x->value = newValue;

  if (head == NULL || newValue <= head->value)
  {
    x->next = head;
    head = x;
  }
  else
  {
    NodePtr temp = head;
    while (temp->next != NULL && temp->next->value <= newValue)
    {
      temp = temp->next;
    }
    x->next = temp->next;
    temp->next = x;
  }
}

void SinglyLinkedList::concatenate(SinglyLinkedList &list2)
{ 
  if (head == NULL)
  {
    head = list2.head;
  }
  else
  {
    NodePtr temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = list2.head;
  }
  list2.head = NULL; 
}

SinglyLinkedList SinglyLinkedList::operator+(SinglyLinkedList &list2)
{
  SinglyLinkedList L3;
  NodePtr temp = head;

  while (temp != NULL)
  {
    L3.addAtEnd(temp->value);
    temp = temp->next;
  }

  temp = list2.head;
  while (temp != NULL)
  {
    L3.addAtEnd(temp->value);
    temp = temp->next;
  }
  return L3;
}

int SinglyLinkedList::getSizeSLL()
{
  int count = 0;
  NodePtr temp = head;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

int SinglyLinkedList::getSizeSLLR()
{
  return getSizeSLLR(head);
}

int SinglyLinkedList::getSizeSLLR(NodePtr node)
{
  if (node == NULL)
    return 0;
  else
    return 1 + getSizeSLLR(node->next);
}

bool SinglyLinkedList::isSorted()
{
  if (head == NULL || head->next == NULL)
  {
    return true;
  }
  NodePtr temp = head;
  while (temp->next != NULL)
  {
    if (temp->value > temp->next->value)
    {
      return false;
    }
    temp = temp->next;
  }
  return true;
}

void SinglyLinkedList::printOut()
{
  NodePtr temp = head;
  while (temp != NULL)
  {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  SinglyLinkedList list1, list2;

  cout << "Enter values for list1 <end with 0>: " << endl;
  list1.readAndCreate();

  cout << "Enter values for list2 <end with 0>: " << endl;
  list2.readAndCreate();

  cout << "List_1:";
  list1.printOut();
  cout << endl;

  cout << "List_2:";
  list2.printOut();
  cout << endl;

  int list1_size = list1.getSizeSLL();
  int list2_size = list2.getSizeSLL();

  SinglyLinkedList list3 = list1 + list2;

  cout << "Concatenated List_1 & List_2 -> List_3: ";
  list3.printOut();

  list1.concatenate(list2); 
  cout << "List_1 After the merger:";
  list1.printOut();
  cout << endl;

  cout << "Size of List_1: " << list1_size << endl;
  cout << "Size of List_2: " << list2_size << endl;
  cout << "Size of List_3: " << list3.getSizeSLL() << endl;

  if (list1.isSorted())
  {
    cout << "The List_1 is sorted." << endl;
  }
  else
  {
    cout << "The List_1 is not sorted." << endl;
  }

  if (list2.isSorted())
  {
    cout << "The List_2 is sorted." << endl;
  }
  else
  {
    cout << "The List_2 is not sorted." << endl;
  }

  if (list3.isSorted())
  {
    cout << "The List_3 is sorted." << endl;
  }
  else
  {
    cout << "The List_3 is not sorted." << endl;
  }

  return 0;
}
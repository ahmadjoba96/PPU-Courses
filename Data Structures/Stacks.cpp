//Course Data Structures - PPU - Dr. Zein Salah
//BY:A7mad_Joba 

#include <bits/stdc++.h>
using namespace std;

template <class elemtype>
class Stack
{
#define MAX 10

public:
  Stack();
  void push(elemtype newval);
  void pop(elemtype &val);
  bool isEmpty();
  bool isFull();
  void clear();
  elemtype peek();
  void print();
  void print_struct();

private:
  int top;
  elemtype data[MAX];
};

template <class elemtype>
Stack<elemtype>::Stack()
{
  top = -1;
}

template <class elemtype>
void Stack<elemtype>::clear()
{
  top = -1;
}

template <class elemtype>
bool Stack<elemtype>::isEmpty()
{
  return top == -1;
}

template <class elemtype>
bool Stack<elemtype>::isFull()
{
  return top == MAX - 1;
}

template <class elemtype>
void Stack<elemtype>::push(elemtype newval)
{
  if (!isFull())
  {
    top++;
    data[top] = newval;
  }
}

template <class elemtype>
void Stack<elemtype>::pop(elemtype &val)
{
  if (!isEmpty())
  {
    val = data[top];
    top--;
  }
}

template <class elemtype>
elemtype Stack<elemtype>::peek()
{
  if (!isEmpty())
  {
    return data[top];
  }
}

template <class elemtype>
void Stack<elemtype>::print()
{
  if (isEmpty())
  {
    cout << "Stack is empty." << endl;
    return;
  }
  for (int i = top; i >= 0; i--)
  {
    cout << data[i] << endl;
  }
}

template <class elemtype>
void Stack<elemtype>::print_struct()
{
  if (isEmpty())
  {
    cout << "Stack is empty." << endl;
    return;
  }
  for (int i = top; i >= 0; i--)
  {
    cout << "Book ID: " << data[i].num_book
         << ", Name: " << data[i].name_book
         << ", Price: $" << data[i].price << endl;
  }
}

struct Book
{
  int num_book;
  string name_book;
  double price;
};

int main()
{
  Stack<Book> bookStack;

  Book book1 = {1, "C++ Programming", 29.99};
  Book book2 = {2, "Data Structures", 39.99};
  Book book3 = {3, "Algorithms", 49.99};

  bookStack.push(book1);
  bookStack.push(book2);
  bookStack.push(book3);

  cout << "Books in stack:" << endl;
  bookStack.print_struct();

  Book poppedBook;
  bookStack.pop(poppedBook);
  cout << "\nPopped book:" << endl;
  cout << "Book ID: " << poppedBook.num_book
       << ", Name: " << poppedBook.name_book
       << ", Price: $" << poppedBook.price << endl;

  cout << "\nBooks in stack after pop:" << endl;
  bookStack.print_struct();

  return 0;
}

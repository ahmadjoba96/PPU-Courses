//Course Data Structures - PPU - Dr. Zein Salah
//BY:A7mad_Joba 

#include <iostream>
using namespace std;

const int MAX = 10;

template <class elementType>
class queue
{
public:
  queue();
  bool isFull();
  void clear();
  bool isEmpty();
  void enqueue(elementType newval);
  void dequeue(elementType &back_val_befor_del);
  elementType peek();
  void print();

private:
  int front;
  int rear;
  elementType data[MAX];
};

template <class elementType>
queue<elementType>::queue()
{
  front = rear = -1;
}

template <class elementType>
void queue<elementType>::clear()
{
  front = rear = -1;
}

template <class elementType>
bool queue<elementType>::isEmpty()
{
  return (front == -1);
}

template <class elementType>
bool queue<elementType>::isFull()
{
  return ((front == 0 && rear == MAX - 1) || rear == front - 1);
}

template <class elementType>
void queue<elementType>::enqueue(elementType newval)
{
  if (!isFull())
  {
    if (isEmpty())
    {
      front = rear = 0;
    }
    else
    {
      rear = (rear + 1) % MAX;
    }
    data[rear] = newval;
  }
  else
  {
    cout << "Queue is full!" << endl;
  }
}

template <class elementType>
void queue<elementType>::dequeue(elementType &back_val_befor_del)
{
  if (!isEmpty())
  {
    back_val_befor_del = data[front];
    if (front == rear)
    {
      front = rear = -1;
    }
    else
    {
      front = (front + 1) % MAX;
    }
  }
  else
  {
    cout << "Queue is empty!" << endl;
  }
}

template <class elementType>
elementType queue<elementType>::peek()
{
  if (!isEmpty())
  {
    return data[front];
  }
  else
  {
    cout << "Queue is empty!" << endl;
    return elementType();
  }
}

template <class elementType>
void queue<elementType>::print()
{
  if (isEmpty())
  {
    cout << "Queue is empty!" << endl;
    return;
  }
  cout << "Queue elements are: ";
  int i = front;
  while (i != rear)
  {
    cout << data[i] << " ";
    i = (i + 1) % MAX;
  }
  cout << data[rear] << endl;
}

int main()
{
  queue<int> q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);

  q.print();

  int val;
  q.dequeue(val);
  std::cout << "Dequeued value: " << val << std::endl; // Use std::cout

  q.print();

  std::cout << "Peek value: " << q.peek() << std::endl; // Use std::cout

  q.clear();
  q.print();

  return 0;
}

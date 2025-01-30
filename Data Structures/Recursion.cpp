//Course Data Structures - PPU - Dr. Zein Salah
//BY:A7mad_Joba 

#include <iostream>
using namespace std;

int sumList(int array[], int size)
{
  if (size == 0)
    return 0;
  else
    return array[size - 1] + sumList(array, size - 1);
}

void printListForward(int array[], int size)
{
  if (size > 0)
  {
    printListForward(array, size - 1);
    cout << array[size - 1] << " ";
  }
}

void printListBackward(int array[], int size)
{
  if (size > 0)
  {
    cout << array[size - 1] << " ";
    printListBackward(array, size - 1);
  }
}

int fibonacci(int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void towerOfHanoi(int n, char s, char i, char d)
{
  if (n > 0)
  {
    towerOfHanoi(n - 1, s, d, i);
    cout << "Move one disk from [" << s << "] to [" << d << "]" << endl;
    towerOfHanoi(n - 1, i, s, d);
  }
}

int main()
{
  int myArray[] = {1, 2, 3, 4, 5};
  int size = sizeof(myArray) / sizeof(myArray[0]);

  cout << "Sum of the list: " << sumList(myArray, size) << endl;

  cout << "List printed forward: ";
  printListForward(myArray, size);
  cout << endl;

  cout << "List printed backward: ";
  printListBackward(myArray, size);
  cout << endl;

  cout << "Fibonacci(5): " << fibonacci(5) << endl;

  cout << "Tower of Hanoi for 3 disks:" << endl;
  towerOfHanoi(3, 'A', 'B', 'C');

  return 0;
}
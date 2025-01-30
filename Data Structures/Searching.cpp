//Course Data Structures - PPU - Dr. Zein Salah
//BY:A7mad_Joba 

#include <iostream>
using namespace std;

int sequentialSearch(int ar[], int size, int key)
{
  for (int i = 0; i < size; i++)
  {
    if (ar[i] == key)
      return i;
  }
  return -1;
}

int binarySearch(int ar[], int size, int key)
{
  int first = 0, last = size - 1;
  while (first <= last)
  {
    int mid = (first + last) / 2;
    if (key == ar[mid])
      return mid;
    else if (key < ar[mid])
      last = mid - 1;
    else
      first = mid + 1;
  }
  return -1;
}

int binarySearch_rec(int ar[], int first, int last, int key)
{
  if (first > last)
    return -1;
  int mid = (first + last) / 2;
  if (key == ar[mid])
    return mid;
  else if (key < ar[mid])
    return binarySearch_rec(ar, first, mid - 1, key);
  else
    return binarySearch_rec(ar, mid + 1, last, key);
}

int main()
{
  int d[] = {15, 24, 33, 42, 51, 60, 69, 70, 77, 86, 95, 104, 133, 152, 177};
  int size = sizeof(d) / sizeof(d[0]);
  int k = 69;

  int seq_result = sequentialSearch(d, size, k);
  cout << "Sequential Search of key " << k << " at index: " << seq_result << endl;

  int bin_result = binarySearch(d, size, k);
  cout << "Binary Search of key " << k << " at index: " << bin_result << endl;

  int rec_bin_result = binarySearch_rec(d, 0, size - 1, k);
  cout << "Recursive Binary Search of key " << k << " at index: " << rec_bin_result << endl;

  return 0;
}

//Course Data Structures - PPU - Dr. Zein Salah
//BY:A7mad_Joba 

#include <iostream>
using namespace std;

void merge(int c[], int start, int mid, int end)
{
  int size_a = mid - start + 1;
  int size_b = end - mid;
  int *a = new int[size_a];
  int *b = new int[size_b];
  for (int i = 0; i < size_a; i++)
    a[i] = c[start + i];
  for (int i = 0; i < size_b; i++)
    b[i] = c[mid + 1 + i];
  int i_a = 0, i_b = 0, i_c = start;
  while (i_a < size_a && i_b < size_b)
  {
    if (a[i_a] < b[i_b])
      c[i_c++] = a[i_a++];
    else
      c[i_c++] = b[i_b++];
  }
  while (i_a < size_a)
    c[i_c++] = a[i_a++];
  while (i_b < size_b)
    c[i_c++] = b[i_b++];
  delete[] a;
  delete[] b;
}

void mergeSort(int arr[], int start, int end)
{
  if (start < end)
  {
    int m = (start + end) / 2;
    mergeSort(arr, start, m);
    mergeSort(arr, m + 1, end);
    merge(arr, start, m, end);
  }
}

void bubbleSort(int a[], int size)
{
  for (int i = 0; i < size - 1; ++i)
    for (int j = size - 1; j > i; --j)
      if (a[j] < a[j - 1])
        swap(a[j], a[j - 1]);
}

int main()
{
  int arr1[] = {5, 3, 8, 4, 2};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  mergeSort(arr1, 0, size1 - 1);
  cout << "Merge Sorted: ";
  for (int i = 0; i < size1; i++)
    cout << arr1[i] << " ";
  cout << endl;

  int arr2[] = {5, 3, 8, 4, 2};
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  bubbleSort(arr2, size2);
  cout << "Bubble Sorted: ";
  for (int i = 0; i < size2; i++)
    cout << arr2[i] << " ";
  cout << endl;
  return 0;
}
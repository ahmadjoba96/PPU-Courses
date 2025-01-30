//Course Data Structures - PPU - Dr. Zein Salah
//BY:A7mad_Joba 

#include <iostream>
#include <vector>
using namespace std;

class Heap
{
  vector<int> heap;

  void heapifyUp(int index)
  {
    while (index > 0 && heap[index] > heap[(index - 1) / 2])
    {
      swap(heap[index], heap[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  void heapifyDown(int index)
  {
    int left = 2 * index + 1, right = 2 * index + 2, largest = index;
    if (left < heap.size() && heap[left] > heap[largest])
      largest = left;
    if (right < heap.size() && heap[right] > heap[largest])
      largest = right;
    if (largest != index)
    {
      swap(heap[index], heap[largest]);
      heapifyDown(largest);
    }
  }

public:
  void insert(int value)
  {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
  }

  int extractMax()
  {
    if (heap.empty())
      return -1;
    int maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return maxVal;
  }

  int getMax()
  {
    return heap.empty() ? -1 : heap[0];
  }

  bool isEmpty()
  {
    return heap.empty();
  }

  void printHeap()
  {
    for (int val : heap)
      cout << val << " ";
    cout << endl;
  }
};

int main()
{
  Heap h;
  h.insert(10);
  h.insert(20);
  h.insert(15);
  h.insert(30);
  h.insert(40);

  h.printHeap();

  cout << "Max: " << h.getMax() << endl;
  cout << "Extracted: " << h.extractMax() << endl;

  h.printHeap();

  return 0;
}

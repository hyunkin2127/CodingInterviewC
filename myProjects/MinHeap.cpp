// ��ó : http://exynoa.tistory.com/249

#include <iostream>
#include <cstdlib>

using namespace std;
 
class Heap
{
public:
  Heap(int Capacity);
  ~Heap();
  void Insert(int data);
  void extractMin();
  void Swap(int* a, int* b);
  void Output();
private:
  int* heap;
  int capacity;
  int usedsize;
};

Heap::Heap(int Capacity) : capacity(Capacity)
{
  heap = new int[Heap::capacity];
  usedsize = 0;
}

Heap::~Heap()
{
  delete[] heap;
}

void Heap::Swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Heap::Insert(int data)
{
  int usedPos = usedsize;
  int parentPos = (int) ((usedPos - 1) / 2);
  if (usedsize == capacity)
  {
    cout << "���� ���� á���ϴ�." << endl;
    return;
  }

  heap[usedsize] = data;
  while (usedPos > 0 && heap[usedPos] < heap[parentPos])
  {
    Swap(&heap[usedPos], &heap[parentPos]);
    usedPos = parentPos;
    parentPos = (int) ((usedPos - 1) / 2);
  }
  usedsize++;
}

void Heap::extractMin()
{
  if (usedsize == 0) return;
  int parentPos = 0, leftPos = 1, rightPos = 2;

  heap[0] = NULL;
  usedsize--;
  Swap(&heap[0], &heap[usedsize]);
  while (true)
  {
    int selectChild = 0;

    if (leftPos >= usedsize) break;
    if (rightPos >= usedsize) selectChild = leftPos;
    else {
      if (heap[leftPos] > heap[rightPos]) selectChild = rightPos;
      else selectChild = leftPos;
    }

    if (heap[selectChild] < heap[parentPos])
    {
      Swap(&heap[parentPos], &heap[selectChild]);
      parentPos = selectChild;
    }
    else break;

    leftPos = 2 * parentPos + 1;
    rightPos = leftPos + 1;
  }
}

void Heap::Output()
{
  for (int i = 0; i < usedsize; i++)
    cout << heap[i] << " ";
  cout << endl;
}

int main()
{ 
  int maxSize = 6;
  int input;
  Heap heap(maxSize);

  for(int i = 0; i < maxSize; i++)
  {
    cin >> input;
    heap.Insert(input);
  }
  heap.Output();

  heap.extractMin();
  heap.Output();
  heap.extractMin();
  heap.Output();
  heap.extractMin();
  heap.Output();

  return 0;
}
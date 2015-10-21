// created by heon - 15.09.09
// C++ 자료구조 구현 
// 3. 큐 
// 일반 큐, 원형큐 둘다 구현해볼것 

//큐 구현에 필요한것들
// enQueue, deQueue
// 1. 배열기반
// 2. 연결리스트 기반

#ifndef __QUEUE_H__
#define __QUEUE_H__


#include "Node.h"

class Queue{
private:
  Node** repository; //Node의 주소를 담을 포인터 배열을 가리키기위한 이중포인터
  int len; // 배열 길이 
  int front; // enQ지점 기억용 
  int rear; // deQ지점 기억용

public:
  Queue(int len);
  //void enQueue(int data);
  //int deQueue(int a);

  void enQueue(Node* data);
  Node* deQueue();
  Node* getNode(int idx) const;
  int searchQueue(int data) const;
  bool isEmpty() const;
  bool isFull() const;
  ~Queue();
};

#endif

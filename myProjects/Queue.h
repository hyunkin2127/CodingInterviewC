// C++ 자료구조 구현 15.09.09
// 3. 큐  -
// 일반 큐, 원형큐 둘다 구현해볼것 

//큐 구현에 필요한것들
// enQueue, deQueue
// 1. 배열기반
// 2. 연결리스트 기반

#ifndef __QUEUE_H__
#define __QUEUE_H__


#include <cstring>
#include <iostream>
//#include "Node.h"
using namespace std;


class Queue{
  private:
    //Node * repository; // 배열 주소 담을 포인터(큐 주소)
    int * repository2;
    int len; // 배열 길이 
    int enqIndex; // enQ지점 기억용 
    int deqIndex; // deQ지점 기억용
  
  public:
    Queue(int len);
    //void enQueue(Node data);
    void enQueue(int data);
    //Node * deQueue();
    int deQueue(int a);
    int searchQueue(int data) const;
    bool isEmpty() const;
    ~Queue();
};

#endif __QUEUE_H__

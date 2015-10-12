// C++ �ڷᱸ�� ���� 15.09.09
// 3. ť  -
// �Ϲ� ť, ����ť �Ѵ� �����غ��� 

//ť ������ �ʿ��Ѱ͵�
// enQueue, deQueue
// 1. �迭���
// 2. ���Ḯ��Ʈ ���

#ifndef __QUEUE_H__
#define __QUEUE_H__


#include <cstring>
#include <iostream>
//#include "Node.h"
using namespace std;


class Queue{
  private:
    //Node * repository; // �迭 �ּ� ���� ������(ť �ּ�)
    int * repository2;
    int len; // �迭 ���� 
    int enqIndex; // enQ���� ���� 
    int deqIndex; // deQ���� ����
  
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

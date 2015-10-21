//created by heon - 15.09.09
//C++로 자료구조 구현하기 
//2. 스택

//스택 구현에 필요한 것들
// push, pop기능, top가리킬 포인터
// 1.배열 기반 
// 2.연결리스트 기반

#ifndef __STACK_H__
#define __STACK_H__

#include "Node.h"


class Stack{
public:
  Node * repository; //
  int len;
  int top;

public:
  Stack(int len);
  ~Stack();
  int getTop() const;
  bool isEmpty() const;
  bool isFull() const;
  void push(Node * data);
  Node * pop();
  Node * peek() const;

};

#endif
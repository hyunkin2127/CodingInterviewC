//C++로 자료구조 구현하기 15.09.09
//2. 스택

//스택 구현에 필요한 것들
// push, pop기능, top가리킬 포인터
// 1.배열 기반 
// 2.연결리스트 기반
 

//1. 스택기반 배열

#include "Stack.h"


StackdqNode::Stack(int len) :len(len), top(0){
  arr= new T[len]; //스택으로 쓸 배열 생성 
}


void StackdqNode::push(T data){ 
  if(top <0 || top >= len) {
    cout<<"Stack overFlow"<<endl;
  }
  else if(top == len-1) {
    cout << "Stack is Full"<< endl;
  }
  else {
    arr[top++] = data;
  }
  return;
}


T StackdqNode::pop(){
   if(top <0 || top >= len) {
    cout<<"Stack overFlow"<<endl;
  }
  else {
    return arr[top--];
  }
}


StackdqNode::~Stack(){
  delete []arr;
}









//created by heon - 15.09.09
//C++로 자료구조 구현하기 
//2. 스택

//스택 구현에 필요한 것들
// push, pop기능, top가리킬 포인터
// 1.배열 기반 
// 2.연결리스트 기반


//1. 스택기반 배열

#include "Stack.h"


Stack::Stack(int len) :len(len), top(-1){
  repository = new Node[len]; //스택으로 쓸 배열 생성 
};

Stack::~Stack(){
  delete []repository;
};

int Stack::getTop() const{
  return top;
};

bool Stack::isEmpty() const{
  return top==-1;
};

bool Stack::isFull() const{
  return top==len-1;
};

void Stack::push(Node * data){ 
  if(isFull()) {
    cout<<"Stack is Full"<<endl;
  }
  else {
    repository[++top] = * data; 
    // top++로 되어있으면 repository[-1]에 데이터를 넣네
    // 그럴꺼면 top을 0으로 바꾸는게 나은데 
    // 문제는 행렬이 0부터 시작하기때문에 데이터가 비었을때를 표시하기 애매함

  }
  return;
};



Node * Stack::pop(){
  if(isEmpty()) {
    cout<<"Stack is Empty"<<endl;
    return NULL;
  }
  else {
    return &repository[top--];
  }
};

Node *  Stack::peek() const {
  if(isEmpty()){
    cout<<"Stack is Empty"<<endl;
    return NULL;
  } 
  else{
    return &repository[top];
  }
};










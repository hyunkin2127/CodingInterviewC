//C++�� �ڷᱸ�� �����ϱ� 15.09.09
//2. ����

//���� ������ �ʿ��� �͵�
// push, pop���, top����ų ������
// 1.�迭 ��� 
// 2.���Ḯ��Ʈ ���
 

//1. ���ñ�� �迭

#include "Stack.h"


StackdqNode::Stack(int len) :len(len), top(0){
  arr= new T[len]; //�������� �� �迭 ���� 
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









//C++로 자료구조 구현하기 15.09.09
//2. 스택

//스택 구현에 필요한 것들
// push, pop기능, top가리킬 포인터
// 1.배열 기반 
// 2.연결리스트 기반
 
#include <iostream>
#include <cstring>
using namespace std;


class Stack{
  private:
    int * arr; //
    int len;
    int top;

  public:
    Stack(int len);
    void push(int data);
    int pop();
    ~Stack();
};
//C++�� �ڷᱸ�� �����ϱ� 15.09.09
//2. ����

//���� ������ �ʿ��� �͵�
// push, pop���, top����ų ������
// 1.�迭 ��� 
// 2.���Ḯ��Ʈ ���
 
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
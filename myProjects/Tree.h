//C++�� �ڷᱸ�� �����ϱ� 15.09.09
//4. Ʈ�� (����Ʈ��)

//Ʈ�� ������ �ʿ��Ѱ� 
// ����, ����, �˻� --> Traverse


//1. �迭���Ʈ��
//2. ���Ḯ��Ʈ ��� Ʈ��

#ifndef __TREE_H__
#define __TREE_H__

#include <iostream>
#include <cstring>
#include "Node.h"
using namespace std;


//���Ḯ��Ʈ ��� 

class Tree{

  private:
    Node * head;
    Node * lastNode;
    int size;
  public:
    Tree();
    Node* getHead();
    void insertNode(int data);
    bool searchNode(Node * head, int data); // ��ȸ����� �־�� �ϹǷ� 
    void deleteNode(int data);
    Node* searchLastNode() const;
    
    int findMax() const;
    ~Tree();
    Node * Treverse();
    // ��ȸ ���� �Լ� ���� ����°� ������ 
    // ��ȸ�� ���θ���� ��ɺ��� �ʿ��� ������ ���޿� ����� 


};

#endif __TREE_H__
﻿//created by heon -  15.09.09
//C++로 자료구조 구현하기
//4. 트리 (이진트리)

//트리 구현에 필요한것 
// 삽입, 삭제, 검색 --> Traverse


//1. 배열기반트리
//2. 연결리스트 기반 트리

#ifndef __TREE_H__
#define __TREE_H__

#include "Node.h"

//연결리스트 기반 

class Tree{

private:
  Node * head;
  Node * lastNode;
  int size;
public:
  Tree();
  ~Tree();
  Node* getHead();
  void insertNode(int data);
  Node searchNode(Node * head, int data); // 순회기능을 넣어야 하므로 
  void deleteNode(int data);
  Node* searchLastNode() const;
  int findMax() const;

  void Treverse(Node * head);
  // 순회 전용 함수 따로 만드는게 나을듯 
  // 순회를 따로만들면 기능별로 필요한 데이터 전달에 어려움 


};

#endif
// C++ 자료구조 구현 15.09.09
// 1. 연결리스트

//연결리스트 구현에 필요한것들
// 1.노드
// 2.연결리스트 클래스 : 삽입, 삭제, 탐색 ++ 노드 추가 위치조정
 
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Node.h"

class LinkedList {

  private:
    Node* head;
    Node* last;
    int len;

  public:
    LinkedList(); // 기본 생성자 
    ~LinkedList();
    bool isEmpty() const;
    int getLen() const;
    void showList() const;
    void insertNode(Node* data); // 삽입.  성공시 true, 실패시 false  or  성공시 삽입된 idx??? 
    Node* searchNode(int data); // 검색1 : 데이터로 검색 // 성공 true,false or 삽입된 idx??
    bool deleteNode(int data); // 삭제1 : 데이터로 삭제 // 성공시 true,false or 삭제된 data?

};

#endif
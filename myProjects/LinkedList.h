// C++ 자료구조 구현 15.09.09
// 1. 연결리스트

//연결리스트 구현에 필요한것들
// 1.노드
// 2.연결리스트 클래스 : 삽입, 삭제, 탐색 ++ 노드 추가 위치조정


#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;


class LinkedList {

  private:
    Node * head;
    Node * last;
    Node * temp;  // 임시저장소로 사용될 포인터
    int len;

  public:
    LinkedList(); // 기본 생성자 
    
    void insertNode(int data); // 삽입.  성공시 true, 실패시 false  or  성공시 삽입된 idx??? 
    int& searchNode(int data); // 검색1 : 데이터로 검색 // 성공 true,false or 삽입된 idx??
    bool deleteNode(int data); // 삭제1 : 데이터로 삭제 // 성공시 true,false or 삭제된 data?

};
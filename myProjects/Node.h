//C++로 자료구조 구현하기 1일차 15.09.09

//연결리스트를 연결하기 위한 노드 
//노드에 필요한것 ??
// 1. 데이터저장공간
// 2. 다음노드와의 연결을 위한 포인터변수

 
#ifndef __NODE_H_
#define __NODE_H_


class Node {

  public:
    int data;
    Node * right;
    Node * left;
    Node * pNode;
  public :
    Node();
    Node(int data):data(data){ 
      // 만약 data가 주소값일 경우 얕은 복사가 일어남
      //--> 만약 int가 주소값이라면 처리를 다르게하는 생성자를 추가해야하나 ?
    }
    int getData() const{
      return data;
    };
    
    void setLeftNode(Node * newNode){
      left = newNode;
    }
    void setRightNode(Node * newNode){
      right = newNode;
    }

};
#endif __NODE_H_


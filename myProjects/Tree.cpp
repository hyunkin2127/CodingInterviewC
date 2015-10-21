//created by heon -  15.09.09
//C++로 자료구조 구현하기
//4. 트리 


//트리 구현에 필요한것 
// 삽입, 삭제, 검색 --> Traverse


//1. 배열기반트리
//2. 연결리스트 기반 트리
#include "Tree.h"
#include "Queue.h"


Tree::Tree():size(0){
  head = NULL;
}


Node* Tree::getHead(){
  return head;
}


void Tree::insertNode(int data){
  //데이터가 하나도 없을때
  //하나이상의 데이터가 존재할때
  //트리의 형식에 따라 저장 방법이 달라질 수 있다
  // 여기서는 기본 이진트리로 설정 

  Node * temp = new Node(data);

  if(head == NULL) { //트리가 비어있을경우
    head = temp;
  }
  else {// 비어있지 않을 경우
    //levelOrder 기법을 이용 해서 자식이 없는 첫번째 노드를 찾아서 할당하면 될듯
    Queue * q = new Queue(20);
    q->enQueue(head);
    while(!q->isEmpty()){
      Node * dqNode = q->deQueue();//노드의 주소값이 반환되는데

      //cout<<"q[0] : "<<q->getNode(0)<<endl;
      //cout<<"q[0] : "<<q->getNode(0)->getData()<<endl;
      //cout<<"dqNo : "<<dqNode<<endl; //이거 잘나오는데
      //cout<<"dqNo : "<<dqNode->getData()<<endl; //이거 잘나오는데
      //cout<<"head : "<<head<<endl; //이거 잘나오는데
      //cout<<"head : "<<head->getData()<<endl; //이거 잘나오는데
      //
      if(dqNode->left != NULL) {
        q->enQueue(dqNode->left);
      }
      else {
        dqNode->left = new Node(data); //temp가 날아가나 ?
        size++;
        break;
      }

      if(dqNode->right != NULL){
        q->enQueue(dqNode->right);
      }
      else {
        dqNode->right = new Node(data);
        size++;
        break;
      }
    }
  }  

  return;
}


//Node* Tree::searchNode(Node * head, int d){
//  //노드 탐색 -- > 순회 기능필요 
//
//  // 검색 함수를 단순히 존재여부 파악용으로 만들것인가 
//  // 주소값 반환 + 위치 (몇번째 노드, 깊이는 얼마인지 등 ) 파악까지  
//  // 이에 따라 구현 방향을 다르게 가야함
//  // ++ 외부변수를 두어서 이를 활용할것인지
//  // 자체적으로 해결할 것인지 
//
//  // 1.존재 파악
//  // --> 반환형 bool이나 int로 변경, 
//  bool left = false;
//  bool right = false;
//
//  left = searchNode(head->left, d);
//  right = searchNode(head->right, d);
//  if(head->data == d || left || right) return true;
//  //자식 노드, 자신중 true가 하나라도 나오면 => 존재하면 
//  return false;
//  // 2.주소 반환
//  // --> 반환경 참조자나 포인터로 변경 
//}


Node* Tree::searchLastNode() const{ //마지막 노드 찾기

  Node * temp;
  Node * last = NULL;
  Queue * q = new Queue(20);
  q->enQueue(head);
  while(!q->isEmpty()){
    temp = q->deQueue();
    if(temp->left == NULL && temp->right == NULL)
      last = temp;
    else {
      if(temp->left) q->enQueue(temp->left);
      if(temp->right) q->enQueue(temp->right);
    } 
  }
  return last;
}



void Tree::deleteNode(int data){

  //노드 삭제를 위해선 
  // 1. 데이터 검색
  // 2. 마지막 노드와의 교체 
  // 3. 마지막 노드 삭제
  //  3-1. 마지막노드 정보를 얻기 위한 방법으로 
  //   1)lastNode 용 포인터사용 : 이방법은 노드 삽입, 삭제마다 lastNode를 재지정해야함
  //   2) 마지막 노드 검색 함수 :levelOrder기법을 이용한 마지막 leaf 노드 탐색

  Node * tempNode = NULL;
  Node * lastNode;
  int tempData;

  Queue * q = new Queue(20);
  q->enQueue(head);
  while(!q->isEmpty()){
    tempNode = q->deQueue();
    if(tempNode->data == data) break;
    else {
      if(tempNode->left) q->enQueue(tempNode->left);
      if(tempNode->right) q->enQueue(tempNode->right);
    }
  }
  lastNode = searchLastNode();
  cout<<"!!!!!!!!!!!!!"<<lastNode->getData()<<endl;
  tempNode->data = lastNode-> data;

  delete lastNode;


}

void Tree::Treverse(Node * head){

  if(head == NULL) return;
  Treverse(head->left);
  cout<<head->getData()<<endl;
  Treverse(head->right);

}
// C++ 자료구조 구현 15.09.09
// 1. 연결리스트

//연결리스트 구현에 필요한것들
// 1.노드
// 2.연결리스트 클래스 : 삽입, 삭제, 탐색 ++ 노드 추가 위치조정


#include "LinkedList.h"


LinkedList::LinkedList():head(NULL),last(NULL), len(0){
  //생성자. 만약 주소값이 들어오면 깊은복사를??
}

LinkedList::~LinkedList(){

  if(isEmpty()) return;

  Node * delNode = head;
  Node * delptr = head->right;

  while(delptr != NULL){
    delete delNode;
    delNode = delptr;
    delptr = delptr->right;
  }

}

bool LinkedList::isEmpty() const{
  return (head == NULL || len <= 0) ;

}

int LinkedList::getLen() const{
  return len;
}

void LinkedList::showList() const{

  if(isEmpty()) {
    cout<<"List is Empty"<<endl;
    return;
  }

  Node * temp = head;

  while(temp!=NULL){
    cout<<temp->getData()<<" ";
    temp = temp->right;
  }
  cout<<endl;
}


void LinkedList::insertNode(Node * data){ //데이터 삽입
  //1) 만약 리스트가 비어있다면
  if(isEmpty()) {
    head = data;
    last = head;
  }
  else{// 2) 비어있지 않다면
    // 직접 찾아가는 방법 
    Node * temp = head; //헤드를 받아서 
    while(temp->right!= NULL){
      temp = temp->right; // 마지막노드를 찾아간다.
    }
    temp->right = data; // 마지막노드를 찾고나면 이어준다

    //마지막 노드를 가리키는 last 포인터를 두어 바로 접근하는방법
    //last->right = data;
    //last = temp->right; // 마지막노드를 가리키는 포인터의 값을 변경한다.
    temp = NULL; //사용하고 난 temp 포인터는 초기화 
  }
  len++;//노드가 추가되었으니 길이 증가시킴
}


Node* LinkedList::searchNode(int data){
  if(isEmpty()){//리스트가 비어있다면 
    cout<<"리스트가 비어있습니다"<<endl;
    return NULL;
  }
  else{ //비어있지 않다면
    Node * temp = head; //헤드를 받아서
    while(temp->right != NULL){ // 노드를 하나씩 찾아가면서
      if(temp->getData() == data) { // 데이터를 확인한다
        return temp ;// 탐색을 중단하고 true 반환하여 찾았음을 알림 
      }
      temp = temp->right;// 아니면 계속 반복 
    }
    return NULL;//while을 빠져나올때까지 못찾았다면 없는것으로 판단
  }
}


bool LinkedList::deleteNode(int data){
  //1.삭제할 값이 없을때
  //2.삭제할 값이 헤드일때
  //3.삭제할 값이 헤드가 아닐때 

  if(isEmpty()){//리스트가 비어있다면 
    cout<<"리스트가 비어있습니다"<<endl;
    //return false;
  }
  else if(head->getData() == data){//만약 삭제할 노드가 헤드라면 
    head = head->right;
    len--;
    return true;
  }

  else{ //비어있지 않고, 헤드가 아니라면 
    Node* temp = head->right; //헤드를 저장한다.(헤드의 다음노드가 Null일수도 있음) 
    Node* prev = head;//삭제시 연결을 위해 이전노드 정보도 받는다.

    while(temp!= NULL){ // 노드를 하나씩 찾아가면서
      if(temp->getData() == data) { // 데이터를 확인한다
        prev->right = temp->right; //이전노드와 다음노드를 이어준다.(temp->right가 Null일수도 있는데???)
        delete temp; // 해당 노드를 삭제한다
        len--;
        return true;;
      }
      prev = temp;
      temp = temp->right;// 아니면 계속 반복
    }
  }
  return false;
}




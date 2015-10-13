// C++ 자료구조 구현 15.09.09
// 1. 연결리스트

//연결리스트 구현에 필요한것들
// 1.노드
// 2.연결리스트 클래스 : 삽입, 삭제, 탐색 ++ 노드 추가 위치조정


#include "LinkedList.h"


LinkedList dqNode::LinkedList() //생성자. 만약 주소값이 들어오면 깊은복사를??
  :head(NULL),last(NULL), temp(NULL){
}

  
void LinkedList dqNode::insertNode(T data){ //데이터 삽입
  //1) 만약 리스트가 비어있다면
  if(head == NULL || len == 0) {
    head = new Node(data);
    last = head;
  }
  else{// 2) 비어있지 않다면
    // 직접 찾아가는 방법 
    temp = head; //헤드를 받아서 
    while(temp != NULL){
      temp = temp->right; // 마지막노드를 찾아간다.
    }
    temp->right = new Node(data); // 마지막노드를 찾고나면 새로운 노드를 생성하여 이어준다

    //마지막 노드를 가리키는 last 포인터를 두어 바로 접근하는방법
    last->right = new Node(data);
    last = temp->right; // 마지막노드를 가리키는 포인터의 값을 변경한다.
    temp = NULL; //사용하고 난 temp 포인터는 초기화 
  }
  len++;//노드가 추가되었으니 길이 증가시킴
}


T& LinkedList dqNode::searchNode(T data){
  if(head == NULL || len == 0){//리스트가 비어있다면 
    cout<<"리스트가 비어있습니다"<<endl;
    return NULL;
  }
  else{ //비어있지 않다면
    temp = head; //헤드를 받아서
    while(temp != NULL){ // 노드를 하나씩 찾아가면서
      if(temp->data == data) { // 데이터를 확인한다
        temp = NULL; //만약 확인되면 temp를 초기화하고
        return data;// 탐색을 중단하고 true 반환하여 찾았음을 알림 
      }
      temp = temp->right;// 아니면 계속 반복 
    }
    return NULL;//while을 빠져나올때까지 못찾았다면 없는것으로 판단
  }
}


bool LinkedList dqNode::deleteNode(T data){
  //1.삭제할 값이 없을때
  //2.삭제할 값이 헤드일때
  //3.삭제할 값이 헤드가 아닐때 

  if(head == NULL || len == 0){//리스트가 비어있다면 
    cout<<"리스트가 비어있습니다"<<endl;
    return false;
  }
  else if(head->data == data){//만약 삭제할 노드가 헤드라면 
    delete head; // 노드를 할당해제하고
    head == NULL;// 헤드 포인터를 초기화
    return true;
  }
  else{ //비어있지 않고, 헤드가 아니라면 
    temp = head->right; //헤드 다음노드를 받고 
    Node * prev = head;//삭제시 연결을 위해 이전노드 정보도 받는다.

    while(temp != NULL){ // 노드를 하나씩 찾아가면서
      if(temp->data == data) { // 데이터를 확인한다
        prev->right = temp->right; //이전노드와 다음노드를 이어주고 
        delete temp; // 해당 노드를 삭제한다
        temp = NULL; //temp를 초기화하고 
        return true;
      }
      prev = temp;
      temp = temp->right;// 아니면 계속 반복
    }
  }
  len--;
}




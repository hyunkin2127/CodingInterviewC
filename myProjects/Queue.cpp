//created by heon - 15.09.09
// C++ 자료구조 구현 
// 3. 큐
// 일반 큐, 원형큐 둘다 구현해볼것 

//큐 구현에 필요한것들
// enQueue, deQueue
// 1. 배열기반
// 2. 연결리스트 기반

#include "Queue.h"


bool Queue::isEmpty() const{
 return front == rear;
}

bool Queue::isFull() const{
  return (rear >= len || front >= len);
}


Queue::Queue(int len):len(len), front(0), rear(0){
  repository = new Node*[len]; //Node의 주소값을 담기위한 포인터 배열
  cout<<"created Q"<<endl;
}


void Queue::enQueue(Node * data){
  if(isFull()) {
    cout<<"Array out of bound en"<<endl;
  }
  else{
    repository[front++] = data;  
    // enQueue 과정에서 전달된 노드의 주소값을 할당하는 것이 아니라 
    // 포인터 변수를 통해서 전달된 노드데이터를 할당하기때문에 
    // 주소값이 달라진다.(head와 repository의 노드 주소를 비교해보면 됨)
    // 그래서 새로운 노드를 생성해서 할당하기보다는 
    // 배열자체를 포인터 배열로 바꿔서 이중포인터를 사용해야함. <-- 이걸로 
  }
}


Node* Queue::deQueue(){
  if( isEmpty() || rear >= front) {
    cout<<"Array out of bound de"<<endl;
  }
  else{
    return *&repository[rear++]; //Node의 주소값을 담고있는 배열요소의 주소를 반환
  }
}


int Queue::searchQueue(int data) const{
  int tempIdx = rear;
  for(int i=0; i<front; i++){
    if(repository[i]->getData() == data){
      return i;
    }
  }
  return -1;//탐색 결과 없을 경우 
}

Node* Queue::getNode(int idx) const{
  return *&repository[idx];

}
// C++ 자료구조 구현 15.09.09
// 3. 큐  -
// 일반 큐, 원형큐 둘다 구현해볼것 

//큐 구현에 필요한것들
// enQueue, deQueue
// 1. 배열기반
// 2. 연결리스트 기반

#include "Queue.h"
 

Queue::Queue(int len):len(len), enqIndex(0), deqIndex(0){
  repository2 = new int[len];
  cout<<"created Q"<<endl;
}


//void Queue::enQueue(Node data){
//  if(deqIndex <0 || enqIndex >= len) {
//    cout<<"Array out of bound"<<endl;
//  }
//  else{
//    repository[enqIndex++] = data;
//  }
//
//  len++;
//
//}

void Queue::enQueue(int data){
  if(deqIndex <0 || enqIndex >= len) {
    cout<<"Array out of bound enq"<<endl;
  }
  else{
    cout<<data<<" inserted q"<<endl;
    repository2[enqIndex++] = data;
  }

}



//Node* Queue::deQueue(){
//  if(deqIndex <0 || deqIndex >= len || deqIndex >= enqIndex) {
//    cout<<"Array out of bound"<<endl;
//  }
//  else{
//    return &repository[deqIndex++];
//  }
//  len--;
//}

int Queue::deQueue(int a){
  if(deqIndex <0 || deqIndex >= len || deqIndex >= enqIndex) {
    cout<<"Array out of bound deq" <<endl;
  }
  else{
    cout<< repository2[deqIndex]<<" deq"<<endl;
    return repository2[deqIndex++];
  }
}


//int Queue::searchQueue(int data) const{
//  int tempIdx = deqIndex;
//  for(int i=0; i<enqIndex; i++){
//    if(repository2[i].getData() == data){
//      return i;
//    }
//  }
//  return -1;//탐색 결과 없을 경우 
//}

bool Queue::isEmpty() const{
  if(enqIndex == deqIndex) return true;
  else return false;

}

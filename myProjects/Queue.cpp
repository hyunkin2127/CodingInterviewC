// C++ �ڷᱸ�� ���� 15.09.09
// 3. ť  -
// �Ϲ� ť, ����ť �Ѵ� �����غ��� 

//ť ������ �ʿ��Ѱ͵�
// enQueue, deQueue
// 1. �迭���
// 2. ���Ḯ��Ʈ ���

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
//  return -1;//Ž�� ��� ���� ��� 
//}

bool Queue::isEmpty() const{
  if(enqIndex == deqIndex) return true;
  else return false;

}

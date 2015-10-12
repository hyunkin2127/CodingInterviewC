//C++�� �ڷᱸ�� �����ϱ� 15.09.09
//4. Ʈ�� 


//Ʈ�� ������ �ʿ��Ѱ� 
// ����, ����, �˻� --> Traverse


//1. �迭���Ʈ��
//2. ���Ḯ��Ʈ ��� Ʈ��
#include "Node.h"
#include "Tree.h"
#include "Queue.h"


Tree::Tree():size(0){
  head = NULL;
}


Node* Tree::getHead(){
  return head;
}


void Tree::insertNode(int d){
  //�����Ͱ� �ϳ��� ������
  //�ϳ��̻��� �����Ͱ� �����Ҷ�
  //Ʈ���� ���Ŀ� ���� ���� ����� �޶��� �� �ִ�
  // ���⼭�� �⺻ ����Ʈ���� ���� 
  Node * temp = new Node(d);

  if(head == NULL) { //Ʈ���� ����������
    head = temp;
  }
  else {// ������� ���� ���
    //levelOrder ����� �̿� �ؼ� �ڽ��� ���� ù��° ��带 ã�Ƽ� �Ҵ��ϸ� �ɵ�
    
    Queue * q = new Queue(size+1);
    q->enQueue(*head);
    while(!q->isEmpty()){
      Node * dqNode = q->deQueue();
     
      if(dqNode->left) 
        q->enQueue(*dqNode->left);
      else {
        dqNode->left = temp;
        break;
      }

      if(dqNode->right) q->deQueue();
      else {
        dqNode->right = temp;
        break;
      }
    }
  }  
  size++;
  return;
}


bool Tree::searchNode(Node * head, int d){
  //��� Ž�� -- > ��ȸ ����ʿ� 

  // �˻� �Լ��� �ܼ��� ���翩�� �ľǿ����� ������ΰ� 
  // �ּҰ� ��ȯ + ��ġ (���° ���, ���̴� ������ �� ) �ľǱ���  
  // �̿� ���� ���� ������ �ٸ��� ������
  // ++ �ܺκ����� �ξ �̸� Ȱ���Ұ�����
  // ��ü������ �ذ��� ������ 

  // 1.���� �ľ�
  // --> ��ȯ�� bool�̳� int�� ����, 
  bool left = false;
  bool right = false;

  left = searchNode(head->left, d);
  right = searchNode(head->right, d);
  if(head->data == d || left || right) return true;
  //�ڽ� ���, �ڽ��� true�� �ϳ��� ������ => �����ϸ� 
  return false;
  // 2.�ּ� ��ȯ
  // --> ��ȯ�� �����ڳ� �����ͷ� ���� 
}


Node* Tree::searchLastNode() const{ //������ ��� ã��
  
  Node * temp;
  Node * last = NULL;
  Queue * q = new Queue(size+1);
  q->enQueue(*head);
  
  while(!q->isEmpty()){
    temp = q->deQueue();
     if(temp->left == NULL && temp->right == NULL)
       last = temp;
     else {
      if(temp->left) q->enQueue(*temp->left);
      if(temp->right) q->enQueue(*temp->right);
     } 
  }
  return last;
}



void Tree::deleteNode(int data){

  //��� ������ ���ؼ� 
  // 1. ������ �˻�
  // 2. ������ ������ ��ü 
  // 3. ������ ��� ����
  //  3-1. ��������� ������ ��� ���� ������� 
  //   1)lastNode �� �����ͻ�� : �̹���� ��� ����, �������� lastNode�� �������ؾ���
  //   2) ������ ��� �˻� �Լ� :levelOrder����� �̿��� ������ leaf ��� Ž��
   
  Node * tempNode = NULL;
  Node * lastNode;
  int tempData;

  Queue * q = new Queue(size+1);
   q->enQueue(*head);
   while(!q->isEmpty()){
     tempNode = q->deQueue();
     if(tempNode->data == data) break;
     else {
      if(tempNode->left) q->enQueue(*tempNode->left);
      if(tempNode->right) q->enQueue(*tempNode->right);
     }
   }
   lastNode = searchLastNode();
   tempNode->data = lastNode -> data;
   delete lastNode;
   

}
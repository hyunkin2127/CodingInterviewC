// C++ �ڷᱸ�� ���� 15.09.09
// 1. ���Ḯ��Ʈ

//���Ḯ��Ʈ ������ �ʿ��Ѱ͵�
// 1.���
// 2.���Ḯ��Ʈ Ŭ���� : ����, ����, Ž�� ++ ��� �߰� ��ġ����


#include "LinkedList.h"


LinkedListdqNode::LinkedList() //������. ���� �ּҰ��� ������ �������縦??
  :head(NULL),last(NULL), temp(NULL){
}

 
void LinkedListdqNode::insertNode(T data){ //������ ����
  //1) ���� ����Ʈ�� ����ִٸ�
  if(head == NULL || len == 0) {
    head = new Node(data);
    last = head;
  }
  else{// 2) ������� �ʴٸ�
    // ���� ã�ư��� ��� 
    temp = head; //��带 �޾Ƽ� 
    while(temp != NULL){
      temp = temp->right; // ��������带 ã�ư���.
    }
    temp->right = new Node(data); // ��������带 ã���� ���ο� ��带 �����Ͽ� �̾��ش�

    //������ ��带 ����Ű�� last �����͸� �ξ� �ٷ� �����ϴ¹��
    last->right = new Node(data);
    last = temp->right; // ��������带 ����Ű�� �������� ���� �����Ѵ�.
    temp = NULL; //����ϰ� �� temp �����ʹ� �ʱ�ȭ 
  }
  len++;//��尡 �߰��Ǿ����� ���� ������Ŵ
}


T& LinkedListdqNode::searchNode(T data){
  if(head == NULL || len == 0){//����Ʈ�� ����ִٸ� 
    cout<<"����Ʈ�� ����ֽ��ϴ�"<<endl;
    return NULL;
  }
  else{ //������� �ʴٸ�
    temp = head; //��带 �޾Ƽ�
    while(temp != NULL){ // ��带 �ϳ��� ã�ư��鼭
      if(temp->data == data) { // �����͸� Ȯ���Ѵ�
        temp = NULL; //���� Ȯ�εǸ� temp�� �ʱ�ȭ�ϰ�
        return data;// Ž���� �ߴ��ϰ� true ��ȯ�Ͽ� ã������ �˸� 
      }
      temp = temp->right;// �ƴϸ� ��� �ݺ� 
    }
    return NULL;//while�� �������ö����� ��ã�Ҵٸ� ���°����� �Ǵ�
  }
}


bool LinkedListdqNode::deleteNode(T data){
  //1.������ ���� ������
  //2.������ ���� ����϶�
  //3.������ ���� ��尡 �ƴҶ� 

  if(head == NULL || len == 0){//����Ʈ�� ����ִٸ� 
    cout<<"����Ʈ�� ����ֽ��ϴ�"<<endl;
    return false;
  }
  else if(head->data == data){//���� ������ ��尡 ����� 
    delete head; // ��带 �Ҵ������ϰ�
    head == NULL;// ��� �����͸� �ʱ�ȭ
    return true;
  }
  else{ //������� �ʰ�, ��尡 �ƴ϶�� 
    temp = head->right; //��� ������带 �ް� 
    Node * prev = head;//������ ������ ���� ������� ������ �޴´�.

    while(temp != NULL){ // ��带 �ϳ��� ã�ư��鼭
      if(temp->data == data) { // �����͸� Ȯ���Ѵ�
        prev->right = temp->right; //�������� ������带 �̾��ְ� 
        delete temp; // �ش� ��带 �����Ѵ�
        temp = NULL; //temp�� �ʱ�ȭ�ϰ� 
        return true;
      }
      prev = temp;
      temp = temp->right;// �ƴϸ� ��� �ݺ�
    }
  }
  len--;
}




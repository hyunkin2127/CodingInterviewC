//C++�� �ڷᱸ�� �����ϱ� 1���� 15.09.09

//���Ḯ��Ʈ�� �����ϱ� ���� ��� 
//��忡 �ʿ��Ѱ� ??
// 1. �������������
// 2. ���������� ������ ���� �����ͺ���


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
      // ���� data�� �ּҰ��� ��� ���� ���簡 �Ͼ
      //--> ���� int�� �ּҰ��̶�� ó���� �ٸ����ϴ� �����ڸ� �߰��ؾ��ϳ� ?
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


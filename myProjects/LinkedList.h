// C++ �ڷᱸ�� ���� 15.09.09
// 1. ���Ḯ��Ʈ

//���Ḯ��Ʈ ������ �ʿ��Ѱ͵�
// 1.���
// 2.���Ḯ��Ʈ Ŭ���� : ����, ����, Ž�� ++ ��� �߰� ��ġ����


#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;


class LinkedList {

  private:
    Node * head;
    Node * last;
    Node * temp;  // �ӽ�����ҷ� ���� ������
    int len;

  public:
    LinkedList(); // �⺻ ������ 
    
    void insertNode(int data); // ����.  ������ true, ���н� false  or  ������ ���Ե� idx??? 
    int& searchNode(int data); // �˻�1 : �����ͷ� �˻� // ���� true,false or ���Ե� idx??
    bool deleteNode(int data); // ����1 : �����ͷ� ���� // ������ true,false or ������ data?

};
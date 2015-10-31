#include <iostream>
using namespace std;

class A {
protected :
  int a;
 
public :
  A():a(10){};

  virtual void showA() const{ 
    // virtual Ű���尡 ������ �ڽ�Ŭ�������� �������̵��� �Լ��� ������
    // �θ�Ŭ������ �ڷ����� ��������� �θ�Ŭ������ �Լ��� ����ȴ�
    // virtual Ű����� �̸� ������ --> �ڹ�ó�� ����ǵ��� �����.
    // (�ڹٴ� �������̵��� �޼��忡 ���ؼ��� �θ�Ŭ���� �ڷ����� ������ �ڽ�Ŭ������ 
    // �޼��尡 ����ǵ��� �Ǿ�����)
    cout<<"a:"<<a<<endl;
  }


};

class B : public A{
private:
  int b;

public:
  B():b(12){};

  void showA() const{ // �θ�Ŭ���� A �� �ִ� showA �Լ� �������̵�
    cout<<"in classB -- a :"<<A::a<<endl;
  }

  void showB() const{
    cout<<"b : "<<b<<endl;
  }

};

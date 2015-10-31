#include <iostream>
using namespace std;

class A {
protected :
  int a;
 
public :
  A():a(10){};

  virtual void showA() const{ 
    // virtual 키워드가 없으면 자식클래스에서 오버라이딩한 함수라 할지라도
    // 부모클래스의 자료형에 담겨있으면 부모클래스의 함수가 실행된다
    // virtual 키워드는 이를 막아줌 --> 자바처럼 실행되도록 만든다.
    // (자바는 오버라이딩한 메서드에 대해서는 부모클래스 자료형에 담기더라도 자식클래스의 
    // 메서드가 수행되도록 되어있음)
    cout<<"a:"<<a<<endl;
  }


};

class B : public A{
private:
  int b;

public:
  B():b(12){};

  void showA() const{ // 부모클래스 A 에 있는 showA 함수 오버라이딩
    cout<<"in classB -- a :"<<A::a<<endl;
  }

  void showB() const{
    cout<<"b : "<<b<<endl;
  }

};

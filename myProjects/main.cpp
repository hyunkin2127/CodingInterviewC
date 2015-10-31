#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"

#include "inheritence.cpp"
#include "stringExamples.cpp"
#include "innerSTL.cpp"

void testLL();
void testStack();
void testQueue();
void testTree();
void testInherit();
int* testETC(int * a);
void testString();
void testSTL();



int main(void){

  //testLL();
  //testStack();
  //testQueue();
  //testTree();
  //testInherit();
  //testString();
  //testSTL();
  int a;
  cout<<sizeof(a)<<endl;

  findDuplicate("HelloHo");

  //int arr[10] = {1,};

  //cout<<arr<<endl;
  //cout<<arr[0]<<endl;

  //int * a = testETC(arr);


  //cout<<a<<endl;
  //cout<<a[0]<<endl;
  //cout<<arr[0]<<endl;


  return 0;
}

void testSTL(){
int arr[10] = { 3, 7, 4, 3, 5, 1, 9, 5, 6, 4 };
cout << count( arr, arr + 10, 5 ) << endl;

}

void testString(){

  string str = "Hello!!!";
  cout<<str<<endl;
  stringTest * st = new stringTest(str);
  cout<<st->getStr()<<endl;

}

int* testETC(int * a){
  // 배열 자체를 전달해도 배열의 주소값이 전달된다.
  // 즉, int*를 전달하는것과 int a[]를 전달하는것이 같음
  a[0] = 0;
  return a;

}

void testInherit(){

  A * aa = new A();
  B * bb = new B();

  aa = new B();
  
  aa->showA();
  bb->showA();

}


void testLL(){
  
  LinkedList * ll = new LinkedList();
  
  ll->insertNode(new Node(1));
  ll->insertNode(new Node(3));
  ll->insertNode(new Node(5));
  ll->insertNode(new Node(7));
  ll->insertNode(new Node(9));
  ll->insertNode(new Node(11));
  ll->insertNode(new Node(13));

  ll->deleteNode(11);

  cout<<ll->searchNode(9)->getData()<<endl;;

  ll->showList();

}

void testStack(){

  Stack * st = new Stack(5);

  st->push(new Node(1));
  st->push(new Node(3));
  st->push(new Node(5));
  st->push(new Node(7));
  st->push(new Node(9));

  cout<<"pop1 : "<<st->pop()->getData()<<endl;
  cout<<"pop2 : "<<st->pop()->getData()<<endl;
  cout<<"pop3 : "<<st->pop()->getData()<<endl;
}

void testQueue(){

  Queue * q = new Queue(10);
  q->enQueue(new Node(1));
  q->enQueue(new Node(2));
  q->enQueue(new Node(3));
  q->enQueue(new Node(4));
  q->enQueue(new Node(5));
  q->enQueue(new Node(6));
  q->enQueue(new Node(7));
  q->enQueue(new Node(8));
  q->enQueue(new Node(9));
  q->enQueue(new Node(10));
  q->enQueue(new Node(11));

  cout<<q->deQueue()->getData()<<endl;
  cout<<q->deQueue()->getData()<<endl;
  cout<<q->deQueue()->getData()<<endl;
  cout<<q->deQueue()->getData()<<endl;
}

void testTree(){
  Tree * t = new Tree();
  t->insertNode(1);

  cout<<"Out : "<<t->getHead()->left<<endl;

  t->insertNode(2);
  t->insertNode(3);
  t->insertNode(4);
  t->insertNode(5);
  t->insertNode(6);
  t->insertNode(7);
  t->insertNode(8);
  t->insertNode(9);
  t->insertNode(10);
  t->insertNode(11);
  t->insertNode(12);
  t->insertNode(13);
  
  //t->Treverse(t->getHead());

  t->Treverse(t->getHead());

}

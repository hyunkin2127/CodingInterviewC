#include "Stack.h"
#include "Queue.h"
#include "Tree.h"


void testStack();
void testQueue();
void testTree();

int main(void){


  /*testStack();
  cout<<"eeeeeeeeeeeeeeeeeeeeeeee"<<endl;
  testQueue();*/
  testTree();
  return 0;
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

  t->deleteNode(1);

    t->Treverse(t->getHead());

}

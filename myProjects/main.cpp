#include "Node.h"
#include "Queue.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Tree.h"

 

int main(void){

  Tree * t = new Tree();
  t->insertNode(1);
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
  cout<<t->searchNode(t->getHead(), 2)<<endl;


}
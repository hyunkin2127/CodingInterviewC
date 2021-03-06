﻿#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  Node* Left;
  Node* Right;
  int Data;
} Node; 

Node* createNode(int data)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->Left = NULL;
  newNode->Right = NULL;
  newNode->Data = data;

  return newNode;
}

Node* searchNode(Node* Tree, int findData)
{
  if (Tree == NULL) return NULL;
  if (Tree->Data == findData)
    return Tree;
  else if (Tree->Data > findData)
    searchNode(Tree->Left, findData);
  else
    searchNode(Tree->Right, findData);
}

void insertNode(Node* Tree, Node* newNode)
{
  if (newNode->Data > Tree->Data)
  {
    if (Tree->Right != NULL) insertNode(Tree->Right, newNode);
    else Tree->Right = newNode;
  }
  else if (newNode->Data < Tree->Data)
  {
    if (Tree->Left != NULL) insertNode(Tree->Left, newNode);
    else Tree->Left = newNode;
  }
}

Node* findMinNode(Node* Tree)
{
  if (Tree == NULL) return NULL;
  if (Tree->Left != NULL) return findMinNode(Tree->Left);
  else return Tree;
}

Node* removeNode(Node* Tree, int data){
  Node* tempNode;

  if (Tree == NULL) printf("해당하는 노드를 찾을 수 없습니다.\n");
  else if (Tree->Data > data) Tree->Left = removeNode(Tree->Left, data);
  else if (Tree->Data < data) Tree->Right = removeNode(Tree->Right, data);
  else{
    if (Tree->Left != NULL && Tree->Right != NULL) { //자식노드가 좌우 둘다 있으면
      tempNode = findMinNode(Tree->Right); //오른쪽자식노드중 최소값을 찾아서 
      Tree->Data = tempNode->Data; // 그값로 삭제할 노드를 대체하고 
      Tree->Right = removeNode(Tree->Right, tempNode->Data); // 최소값을 갖고 있던 노드를 삭제한다.
    }
    else{ //자식노드가 좌, 우 둘중 하나일때
      tempNode = Tree; // 삭제할 노드정보를 저장해두고
      if (Tree->Left == NULL) Tree = Tree->Right; //왼쪽자식노드가 없다면 오른쪽 자식노드를 올려 삭제할 노드를 대체시키고 
      else if (Tree->Right == NULL) Tree = Tree->Left; // 오른쪽자식노드가 없으면 왼쪽자식노드를 올려 삭제할 노드를 대체함
      free(tempNode);//저장해둔 노드(삭제할)를 삭제한다.????????????ㅡㅡ
    }
  }
  return Tree;
}

void printTree(Node* Tree)
{
  if (Tree == NULL) return;
  printTree(Tree->Left);
  printf("%d ", Tree->Data);
  printTree(Tree->Right);
}


int binarySearch(int arr[], int low, int high, int data){

  int mid = (low+high)/2;
  if(data == arr[mid]) return mid;
  else if(data < arr[mid]) return binarySearch(arr, low, mid-1, data);
  else return binarySearch(arr, mid+1, high, data);

}

int main()
{
  Node * Tree = createNode(10);
  Node * findNode;
  int input;

  insertNode(Tree, createNode(5));
  insertNode(Tree, createNode(1));
  insertNode(Tree, createNode(6));
  insertNode(Tree, createNode(17));
  insertNode(Tree, createNode(14));
  insertNode(Tree, createNode(21));

  int arr[11] = {0,1,2,3,4,5,6,7,8,9,10};

  printf( "%d", binarySearch(arr, 0, 10, 10));

  while(1)
  {
    scanf_s("%d", &input);
    findNode = searchNode(Tree, input);

    if (findNode != NULL) 
    {
      printf("해당 노드를 찾았습니다! 노드를 제거합니다. 노드의 위치는 %#x 입니다.\n", findNode);
      removeNode(Tree, input);
      printf("현재 트리 출력: ");
      printTree(Tree); printf("\n");
    }
    else printf("노드를 찾을 수 없었습니다.\n");

  }
  return 0;
}
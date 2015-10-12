//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//
////1.���� �켱 Ž�� 
//
//int n;
//int map[10][10], Visited[10];
//
//void DFS(int u){
//  Visited[u] = 1;
//  for(int i=0; i<10; i++){
//    if(map[u][i] == 1, Visited[i] != 1){// u�� i���� ����Ǿ��ְ�, i�� �̹湮�����϶�
//      cout<<u<<"���� "<<i<<"�� �̵�"<<endl;
//      DFS(i);
//    }
//  }
//};

#include <iostream>
#include <stdio.h>
#include "Queue.h"


int n, minLen; // ���� ũ��� �ּҰ��� ��Ÿ���� ����
int map[10][10]; // ���� ��Ÿ���� 2���� �迭
int Visited[10];

//void DFS(int x, int y, int l)// x ���� ��ǥ, y: ������ǥ, l :��� ����
//{
//  // ���� ������ �������� ���
//  if (x == n - 1 && y == n - 1){
//    // ���� �ּҰ��� l���� ũ��, l�� ���� ���̹Ƿ� l�� �ּҰ����� ����
//    if (minLen > l) minLen = l;
//    return;
//  }
//  map[y][x] = 0; // �湮������ ǥ���ϱ� ���� 0�� ����
//
//  // ���� �̵��� �� �ִٸ� �̵�!
//  if (y > 0 && map[y - 1][x] != 0) DFS(x, y - 1, l + 1);
//  // �Ʒ��� �̵��� �� �ִٸ� �̵�!
//  if (y < n - 1 && map[y + 1][x] != 0) DFS(x, y + 1, l + 1);
//  // �������� �̵��� �� �ִٸ� �̵�!
//  if (x > 0 && map[y][x - 1] != 0) DFS(x - 1, y, l + 1);
//  // ���������� �̵��� �� �ִٸ� �̵�!
//  if (x < n - 1 && map[y][x + 1] != 0) DFS(x + 1, y, l + 1);
//
//  map[y][x] = 1; // ������ �ڸ��� �����·� �ǵ����� ���� 1�� ����
//}

//�迭�� ���� ������ �ʿ���
void findway(int x, int y, int len){

  if(map[y][x] == 1) return;
  if (x == n - 1 && y == n - 1){
    // ���� �ּҰ��� l���� ũ��, l�� ���� ���̹Ƿ� l�� �ּҰ����� ����
    if (minLen > len) minLen = len;
    return;
  }
  map[y][x] = 1; // 1 == �湮�� 
  if( x+1 < n ) findway(x+1, y, len+1);
  if( x-1 > 0 ) findway(x-1, y, len+1);
  if( y+1 < n ) findway(x, y+1, len+1);
  if( y-1 > 0 ) findway(x, y-1, len+1);
  map[y][x] = 0; // 0 == �湮���� ���� 
};


//int main(){
//  int i, j;
//
//  scanf_s("%d", &n);
//  minLen = n * n; // ��� ��θ� ���ƴٳ൵ n * n�̴�, �̸� �ּҰ����� �����صд�
//  for (i = 0; i < n; i++)
//    for (j = 0; j < n; j++)
//      scanf_s("%d", &map[i][j]);
//  findWay(0, 0, 1); // DFS ����!
//
//  printf("�ִ� �Ÿ�: %d\n", minLen);
//
//  return 0;
//}





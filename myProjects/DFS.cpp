//
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//
////1.깊이 우선 탐색 
//
//int n;
//int map[10][10], Visited[10];
//
//void DFS(int u){
//  Visited[u] = 1;
//  for(int i=0; i<10; i++){
//    if(map[u][i] == 1, Visited[i] != 1){// u와 i점이 연결되어있고, i에 미방문상태일때
//      cout<<u<<"에서 "<<i<<"로 이동"<<endl;
//      DFS(i);
//    }
//  }
//};

#include <iostream>
#include <stdio.h>
#include "Queue.h"


int n, minLen; // 맵의 크기와 최소값을 나타내는 변수
int map[10][10]; // 맵을 나타내는 2차원 배열
int Visited[10];

//void DFS(int x, int y, int l)// x 가로 좌표, y: 세로좌표, l :경로 길이
//{
//  // 도착 지점에 도착했을 경우
//  if (x == n - 1 && y == n - 1){
//    // 현재 최소값이 l보다 크면, l이 작은 것이므로 l를 최소값으로 지정
//    if (minLen > l) minLen = l;
//    return;
//  }
//  map[y][x] = 0; // 방문했음을 표시하기 위해 0을 대입
//
//  // 위로 이동할 수 있다면 이동!
//  if (y > 0 && map[y - 1][x] != 0) DFS(x, y - 1, l + 1);
//  // 아래로 이동할 수 있다면 이동!
//  if (y < n - 1 && map[y + 1][x] != 0) DFS(x, y + 1, l + 1);
//  // 왼쪽으로 이동할 수 있다면 이동!
//  if (x > 0 && map[y][x - 1] != 0) DFS(x - 1, y, l + 1);
//  // 오른쪽으로 이동할 수 있다면 이동!
//  if (x < n - 1 && map[y][x + 1] != 0) DFS(x + 1, y, l + 1);
//
//  map[y][x] = 1; // 지나간 자리를 원상태로 되돌리기 위해 1을 대입
//}

//배열의 길이 정보가 필요함
void findway(int x, int y, int len){

  if(map[y][x] == 1) return;
  if (x == n - 1 && y == n - 1){
    // 현재 최소값이 l보다 크면, l이 작은 것이므로 l를 최소값으로 지정
    if (minLen > len) minLen = len;
    return;
  }
  map[y][x] = 1; // 1 == 방문함 
  if( x+1 < n ) findway(x+1, y, len+1);
  if( x-1 > 0 ) findway(x-1, y, len+1);
  if( y+1 < n ) findway(x, y+1, len+1);
  if( y-1 > 0 ) findway(x, y-1, len+1);
  map[y][x] = 0; // 0 == 방문하지 않음 
};


//int main(){
//  int i, j;
//
//  scanf_s("%d", &n);
//  minLen = n * n; // 모든 경로를 돌아다녀도 n * n이니, 이를 최소값으로 지정해둔다
//  for (i = 0; i < n; i++)
//    for (j = 0; j < n; j++)
//      scanf_s("%d", &map[i][j]);
//  findWay(0, 0, 1); // DFS 시작!
//
//  printf("최단 거리: %d\n", minLen);
//
//  return 0;
//}





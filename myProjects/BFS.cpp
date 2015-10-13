#include <stdio.h>
#include <iostream>
#include "Queue.h"

int n, cnt; // 맵의 크기와 카운트 변수
int map[10][10]; // 맵을 나타내는 2차원 배열
int x[100], y[100], l[100]; // 좌표와 길이를 담을 배열


int n, minLen; // 맵의 크기와 최소값을 나타내는 변수
int Visited[10];
 
void BFS(int u){
  cout<<"call bfs"<<endl;
  Visited[u] = 1;
  Queue * q = new Queue(20);
  q->enQueue(u);
  while(!q->isEmpty()){
    cout<<"!!!!!!"<<endl;
    int temp = q->deQueue(0);
    for(int i=1; i<= n; i++){
      if(map[temp][i]==1 && Visited[i] !=1){
        cout<<temp<<"에서 "<<i<<"로 이동"<<endl;
        q->enQueue(i);
      }
    }
  }
}

int n; // 입력되는 정점의 최댓값
int rear, front; // 전단과 후단을 나타내는 변수
int map[30][30], queue[30], visit[30]; // 인접 행렬과 큐와 방문 배열

void bfs2(int v)
{
  int i;

  visit[v] = 1; // 정점 v를 방문했다고 표시
  printf("%d에서 시작\n", v);
  queue[rear++] = v; // 큐에 v를 삽입하고 후단을 1 증가시킴
  while (front < rear) // 후단이 전단과 같거나 작으면 루프 탈출
  {
    // 큐의 첫번째에 있는 데이터를 제외하고 제외된 값을 가져오며, 전단 1 증가
    v = queue[front++];
    for (i = 1; i <= n; i++)
    {
      // 정점 v와 정점 i가 만나고, 정점 i를 방문하지 않은 상태일 경우
      if (map[v][i] == 1 && !visit[i])
      {
        visit[i] = 1; // 정점 i를 방문했다고 표시
        printf("%d에서 %d로 이동\n", v, i);
        queue[rear++] = i; // 큐에 i를 삽입하고 후단을 1 증가시킴
      }
    }
  }
}


//int main()
//{
//  int start; // 시작 정점을 나타내는 변수
//  int v1, v2;
//
//  scanf_s("%d%d", &n, &start);
//
//  while (1)
//  {
//    scanf_s("%d%d", &v1, &v2);
//    if (v1 == 0 && v2 == 0) break;
//    map[v1][v2] = map[v2][v1] = 1;
//  }
//  BFS(start); // BFS 시작!
//  cin>>start;
//  return 0; 
//}


// 큐에 좌표 정보와 길이를 삽입하는 함수
void enqueue(int _x, int _y, int _l)
{
  x[cnt] = _x;
  y[cnt] = _y;
  l[cnt] = _l;
  cnt++;
}

void BFS(int _x, int _y){
  int pos = 0;

  // 시작점의 좌표 정보와 길이를 큐에 삽입한다
  enqueue(_x, _y, 1);
  // 더 이상 방문할 지점이 없거나, 도착 지점에 도착하면 루프를 탈출한다
  while (pos < cnt && (x[pos] != n - 1 || y[pos] != n - 1)){
    
    // 두 번 방문하게 하면 안되므로, 이미 지나갔다는 표시를 해둔다
    map[y[pos]][x[pos]] = 0;

    // 위로 갈 수 있다면, 위 지점의 좌표 정보와 길이를 큐에 삽입한다
    if (y[pos] > 0 && map[y[pos] - 1][x[pos]] == 1)
      enqueue(x[pos], y[pos] - 1, l[pos] + 1);
    // 아래로 갈 수 있다면, 아래 지점의 좌표 정보와 길이를 큐에 삽입한다
    if (y[pos] < n - 1 && map[y[pos] + 1][x[pos]] == 1)
      enqueue(x[pos], y[pos] + 1, l[pos] + 1);
    // 왼쪽으로 갈 수 있다면, 왼쪽 지점의 좌표 정보와 길이를 큐에 삽입한다
    if (x[pos] > 0 && map[y[pos]][x[pos] - 1] == 1)
      enqueue(x[pos] - 1, y[pos], l[pos] + 1);
    // 오른쪽로 갈 수 있다면, 오른쪽 지점의 좌표 정보와 길이를 큐에 삽입한다
    if (x[pos] < n - 1 && map[y[pos]][x[pos] + 1] == 1)
      enqueue(x[pos] + 1, y[pos], l[pos] + 1);

    // 큐의 다음 순서의 지점을 방문한다
    pos++;
  }

  // cnt가 pos보다 크다면, 도착 지점에 무사히 도착한 것이라고 말할 수 있다.
  // 위의 반복문은 도착점에 도착하게 되면 루프를 바로 빠져나오기 때문에,
  // 길이를 삽입하는 큐의 마지막 요소가 최단 경로의 길이라고 할 수 있다.
  if (pos < cnt)
    printf("최단 경로 길이: %d\n", l[pos]);
}

int main()
{
  int i, j;

  scanf("%d", &n);
  min = n * n;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &map[i][j]);
  BFS(0, 0); // BFS 시작!

  return 0;
}
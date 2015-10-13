#include <stdio.h>
#include <iostream>
#include "Queue.h"

int n, cnt; // ���� ũ��� ī��Ʈ ����
int map[10][10]; // ���� ��Ÿ���� 2���� �迭
int x[100], y[100], l[100]; // ��ǥ�� ���̸� ���� �迭


int n, minLen; // ���� ũ��� �ּҰ��� ��Ÿ���� ����
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
        cout<<temp<<"���� "<<i<<"�� �̵�"<<endl;
        q->enQueue(i);
      }
    }
  }
}

int n; // �ԷµǴ� ������ �ִ�
int rear, front; // ���ܰ� �Ĵ��� ��Ÿ���� ����
int map[30][30], queue[30], visit[30]; // ���� ��İ� ť�� �湮 �迭

void bfs2(int v)
{
  int i;

  visit[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��
  printf("%d���� ����\n", v);
  queue[rear++] = v; // ť�� v�� �����ϰ� �Ĵ��� 1 ������Ŵ
  while (front < rear) // �Ĵ��� ���ܰ� ���ų� ������ ���� Ż��
  {
    // ť�� ù��°�� �ִ� �����͸� �����ϰ� ���ܵ� ���� ��������, ���� 1 ����
    v = queue[front++];
    for (i = 1; i <= n; i++)
    {
      // ���� v�� ���� i�� ������, ���� i�� �湮���� ���� ������ ���
      if (map[v][i] == 1 && !visit[i])
      {
        visit[i] = 1; // ���� i�� �湮�ߴٰ� ǥ��
        printf("%d���� %d�� �̵�\n", v, i);
        queue[rear++] = i; // ť�� i�� �����ϰ� �Ĵ��� 1 ������Ŵ
      }
    }
  }
}


//int main()
//{
//  int start; // ���� ������ ��Ÿ���� ����
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
//  BFS(start); // BFS ����!
//  cin>>start;
//  return 0; 
//}


// ť�� ��ǥ ������ ���̸� �����ϴ� �Լ�
void enqueue(int _x, int _y, int _l)
{
  x[cnt] = _x;
  y[cnt] = _y;
  l[cnt] = _l;
  cnt++;
}

void BFS(int _x, int _y){
  int pos = 0;

  // �������� ��ǥ ������ ���̸� ť�� �����Ѵ�
  enqueue(_x, _y, 1);
  // �� �̻� �湮�� ������ ���ų�, ���� ������ �����ϸ� ������ Ż���Ѵ�
  while (pos < cnt && (x[pos] != n - 1 || y[pos] != n - 1)){
    
    // �� �� �湮�ϰ� �ϸ� �ȵǹǷ�, �̹� �������ٴ� ǥ�ø� �صд�
    map[y[pos]][x[pos]] = 0;

    // ���� �� �� �ִٸ�, �� ������ ��ǥ ������ ���̸� ť�� �����Ѵ�
    if (y[pos] > 0 && map[y[pos] - 1][x[pos]] == 1)
      enqueue(x[pos], y[pos] - 1, l[pos] + 1);
    // �Ʒ��� �� �� �ִٸ�, �Ʒ� ������ ��ǥ ������ ���̸� ť�� �����Ѵ�
    if (y[pos] < n - 1 && map[y[pos] + 1][x[pos]] == 1)
      enqueue(x[pos], y[pos] + 1, l[pos] + 1);
    // �������� �� �� �ִٸ�, ���� ������ ��ǥ ������ ���̸� ť�� �����Ѵ�
    if (x[pos] > 0 && map[y[pos]][x[pos] - 1] == 1)
      enqueue(x[pos] - 1, y[pos], l[pos] + 1);
    // �����ʷ� �� �� �ִٸ�, ������ ������ ��ǥ ������ ���̸� ť�� �����Ѵ�
    if (x[pos] < n - 1 && map[y[pos]][x[pos] + 1] == 1)
      enqueue(x[pos] + 1, y[pos], l[pos] + 1);

    // ť�� ���� ������ ������ �湮�Ѵ�
    pos++;
  }

  // cnt�� pos���� ũ�ٸ�, ���� ������ ������ ������ ���̶�� ���� �� �ִ�.
  // ���� �ݺ����� �������� �����ϰ� �Ǹ� ������ �ٷ� ���������� ������,
  // ���̸� �����ϴ� ť�� ������ ��Ұ� �ִ� ����� ���̶�� �� �� �ִ�.
  if (pos < cnt)
    printf("�ִ� ��� ����: %d\n", l[pos]);
}

int main()
{
  int i, j;

  scanf("%d", &n);
  min = n * n;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &map[i][j]);
  BFS(0, 0); // BFS ����!

  return 0;
}
// 출처 : http://d4nnykim.tistory.com/184
// 주석 추가중
#include <iostream>
#include <stack>
#include <tchar.h>

#define NMAX 	100
#define MAX 99999999 // 무한대의 수

using std::stack;
using namespace std;

class Graph
{
private:
  int length[NMAX][NMAX]; // 인접행렬
  int dist[NMAX]; // 최단거리를 저장할 배열
  bool s[NMAX]; // 최단경로를 발견한 정점의 집합
  int path[NMAX]; // 최단경로를 역추적할 배열

public:
  Graph(int size);
  ~Graph();
  void ShortestPath(const int n, const int v);
  void InsertEdge(int u, int v, int w);
  void PrintVertex(const int n, const int v);
  void PrintInfo(const int u, const int n);
  int choose(const int n);
  void Graph::Dijkstra(const int n, const int start);
};

Graph::Graph(int size)
{ 
  // 대각선은 모두 0으로, 나머지는 무한대로 초기화
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
    {
      length[i][j] = MAX;
      if (i == j)	length[i][j] = 0;
    }
}
Graph::~Graph()
{
}

void Graph::InsertEdge(int u, int v, int w) 
{
  length[u][v] = w; // u와 v 사이 간선의 가중치는 w
}

// 인접 행렬 출력
void Graph::PrintVertex(const int n, const int v)
{
  cout << "--------------------------------------------------------------------" << endl;
  cout << "인접 행렬 = " << endl;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout.width(2); 
      // int width(); : 현재 설정된 필드 폭을 리턴
      // int width(int i); 필드 폭을 i 칸으로 설정하고, 이전의 필드 폭을 리턴한다.
      // width() 메서드는 바로 다음에 출력될 항목에만 영향을 미친다. 
      // 그 항목을 지나면 필드 폭은 다시 default 값으로 환원된다.
      
      if(length[i][j] == MAX) cout << "∞" << " ";
      else cout << length[i][j] << " ";
    }
    cout << endl;
  }
  cout << "--------------------------------------------------------------------" << endl;
  cout << "최단 경로" << endl;

  for (int i = 0; i < n; i++)
  {
    if (i == v) // 자기자신으로의 최단 경로는 없음
      continue;

    stack<int> s; // 스택을 선언함

    cout << "정점 " << i << ": ";

    if (dist[i] == MAX) // 도달할 수 없는 정점에 대한 처리
    {
      cout << "도달할 수 없음" << endl;
      continue;
    }

    s.push(MAX); // End of Record

    // 시작 : 각 정점, 종료 : 시작 정점과 같지 않을 때
    // 값이 인덱스가 되는 것을 반복하여 역추적
    for (int j = i; j != v; j = path[j])
      s.push(j); // 스택에 넣음

    cout << v;

    // 스택에서 하나씩 빼면서 EOR까지 출력
    for (int j; (j = s.top()) != MAX; s.pop())
      cout << " -> " << j;

    cout << endl;
  }
}


// dist와 s 배열을 출력
void Graph::PrintInfo(const int u, const int n)
{
  for (int i = 0; i < n; i++)
  {
    cout.width(2);
    if (dist[i] == MAX)
      cout << "∞" << " ";
    else
      cout << dist[i] << " ";
  }

  cout << "  ";

  for (int i = 0; i < n; i++)
  {
    cout.width(2);
    cout << path[i] << " ";
  }

  cout << "    " << u << "     ";

  for (int i = 0; i < n; i++)
  {
    if (s[i])
    {
      cout.width(2);
      cout << i << " ";
    }
  }
  cout << endl;
}

// S에 속하지 않는 정점 중에서 가장 작은 값을 찾아서 반환
int Graph::choose(const int n)
{
  int min = MAX;
  int min_index = 0;

  for (int i = 0; i < n; i++)
  {
    if (!s[i]) // S에 속하지 않는 정점 중에서
    {
      if (min > dist[i])
      {
        min = dist[i];
        min_index = i; // 가장 작은 값을 찾음
      }
    }
  }

  return min_index; // 가장 작은 값을 반환
}

// dist[j],0 <= j < n은 n개의 정점을 가진 방향 그래프 G에서 정점 v로부터 정점 j
// 까지의 최단 경로 길이로 설정됨. 간선의 길이는 length[i][j]로 주어짐.
void Graph::ShortestPath(const int n, const int v)
{
  // 초기화
  for (int i = 0; i < n; i++) 
  {
    // 초기값 - 공집합
    s[i] = false; 
    // 초기값 - 시작정점으로부터 직접 가는 거리
    dist[i] = length[v][i]; 
    path[i] = v; // 초기값 - 시작정점의 값
  }

  s[v] = true; // 자기 자신과의 최단 거리는 이미 정해짐
  dist[v] = 0; // 자기 자신과의 최단 거리는 0

  cout << "--------------------------------------------------------------------" << endl;
  cout << "dist[]=              path[]=            선택정점(u)   s[] =" << endl;
  PrintInfo(0, n);

  // 정점 v로부터 n-1개 경로를 결정
  for (int i = 0; i < n - 2; i++) 
  { 
    int u = choose(n); // dist에서 가장 작은 값을 찾음

    // (여기서 s[w]=FALSE) 
    s[u] = true;

    for (int w = 0; w < n; w++)
    {
      if(!s[w]) // S에 속하지 않는 정점 중에서
      {
        // 다른 정점을 거쳐서 가는 것이 더 비용이 적게 든다면
        if(dist[u] + length[u][w] < dist[w])
        {
          // 그 정점을 택함
          dist[w] = dist[u] + length[u][w];
          // 역추적을 위한 path 배열에 저장
          path[w] = u;
        }
      }
    }

    PrintInfo(u, n);
  }
} 
 
// 한 정점에서 다른 모든 정점으로 가는 최단 경로를 구함
void Graph::Dijkstra(const int n, const int start)
{
  ShortestPath(n, start); // 정점 0에서의 최단 경로
  PrintVertex(n, start); // 출력
}


// _tmain 관련 : http://yokang90.tistory.com/51
int _tmain(int argc, _TCHAR* argv[]) 
{
  int n, edge ;  // n: 정점의 수, e: 간선의 수
  int k, u, v, w; // k: count 변수, u -> v로 가는 간선, w:가중치
  int start; // 시작 정점

  cout << "***************************" << endl;
  cout << "Programmed by Daegyeong Kim" << endl;
  cout << "student # : 32062105" << endl;
  cout << "***************************" << endl;

  cout << "정점의 수와 간선의 수를 입력하시오: ";
  cin >> n >> edge ;

  Graph g(n);

  for (int i = 0; i < edge; i++) 
  {
    k = i + 1;
    cout << k << "번째 간선(u, v, w)를 입력 > ";
    cin >> u >> v >> w ;
    g.InsertEdge(u, v, w);
  }

  cout << "시작 정점 입력 > ";
  cin >> start;

  g.Dijkstra(n, start);

  cout << endl;

  return 0;
}

//</int></stack></iostream>
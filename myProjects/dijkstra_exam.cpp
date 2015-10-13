#include <iostream>
#include <stack>

#define NMAX 	100
#define MAX 99999999 // ���Ѵ��� ��

using std::stack;
using namespace std;

class Graph
{
private:
	int length[NMAX][NMAX]; // �������
	int dist[NMAX]; // �ִܰŸ��� ������ �迭
	bool s[NMAX]; // �ִܰ�θ� �߰��� ������ ����
	int path[NMAX]; // �ִܰ�θ� �������� �迭

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
	// �밢���� ��� 0����, �������� ���Ѵ�� �ʱ�ȭ
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
	length[u][v] = w; // u�� v ���� ������ ����ġ�� w
}

// ���� ��� ���
void Graph::PrintVertex(const int n, const int v)
{
	cout << "--------------------------------------------------------------------" << endl;
	cout << "���� ��� = " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(2);
			if (length[i][j] == MAX)
				cout << "��" << " ";
			else
				cout << length[i][j] << " ";
	
		}
		cout << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;
	cout << "�ִ� ���" << endl;

	for (int i = 0; i < n; i++)
	{
		if (i == v) // �ڱ��ڽ������� �ִ� ��δ� ����
			continue;

		stack<int> s; // ������ ������

		cout << "���� " << i << ": ";

		if (dist[i] == MAX) // ������ �� ���� ������ ���� ó��
		{
			cout << "������ �� ����" << endl;
			continue;
		}

		s.push(MAX); // End of Record

		// ���� : �� ����, ���� : ���� ������ ���� ���� ��
		// ���� �ε����� �Ǵ� ���� �ݺ��Ͽ� ������
		for (int j = i; j != v; j = path[j])
			s.push(j); // ���ÿ� ����

		cout << v;

		// ���ÿ��� �ϳ��� ���鼭 EOR���� ���
		for (int j; (j = s.top()) != MAX; s.pop())
			cout << " -> " << j;

		cout << endl;
	}
}

// dist�� s �迭�� ���
void Graph::PrintInfo(const int u, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout.width(2);
		if (dist[i] == MAX)
			cout << "��" << " ";
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

// S�� ������ �ʴ� ���� �߿��� ���� ���� ���� ã�Ƽ� ��ȯ
int Graph::choose(const int n)
{
	int min = MAX;
	int min_index = 0;

	for (int i = 0; i < n; i++)
	{
		if (!s[i]) // S�� ������ �ʴ� ���� �߿���
		{
			if (min > dist[i])
			{
				min = dist[i];
				min_index = i; // ���� ���� ���� ã��
			}
		}
	}

	return min_index; // ���� ���� ���� ��ȯ
}

// dist[j],0 <= j < n�� n���� ������ ���� ���� �׷��� G���� ���� v�κ��� ���� j
// ������ �ִ� ��� ���̷� ������. ������ ���̴� length[i][j]�� �־���.
void Graph::ShortestPath(const int n, const int v)
{
	// �ʱ�ȭ
	for (int i = 0; i < n; i++) 
	{
		// �ʱⰪ - ������
		s[i] = false; 
		// �ʱⰪ - �����������κ��� ���� ���� �Ÿ�
		dist[i] = length[v][i]; 
		path[i] = v; // �ʱⰪ - ���������� ��
	}
	
	s[v] = true; // �ڱ� �ڽŰ��� �ִ� �Ÿ��� �̹� ������
	dist[v] = 0; // �ڱ� �ڽŰ��� �ִ� �Ÿ��� 0

	cout << "--------------------------------------------------------------------" << endl;
	cout << "dist[]=              path[]=            ��������(u)   s[] =" << endl;
	PrintInfo(0, n);

	// ���� v�κ��� n-1�� ��θ� ����
	for (int i = 0; i < n - 2; i++) 
	{ 
		int u = choose(n); // dist���� ���� ���� ���� ã��
		
		// (���⼭ s[w]=FALSE) 
		s[u] = true;

		for (int w = 0; w < n; w++)
		{
			if(!s[w]) // S�� ������ �ʴ� ���� �߿���
			{
				// �ٸ� ������ ���ļ� ���� ���� �� ����� ���� ��ٸ�
				if(dist[u] + length[u][w] < dist[w])
				{
					// �� ������ ����
					dist[w] = dist[u] + length[u][w];
					// �������� ���� path �迭�� ����
					path[w] = u;
				}
			}
		}

		PrintInfo(u, n);
	}
} 

// �� �������� �ٸ� ��� �������� ���� �ִ� ��θ� ����
void Graph::Dijkstra(const int n, const int start)
{
	ShortestPath(n, start); // ���� 0������ �ִ� ���
	PrintVertex(n, start); // ���
}


int _tmain(int argc, _TCHAR* argv[])
{
	int n, edge ;  // n: ������ ��, e: ������ ��
	int k, u, v, w; // k: count ����, u -> v�� ���� ����, w:����ġ
	int start; // ���� ����
	
	cout << "***************************" << endl;
	cout << "Programmed by Daegyeong Kim" << endl;
	cout << "student # : 32062105" << endl;
	cout << "***************************" << endl;

	cout << "������ ���� ������ ���� �Է��Ͻÿ�: ";
	cin >> n >> edge ;

	Graph g(n);

	for (int i = 0; i < edge; i++) 
	{
		k = i + 1;
		cout << k << "��° ����(u, v, w)�� �Է� > ";
		cin >> u >> v >> w ;
		g.InsertEdge(u, v, w);
	}

	cout << "���� ���� �Է� > ";
	cin >> start;

	g.Dijkstra(n, start);

	cout << endl;

	return 0;
}
</int></stack></iostream>
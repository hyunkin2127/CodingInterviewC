/**
 * 15-10-13
 * created by heon 
 * �ڷᱸ�� graph
 */

enum v{A=1, B=2, C=3, D=4, E=5};

class Graph{

private :
  int * vertex;
  int * edges;
  int vNum;
  int maxEdgeNum;
  int curEdgeNum;

public:
  //���� ����, ���� ���� �Ҵ��ϴ°�
  Graph(int * vertex, int vNum, int edgeNum)
    :vertex(vertex), vNum(vNum), maxEdgeNum(edgeNum), curEdgeNum(0){
    //edges = new int[maxEdgeNum][3];
  }

  void addEdge(int from, int to, int value){
  //new�� �̿��� 2���� �迭�� �����Ҵ��� http://krkr.tistory.com/3 ����
  // int ** arr;
  // arr = new int*[2];
  // for(int i=0; i<3; i++) arr[i] = new int[3]; 
  // int[2][3] �迭�� ����
  } 

  //�ۿ��� ����, ���� ���� �� ���� ���̴°�
  Graph(int vNum, int maxEdgeNum,int * edges)
    :vNum(vNum), edges(edges), maxEdgeNum(maxEdgeNum){
  }

  int getVertexNum() const{
    return vNum;
  }

  int getEdgeNum() const{
    return maxEdgeNum;
  }

  int* getEdges() const{
    return edges;
  }
  



};
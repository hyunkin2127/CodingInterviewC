/**
 * 15-10-13
 * created by heon 
 * 자료구조 graph
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
  //직접 간선, 정점 정보 할당하는것
  Graph(int * vertex, int vNum, int edgeNum)
    :vertex(vertex), vNum(vNum), maxEdgeNum(edgeNum), curEdgeNum(0){
    //edges = new int[maxEdgeNum][3];
  }

  void addEdge(int from, int to, int value){
  //new를 이용한 2차원 배열의 동적할당은 http://krkr.tistory.com/3 참조
  // int ** arr;
  // arr = new int*[2];
  // for(int i=0; i<3; i++) arr[i] = new int[3]; 
  // int[2][3] 배열과 동일
  } 

  //밖에서 간선, 정점 정보 다 만들어서 들이는거
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
// Pesudo 출처 : https://namu.wiki/w/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

/** 
 * 15-10-13
 * created by heon
 * Dijkstra 최단 거리 알고리즘 구현 
 */

// 다익스트라 알고리즘은 다음과 같다. P[A][B]는 A와 B사이의 거리라고 하자.
// 1.출발점으로부터의 최단거리를 저장할 배열 d[v]를 만들고, 출발 노드에는 0을, 
//   출발점을 제외한 다른 노드들에는 매우 큰 값 INF를 채워 넣는다.
//   보통은 최단거리 저장 배열의 이론상 최대값에 맞게 INF를 정한다. 
//   실무에서는 보통 d의 원소 타입에 대한 최대값으로 설정하는 편. [2][3]
// 2.현재노드 A에 출발노드를 저장한다.
// 3.A로부터 갈 수 있는 임의의 노드 B에 대해, 
//   d[A]+P[A][B][4]와 d[B][5]의 값을 비교한다.
// 4.만약 d[A]+P[A][B]가 더 짧다면, d[B]의 값을 이 값으로 갱신시킨다.
// 5.모든 이웃 노드 B에 대해 이 작업을 수행한다.
// 6.A의 상태를 "방문 완료"로 바꾼다. 그러면 이제 더 이상 A는 사용하지 않는다.
// 7.A의 "미방문"상태인 모든 이웃노드들 중, 출발점으로부터의 거리가 
//   제일 짧은 짧은 노드 하나를 골라서 그 노드를 A에 저장한다.
// 8.도착노드가 "방문 완료"상태가 되거나, 혹은 더이상 미방문 상태의 노드를 
//   선택할 수 없을 때까지, 3~7의 과정을 반복한다.
//
// 이 작업을 마친 뒤, 도착노드에 저장된 값이 바로 A로부터의 최단거리이다. 만약 이 값이 INF라면, 중간에 길이 끊긴 것임을 의미한다.

 
//구현중
#include <iostream>
#include <limits> //numeric_limits 를 사용하기 위한 헤더파일
#include "Graph.h"
#include "MinHeap.cpp"

using namespace std;

void Dijkstra(Graph g, int src){

  int vNum = g.getVertexNum();

  int * dist = new int[vNum];
  int * prev = new int[vNum];
  dist[src] = 0;
  
  //방문하지 않은 정점들중 최소비용정점 선택을 위한 최소힙
  Heap * vHeap = new Heap(vNum); 
  
  //힙에 방문하지 않은 정점들 삽입
  int * edges = g.getEdges();
  for(int i=0; i<g.getEdgeNum(); i++){

    if(edges[i] == src){ // src를 출발지로 하는 간선을 찾아서 
      vHeap->Insert(edges[i][1]); //그 목적지가 되는 정점들을 힙에 넣는다. ?? 간선정보는 ?
    }

    vHeap->Insert(i); // src에 연결된 점중 방문하지 않은 정점을 삽입(1 ~ vNum) 처음이니 전부다 넣음
  }

  for(int i=1; i<=vNum; i++){
    if(i != src){
        dist[i] = numeric_limits<int>::max(); //int형 최대값을 반환하는 함수
        prev[i] = 0;
    }
  
  }
  

  
}
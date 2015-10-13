// 출처 : https://namu.wiki/w/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

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





//  function Dijkstra(Graph, source):
// 
//     dist[source] ← 0                           // 소스와 소스 사이의 거리 초기화 --출발지와 출발지의 거리는 당연히 0--
//      prev[source] ← undefined              // 출발지 이전의 최적 경로 추적은 없으므로 Undefined
//
//     create vertex set Q                       //노드들의 집합 Q(방문되지 않은 노드들의 집합) 생성 시작
//
//      for each vertex v in Graph:           // Graph안에 있는 모든 노드들의 초기화
//          if v ≠ source:                          // V 노드가 출발지가 아닐 경우(출발지를 제외한 모든 노드!)
//            dist[v] ← INFINITY             // 소스와 V노드 사이에 알려지지 않은 거리 --얼마나 먼지 모르니까-- = 무한값 ( 모든 노드들을 초기화하는 값)
//            prev[v] ← UNDEFINED       // V노드의  최적경로 추적 초기화
//        add v to Q                            //  Graph에 존재하고 방금 전 초기화된 V 노드를 Q(방문되지 않은 노드들의 집합)에 추가
//
////요약하자면, Graph에 존재하는 모든 노드들을 초기화한 뒤, Q에 추가함.
//      
//      while Q is not empty:                      // Q 집합이 공집합 아닐 경우, 루프 안으로!
//          u ← vertex in Q with min dist[u]    // 첫번째 반복에서는 dist[source]=0이 선택됨. 즉, u=source에서 시작
//          remove u from Q                         // U 노드를 방문한 것이므로 Q집합에서 제거
//          
//          for each neighbor v of u:           // U의 이웃노드들과의 거리 측정
//              alt ← dist[u] + length(u, v)      // 출발지 노드 부터 계산된 U노드까지의 거리 + V에서 U의 이웃노드까지의 거리
//                                                             //= source to U + V to U = source to U
//             if alt < dist[v]:               // 방금 V노드까지 계산한 거리(alt)가 이전에 V노드까지 계산된 거리(dist[v])보다 빠른 또는 가까운 경우
//                 dist[v] ← alt            //  V에 기록된 소스부터 V까지의 최단거리를 방금 V노드까지 계산한 거리로 바꿈
//                  prev[v] ← u            // 제일 가까운 노드는 지금 방문하고 있는 노드(U)로 바꿈
//
//     return dist[], prev[]       //계산된 거리값과 목적지를 리턴
  
}
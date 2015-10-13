//코딩인터뷰 p.180  막대그래프의 최대사각형
#include <iostream>
using namespace std;


//1. 각칸의 높이를 기준으로 최대 넓이를 찾아본다
// 막힐때까지 나아간다 
//2. 이를 배열 처음부터 끝까지 탐색
//3. 다되면 배열을 뒤집어서 재탐색


void findMaxArea(int * arr, int len){

  int i, j, width;
  int tempArea=0;
  int tempIdx=0;
  int tempWidth=0;
  bool isFront;

  //앞쪽에서 부터 찾기 시작
  for(i=0; i< len ; i++){
     j=i+1;
    width=1;
   while(arr[i] <= arr[j] && j < len){
      width++;
      j++;
    }
    if(tempArea <= arr[i] * width){
      tempArea = arr[i] * width;
      tempIdx = i;
      tempWidth = width;
      isFront = true;
    }
  }



  for(i=len-1; i>=0; i--){
    j=i-1;
    width=1;
    while(arr[i] <= arr[j] && j > 0){
      width++;
      j--;
    }
    if(tempArea <= arr[i] * width){
      tempArea = arr[i] * width;
      tempIdx = i;
      tempWidth = width;
      isFront = false;
    }
  }

  cout<<tempArea<<endl;;
  cout<<tempIdx<<endl;
  cout<<tempWidth<<endl;
  cout<<isFront<<endl;
}


int main(void){

  int a;
  int arr[10] = {1,3,2,5,4,2,1,5,6,2};
  findMaxArea(arr, 10);
  cin>>a;
  
}
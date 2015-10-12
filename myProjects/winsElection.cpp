#include <iostream>
using namespace std;

//북마크 C 배열 크기 참고
//CodingInterview p.392 Question3. 선거 당선자 찾기
// --> 중복이 존재하는 배열내에서 가장 많이 중복되는 요소값 찾기
int checkTheElected(int arr[10], int len){
 
  cout<<"in func sizeof (arr) : " <<sizeof (arr)<<endl; //4
  cout<<"in func sizeof arr : " <<sizeof arr<<endl;     //4
  //함수 내에서는 배열의 크기를 알아 낼 방법이 없다.
  //함수의 매개변수에 배열의 크기를 적더라도 아무런 의미가 없음
  //함수의 인자로 배열이 전달되면 배열이 넘어오는것이 아닌 배열의 시작 주소값이 전달

  int * candidateList = new int[len]; // 후보자 목록을 만들고 

  cout<<"sizeof list : " <<sizeof candidateList<<endl;  // 4
  cout<<"sizeof *list : " <<sizeof *candidateList<<endl; // 4

  int maxCnt =0, candidate = 0; 
  for(int i=0; i<len; i++) candidateList[i] = 0; // 후보자 목록 초기화 
  for(int i=0; i<len; i++) {
    candidateList[arr[i]]++; 
    if(candidateList[arr[i]] > maxCnt){
      maxCnt = candidateList[arr[i]];
      candidate = arr[i];
    }  
  }
  return candidate;
}
//dd
void shuffleArray(){
  int len = 18;
  int arr[] = {11, 21 ,31, 41, 51, 61, 71, 81, 91, 12, 22, 32, 42, 52, 62, 72, 82, 92 };
  int temp= 0;

  for(int i=1, j=len/2; i<18; i+=2, j++){ 
    // i : 뒤의 값들과 교체시킬 값의 인덱스, j : 뒤의 값들중 교체될 값의 인덱스
    // 
    temp = arr[j]; //삽입 정렬과 비슷하게 교체될 값을 임시로 저장하고 
    cout<<"j : "<<j<<" // arr[j] : "<< arr[j]<< " // temp : "<< temp<<endl;

    for(int k=j-1; k>=i; k--){ 
      arr[k+1] = arr[k];   // 배열을 한칸씩 뒤로 미루고 
    }
    arr[i] = temp;  // 임시로 저장된 값의 자기자리를 찾아준다.
    cout<<"i : "<<i<<" // arr[i] : "<<arr[i]<<endl;

    cout<<"temp Result: ";
     for(int i=0; i<len ; i++){
       cout<<arr[i]<<" ";
    }
     cout<<endl;
     cout<<"-------------------------"<<endl;

  }

  cout<<"result : ";
  for(int i=0; i<len ; i++){
    cout<<arr[i]<<" ";
  }
  }




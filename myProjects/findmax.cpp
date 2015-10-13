//�ڵ����ͺ� p.180  ����׷����� �ִ�簢��
#include <iostream>
using namespace std;


//1. ��ĭ�� ���̸� �������� �ִ� ���̸� ã�ƺ���
// ���������� ���ư��� 
//2. �̸� �迭 ó������ ������ Ž��
//3. �ٵǸ� �迭�� ����� ��Ž��


void findMaxArea(int * arr, int len){

  int i, j, width;
  int tempArea=0;
  int tempIdx=0;
  int tempWidth=0;
  bool isFront;

  //���ʿ��� ���� ã�� ����
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
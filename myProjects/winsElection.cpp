#include <iostream>
using namespace std;

//�ϸ�ũ C �迭 ũ�� ����
//CodingInterview p.392 Question3. ���� �缱�� ã��
// --> �ߺ��� �����ϴ� �迭������ ���� ���� �ߺ��Ǵ� ��Ұ� ã��
int checkTheElected(int arr[10], int len){
 
  cout<<"in func sizeof (arr) : " <<sizeof (arr)<<endl; //4
  cout<<"in func sizeof arr : " <<sizeof arr<<endl;     //4
  //�Լ� �������� �迭�� ũ�⸦ �˾� �� ����� ����.
  //�Լ��� �Ű������� �迭�� ũ�⸦ ������ �ƹ��� �ǹ̰� ����
  //�Լ��� ���ڷ� �迭�� ���޵Ǹ� �迭�� �Ѿ���°��� �ƴ� �迭�� ���� �ּҰ��� ����

  int * candidateList = new int[len]; // �ĺ��� ����� ����� 

  cout<<"sizeof list : " <<sizeof candidateList<<endl;  // 4
  cout<<"sizeof *list : " <<sizeof *candidateList<<endl; // 4

  int maxCnt =0, candidate = 0; 
  for(int i=0; i<len; i++) candidateList[i] = 0; // �ĺ��� ��� �ʱ�ȭ 
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
    // i : ���� ����� ��ü��ų ���� �ε���, j : ���� ������ ��ü�� ���� �ε���
    // 
    temp = arr[j]; //���� ���İ� ����ϰ� ��ü�� ���� �ӽ÷� �����ϰ� 
    cout<<"j : "<<j<<" // arr[j] : "<< arr[j]<< " // temp : "<< temp<<endl;

    for(int k=j-1; k>=i; k--){ 
      arr[k+1] = arr[k];   // �迭�� ��ĭ�� �ڷ� �̷�� 
    }
    arr[i] = temp;  // �ӽ÷� ����� ���� �ڱ��ڸ��� ã���ش�.
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




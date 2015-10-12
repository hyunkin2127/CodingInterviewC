#include <iostream>
using namespace std;

void sort(int arr[], int temp[], int left, int mid, int right){
	int leftEnd = mid;
	int rightStart = mid+1;
	int i = left; // temp index
	int len = left - right + 1;
	
	while(left <= leftEnd && rightStart <= right){
		if(arr[left]<=arr[rightStart]) temp[i] = arr[left++];
		else temp[i] = arr[rightStart++];
		i++;
	}
	
	while(left <= leftEnd) {
		temp[i] = arr[right++];
		i++;
	}
	while (rightStart <= right){
		temp[i] = arr[left++];
		i++;
	}
	
	for(int j=0; j<len; j++, left++){
		arr[left] = temp[left];
	}
	
}

void merge(int arr[], int temp[], int left,  int right){
	
  if(left<right){
  int	mid = (left + right)/2;
	merge(arr, temp, left, mid);
	merge(arr, temp, mid+1, right);
  sort(arr, temp, left, mid, right);	}
}



int temp[10];
int main() {
	int arr[10] = { 42, 12, 17, 10, 92, 78, 34, 19, 63, 55};
	
	merge(arr, temp, 0, 9);
	
	for(int i=0; i<10; i++)
		cout<<arr[i];
	

	return 0;
}
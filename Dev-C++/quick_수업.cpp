#include<iostream>
#include<cstdio>
using namespace std;

int getLeft(int arr[], int start, int end, int pivot, int result[]){
	//arr의 start부터 end까지 숫자들 중에서
	//pivot보다 작거나 같은 값을 result에 채우는 함수 
	// 또한, 작거나 같은 원소의 개수를 반환.
	int inx =0; 
	for(int i=start; i<=end; i++){
		if(arr[i]<=pivot){
			result[inx++] = arr[i];
		}//if
	}//for-i
	
	return inx;
}//getLeft

int getRight(int arr[], int start, int end, int pivot, int result[]){
	//arr의 start부터 end까지 숫자들 중에서
	//pivot보다 큰 값을 result에 채우는 함수 
	//또한, 큰 값의 원소의 개수를 반환 
	int inx=0;
	for(int i=start; i<=end; i++){
		if(arr[i]>pivot){
			result[inx++]=arr[i];
		}//if
	}//for-i
	
	return inx;	
}//getRight

void quickSort(int arr[], int start, int end){
	//arr을 start부터 end까지 퀵정렬하는 함수
	
	//기저조건 
	if(start >= end)
		return;
		
	int pivot = arr[start];
	int left[100], right[100];
	int leftCnt = getLeft(arr, start+1, end, pivot, left);
	int rightCnt = getRight(arr, start+1, end, pivot, right);
	
	for(int i=0; i<leftCnt; i++){
		arr[start+i] = left[i];
	}
	arr[start+leftCnt] = pivot;
	for(int i=0; i<rightCnt; i++){
		arr[start+leftCnt+1+i]=right[i];
	}
	
	quickSort(arr, start, start + leftCnt-1);
	quickSort(arr, start+leftCnt+1, end);
}//quickSort

int main(){
	
	int n; scanf("%d", &n);
	int arr[100];
		
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
		
	quickSort(arr, 0, n-1);
	
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);	
	
	return 0;
}//main

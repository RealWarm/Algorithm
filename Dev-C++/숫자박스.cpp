#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int binarySearch(int arr[], int start, int end, int value){
	//arr의 s번째 값부터 e번째값 중 value를 찾는 함수 
	//찾으면 인덱스를 반환, 못찾으면 -1을 반환. 
	//그렇지 않다면 -1을 반환하는 함수
	
	if(start>end) {//숫자가 아에 존재하지 않을 경우 >> value도 존재하지 않는다. 
		return -1; 
	}else if(start == end){//숫자가 하나인경우 
		if(arr[start]==value) return start;
		else return -1;
	}else{//숫자가 여러개 있는 경우 
		int mid= (start+end) /2;//중간위치의 인덱스 
		if(arr[mid]==value){
			return mid;		
		}else if(arr[mid] > value){
			return binarySearch(arr, start, mid-1, value);
		}else{
			return binarySearch(arr, mid+1, end, value);
		} 
	}//if-else
	
}//binarySearch

int main(){
	
	int arr[300010]={0};
	int n; cin >> n;		
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	int m; cin >> m;
	
	while(m--){		
		int num; cin >> num;
		int result = binarySearch(arr, 0, n-1, num);
		
		if(result==-1){
			printf("0\n");
		}else{
			printf("1\n");
		}		
	}//while
	
	return 0;
}

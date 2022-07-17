#include<iostream>
#include<cstdio>
using namespace std;

int binarySearch(int arr[], int start, int end, int value){
	//arr의 s번째 값부터 e번째값 중 value를 찾는 함수 
	//찾으면 인덱스를 반환, 못찾으면 -1을 반환. 	
	
	if(start>end) {
		//숫자가 아에 존재하지 않을 경우 >> value도 존재하지 않는다. 
		return -1; 
	}else if(start == end){//숫자가 하나인경우 
		if(arr[start]==value) return start;
		else return -1;
	}else{//숫자가 여러개 있는 경우 
		int mid= (start+end) /2;//중간위치의 인덱스 
		if(arr[mid]==value){
			return mid;		
		}else if(arr[mid] > value) return binarySearch(arr, start, mid-1, value);
		else return binarySearch(arr, mid+1, end, value);
	}//if-else
	
}//binarySearch

int main(){
	
	int arr[100];
	int n, m; cin >> n;
	
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
		
	scanf("%d", &m);
	
	int inx = binarySearch(arr, 0, n-1, m);
	
	if(inx == -1){
		printf("수가 없습니다. \n");
	}else{
		printf("%d 번째에 숫자가 있습니다. \n", inx);
	}
	
	return 0;
}

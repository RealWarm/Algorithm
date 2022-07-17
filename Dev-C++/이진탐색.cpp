#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int binarySearch(int arr[], int myStart, int myEnd, int value) {
	//arr의 start 부터 end까지 중에서
	//value를 찾아 그 위치를 반환하는 함수.
	//만약, 없다면 -1을 반환한다. 
	int start, end, mid;
	
	//start : value보다 항상 작은 값을 가리킴
	//end : value보다 항상 큰값을 가리킴. 
	if(arr[myStart]>value) return -1;
	else if(arr[myStart]==value) return myStart;
		
	if(arr[myEnd]< value) return -1;
	else if(arr[myEnd]==value) return myEnd;
	
	start = myStart;
	end = myEnd;
	while(start + 1 < end) {
//		printf("start : %d       end : %d\n", start, end);
		
		mid =(start+end)/2;
		if(arr[mid] == value) return mid;
		else if(arr[mid]>value) end = mid;
		else if(arr[mid]<value) start = mid;
	}//while	
	
//	printf("start : %d       end : %d\n", start, end);
	
	return  -1; // start와 end가 서로 붙어있다. 
	
}//binarySearch

int main(){
		 
	int n, q; cin >> n >> q;//n:원소의 갯수, q: 질문의 갯수 
	int arr[100010]={0};
	
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);		
	}
//	sort(arr, arr+n);
	
	while(q--){
		int num; scanf("%d", &num);
		
		if(binarySearch(arr, 0, n-1, num) == -1){
			printf("NO\n");
		}else if(binarySearch(arr, 0, n-1, num)!=-1){
			printf("YES\n");
		}
	}//while	
	
	return 0;
}//main

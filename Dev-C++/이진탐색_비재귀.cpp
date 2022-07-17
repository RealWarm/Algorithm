#include<iostream>
/*
5 0
-1 0 1 8 9
*/
using namespace std;

int binarySearch(int arr[], int s, int e, int v){
	// arr 배열의 s부터 e까지에서 v를 찾아 인덱스를 반환한다.
	// 만약 없다면 -1 반환
	// s :: mid보다 작은 값을 가르킨다 || e :: mid보다 큰 값을 가르킨다.
	if(arr[s]>v) return -1;
	else if(arr[s]==v) return s;

	if(arr[e]<v) return -1;
	else if(arr[e]==v) return e;
	printf("while!!!!!!!\n");
	while(s+1<e){ 
		printf("start : %d       end : %d\n", s, e);
		// 비교 할 숫자가 있다면
		int mid=(s+e)/2;
		if(arr[mid]==v) return mid;
		else if(arr[mid]>v) e=mid;
		else if(arr[mid]<v)	s=mid;
		printf("start : %d       end : %d\n", s, e);
	}//while

	return -1;

}//bin

//int binarySearch(int arr[], int myStart, int myEnd, int value) {
//	//arr의 start 부터 end까지 중에서
//	//value를 찾아 그 위치를 반환하는 함수.
//	//만약, 없다면 -1을 반환한다. 
//	int start, end, mid;
//	
//	//start : value보다 항상 작은 값을 가리킴
//	//end : value보다 항상 큰값을 가리킴. 
//	// value : -3
//	// 1 4 7 10 19 22 24 27 39
//	// S                    E
//	// start를 정의 할 수 없는 경우 
//	if(arr[myStart]>value) return -1;
//	else if(arr[myStart]==value) return myStart;
//		
//	// value : 50
//	// 1 4 7 10 19 22 24 27 39
//	// S                    E
//	// end를 정의 할 수 없는 경우 
//	if(arr[myEnd]<value) return -1;
//	else if(arr[myEnd]==value) return myEnd;
//	///////////////////////////////////////////////
//	start = myStart;
//	end = myEnd;
//	while(start + 1 < end) {	// (비교할 숫자가 있다면)
//		printf("start : %d       end : %d\n", start, end);
//		
//		mid =(start+end)/2;
//		if(arr[mid] == value) return mid;
//		else if(arr[mid]>value) end = mid;
//		else if(arr[mid]<value) start = mid;
//	}//while	
//	
//	printf("start : %d       end : %d\n", start, end);
//	
//				// start + 1 = end 
//	return  -1; // start와 end가 서로 붙어있다 >> 찾고자 하는 값이 없구나 
//	
//}//binarySearch


int main(){
	
	int arr[100];
	int n, m; scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++)
		scanf(" %d", &arr[i]);	
	
	int inx = binarySearch(arr, 0, n-1, m);
	
	if(inx == -1){
		printf("수가 없습니다. \n");
	}else{
		printf("%d 번째에 숫자가 있습니다. \n", inx);
	}
	
	return 0;
}


//int binarySearch(int arr[], int mystart, int myend, int val){
//	// arr 배열의 start부터 end까지에서
//	// val 값을 찾아 그 위치를 반환하는 함수 
//	// start : 찾는 값보다 항상 작은 수를 가리킨다.
//	// end : 찾는 값보다 항상 큰수를 가르기키나. 
//	
//	if(arr[mystart]==val) return mystart;
//	else if(arr[mystart]>val) return -1;
//	
//	if(arr[myend] == val) return myend;
//	else if(arr[myend]<val) return -1;
//	
//	int s=mystart;
//	int e=myend;
//	int mid;
//	while(s+1<e){ // (비교할 숫자가 있니?) 
//		mid=(s+e)/2;
//		
//		if(arr[mid]==val) return mid;
//		else if(arr[mid]>val) e=mid;
//		else if(arr[mid]<val) s=mid;
//		
//	}//while
//	
//	return -1;
//}//bins









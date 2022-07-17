#include<iostream>
#include<cstdio> 
using namespace std;

void merging(int arr[], int s1, int e1, int s2, int e2){
	//arr의 s1~e1이 왼쪽절반 , s2~e2가 오른쪽 절반일때,
	// 이 둘을 합쳐서 arr의 s1~e2를 정렬된 결과로 만드는 함수
	 
	int p, q;//p와 q의 현재 최솟값을 가르키는 변수들 
 	int temp[100]; // 합쳐진 결과를 저장하는 임시변수 
 	int temp_inx =0; 
 	p = s1;
 	q = s2;
 	
 	//1 2 4 8   1 2 3 3
 	//  p		q
 	//1 2 2 2 3 3 4 8 	
 	while(p<=e1 && q<=e2){
 		if(arr[p]<= arr[q]){
 			temp[temp_inx++] = arr[p];
			p++; 			
		 }else{
		 	temp[temp_inx++]=arr[q];
		 	q++;
		 }//if-else 		
	 }//while
	
	if(p > e1){ // p가 범위를 나갔다. 
		for(int i=q; i<=e2; i++)
			temp[temp_inx++] = arr[i];
	}else{
		for(int i=p; i<=e1; i++)
			temp[temp_inx++] = arr[i];
	}//if-else
	
	//temp는 완성이 되었으니
	//arr[s1~e2]까지에 temp의 값을 복사 
	for(int i=s1; i<=e2; i++){
		arr[i] = temp[i-s1];
	}
	
}//merging

//arr을 s번째 값부터 e번째 값까지 합병정렬하는 함수 
void mergeSort(int arr[], int start, int end){
	
	if(start>=end){
		return;
	}else{
		//1. 왼쪽 절반을 합병정렬
		//2. 오른쪽 절반을 합병정렬
		//3. 그 둘을 합친다. 
		int mid = (start + end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);		
		// start~mid, mid+1 ~ end 까지 이미 정렬 되어있음
				
		merging(arr, start, mid, mid+1, end);		
	}//if-else 	
}//mergeSort



int main(){
	
	int n; scanf("%d", &n);
	int numbers[100];
	
	for(int i=0; i<n; i++)
		scanf("%d", &numbers[i]);
	
	mergeSort(numbers, 0, n-1);
	
	for(int i=0; i<n; i++)
		printf("%d ", numbers[i]);
	
	return 0;
}//main

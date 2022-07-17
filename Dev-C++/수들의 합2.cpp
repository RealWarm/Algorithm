#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int v1[10010];

 int main(){ 	
 	int n, m; scanf("%d %d", &n, &m); // 원소 갯수, 부분 합 
 	for(int i=0; i<n; i++){
 		scanf(" %d", &v1[i]);
	}//for-i
	////////////////////////////////////////////
	// 1. 시작점(start)과 끝점(end)이 첫번째 원소의 인덱스(0)를 가리키도록 한다.
 	int end=0, psum=0, total=0; // 부분합, 만족하는 갯수
	  	
 	for(int start=0; start<n; start++){
 		while(psum<m && end<n){
 			// 3. 현재 부분 합이 M보다 작거나 같다면, end를 1증가 시킨다. 
 			psum += v1[end];
 			end+=1;
		}//while
 		
 		if(psum==m){
 			// 2. 현재 부분 합이 M과 같다면, 카운트 한다.
 			total+=1;
		 }//if
 		psum-=v1[start];
	}//for-start 		
	printf("%d\n", total);
	/////////////////////////////////////////////// 	
    return 0;
 }//main 
 // 투포인터 알고리즘
 // 1. 시작점(start)과 끝점(end)이 첫번째 원소의 인덱스(0)를 가리키도록 한다.
 // 2. 현재 부분 합이 M과 같다면, 카운트 한다.
 // 3. 현재 부분 합이 M보다 작거나 같다면, end를 1증가 시킨다. 
 // 4. 현재 부분 합이 M보다 이상이거나 OR end=n 이면, start를 1증가 시킨다. 
 // 5. 모든 경우를 확인할 때까지 2번부터 4번까지의 과정을 반복한다. 

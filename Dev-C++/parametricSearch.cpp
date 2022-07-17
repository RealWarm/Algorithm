#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 100000;
int n, s;
int data[MAX];
/*
9 16
2 1 8 1 3 7 2 6 3 
*/
bool check(int interval) {
	// 구간의 길이 interval 만큼 정했을 때, 
	// 그 값이 s 이상인 경우가 있는가? 
	// 있으면 true, 아니면 false	
	int sum=0;
	for(int i=0; i<interval; i++) sum+=data[i];
	
	if(sum>=s) return true;
	
	for(int i=0; i<n-interval; i++){
		sum = sum - data[i] + data[i+interval];
		if(sum>=s) return true;
	}
		
	return false;	
	
}//check

int main(){
	
	scanf("%d %d", &n, &s);
	for(int i=0; i<n; i++) scanf("%d", &data[i]);
	
	int start = 1; //statr는 무조건 X를 가리킴
	int end = n; //end는 무조건 O를 가르킴
	
	if(check(1)){
		cout << 1;
		return 0;
	}
	
	if(!check(n)){
		cout << -1;
		return 0;
	}
	
	while(start+1 < end){
		int mid = (start + end)/2;
		if(check(mid)) end = mid;
		else start = mid;		
	}//while
	
	cout << end;		 
	
	return 0;
}//main

#include<cstdio>
#include<iostream>
using namespace std;

int getSum(int n, int m){
	// n 부터 m 까지의 합을 반환하는 함수
	if(n==m) 
		return n;
	else
		return getSum(n, m-1) + m;
}

int main(){
	
	int n, m; cin >> n >> m;
	
	cout << getSum(n, m);
	
	return 0;
}

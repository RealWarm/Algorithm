#include<iostream>
#include<cstdio>
using namespace std;

void printBinary(int n){
	//n을 이진수로 바꾸어 출력하는 함수.
	if(n==0) printf("0");
	else if(n==1) printf("1");
	else{
		printBinary(n/2);
		printf("%d", n%2);
	}//if-else	
}//printBinary

int main(){
	
	int n; cin>>n;
	printBinary(n);
	
	return 0;
}

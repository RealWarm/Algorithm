#include<iostream>
using namespace std;

int main(){
	int n; cin>>n;
	int space = n-1;
	int cnt=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<space; j++){
			printf(" ");
		}//for-j
		space--;
		for(int k=0; k<cnt; k++){
			printf("*");
		}//for-k
		cnt+=2;
		printf("\n");
	}//for-i
	
	return 0;
}//main

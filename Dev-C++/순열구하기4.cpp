#include<iostream>
#include<cstdio>
using namespace std;
int n, r;
int result[15];

void getResult(int x){
	//result[x]가 정해지고 result[x+1]을 정하는 함수
	 
	if(x>=r){
		for(int i=0; i<r; i++){
			printf("%c", result[i]+'a');
		}//for-i
		printf("\n");
		return;
	}
	
	for(int i=0; i<n; i++){
		result[x]=i;
		int flag = 0;
		for(int a=0; a<=x; a++){
			for(int b=0; b<=x; b++){
				if(a!=b && result[a]==result[b]){
						flag = 1;
				}//if
			}//for-b
		}//for-a
		
		if(flag==0){
			getResult(x+1);
		}
	}//for-i	
	
}//getResult

int main(){
	cin >> n >> r;
	getResult(0);
	return 0;
}//main

#include<iostream>
using namespace std;
int rr[40];
int n, k;

void get(int x, int s){
	
	if(s==k){
		for(int i=0; i<n; i++){
			printf("%d", rr[i]);
		}//for-i
		printf("\n");
		return;
	}//if-2
	
	if(x==n){
//		return;
	}else{
		rr[x]=1;
		get(x+1, s+1);
		rr[x]=0;
		get(x+1, s);
	}//if-1
}//get

int main(){
	scanf("%d %d", &n, &k);
	get(0,0);
	return 0;
}//main

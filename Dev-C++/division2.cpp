#include<iostream>
using namespace std;
int grp[30];
int n, nn;

void get(int x, int sum){
	
	if(sum==n){
		nn++;
		printf("%d", grp[0]);
		for(int i=1; i<x; i++){
			printf("+%d", grp[i]);
		}//for-i
		printf("\n");
		return;
	}//if
	
	for(int i=n-1; i>=1; i--){
		if(sum+i<=n && (x==0 || grp[x-1]>=i)){
			grp[x]=i;
			get(x+1, sum+i);
		}//if
	}//for-i
	
}//get

int main(){
	scanf("%d", &n);
	get(0,0);	
	printf("%d", nn);
	return 0;
}//main

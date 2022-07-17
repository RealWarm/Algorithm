#include<iostream>
using namespace std;
int arr[30];
int n, cnt;

void get(int sum, int x){	
	if(sum==n){
		printf("%d", arr[0]);
		for(int i=1; i<x; i++){
			printf("+%d", arr[i]);
		}//for-i
		printf("\n");
		cnt++;
	}else{
		int num;
		if(x==0) num =n-1;
		else num = n-sum;		
		for(int i=num; i>=1; i--){
			arr[x]=i;
			if(x>0 && arr[x-1]<arr[x]) continue;
			get(sum+i, x+1);
		}//for-i		
	}//if-else	
}//getResult

int main(){
	scanf("%d", &n);
	get(0,0);
	printf("%d",cnt);
	return 0;
}//main

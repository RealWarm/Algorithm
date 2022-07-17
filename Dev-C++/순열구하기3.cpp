#include<iostream>
#include<cstdio>
using namespace std;
int n, r;
int result[100];

void getResult(int x){
	
	if(x>=r){
		int flag=0;
		for(int i=0; i<r; i++){
			for(int j=0; j<r; j++){
				if(i!=j && result[i]==result[j]){
					flag=1;						
				}
			}
		}
		
		if(flag==0){
			for(int i=0; i<r; i++){
				printf("%c", result[i]+'a');
			}
			printf("\n");
		}
	}else if(x < r){
		for(int i=0; i<n; i++){
			result[x]=i;
			getResult(x+1);
		}//for-i		
	}//if-else
	
}//getResult

int main(){
	cin>>n>>r;
	getResult(0);
	return 0;
}//main

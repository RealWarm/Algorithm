#include<iostream>
#include<cstdio>
using namespace std;
char comp[15];
int result[15];
int chck[10];
int k;
int maxbool, minbool; 

void getMax(int x){
			
	if(x>k){
		for(int i=0; i<; i++){
			printf("%d", result[i]);
		}
		printf("\n");
		return;		 
	}else{
		for(int i=9; i<=0; i--){
			if(chck[i]==1) continue;
			result[x]=i;			
			
			int flag=0;
			if(x==0) flag==1;
			else 
			
		}		
	}
	
	
	
	
}//getResult

int main(){
	cin >> k; // 2<=k<=9
	for(int i=0; i<k; i++){
		scanf(" %c", &compaer[i]);
	}//for-i
	getResult(k);
	return 0;
}//main

#include<iostream>
#include<cstring>
using namespace std;
int result[20];
int r, tsum;

int check(){
	// 배열 요소들의 합이 
	// 양의 정수이면 1 반환 
	// 0 이면 0 반환 
	// 음의 정수이면 -1 을 반환 
	int sum=0;
	for(int i=0; i<r; i++){
		sum+=result[i];
	}//for-i
	if(sum==0){
		return 0;
	}else if(sum>0){
		return 1;
	}else if(sum<0){
		return -1;
	}//if-1
}//check

void get(int x){
	if(x>=r){
		for(int i=0; i<r; i++){
			if(result[i]==1){
				printf("(");
			}else if(result[i]==-1){
				printf(")");
			}//if-2
		}//for-i
		printf("\n");
	}else{
		if(check()>0){
			result[x]=-1;
		}else{
			result[x]=1;
		}
		get(x+1);
	}//if-1
}//get

int main(){
	scanf("%d", &r);
	for(int i=r/2; i>=1; i--){
		memset(result, 0, sizeof(result));
		for(int j=0; j<i; j++){
			result[j]=1;
		}
		get(i);
	}//for-i
	return 0;
}//main

#include<iostream> 
#include<cstdio>
using namespace std;
int result[30];
int n, cnt;

void getResult(int sum, int inx){
	
	if(sum==n){
		printf("%d", result[0]);
		for(int i=1; i<inx; i++){
			printf("+%d", result[i]);
		}
		printf("\n");
		cnt++;
	}else{
		int num;
		if(inx==0) num=n-1;
		else num = n-sum;
		
		for(int i=num; i>=1; i--){
			result[inx]=i;
			if(inx>0 && result[inx-1]<result[inx]){
				continue;
			}
			getResult(sum+i, inx+1);
		}//for-i
	}//if-else	
}//getResult

int main(){	
	scanf("%d", &n);
	getResult(0, 0);
	printf("%d", cnt);	
	return 0;
}//main

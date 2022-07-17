#include<iostream>
#include<cstdio>
using namespace std;
int result[30];
int cnt;
int n;
void getResult(int mySum, int index){
	//mySum 현재까지 구한 합.	 
	if(mySum == n){		
		printf("%d", result[0]);
		
		for(int i=1; i<index; i++){
			printf("+%d", result[i]);
		}
		printf("\n");
		cnt++;
	}else{
		int myNumber;		
		if(index == 0) myNumber = n-1;
		else myNumber = n - mySum;
		
		for(int i=myNumber; i>=1; i--){
			result[index] = i;
			if(index > 0 && result[index-1] < result[index]) continue;
			
			getResult(mySum+i, index+1);
		}//for-i
	}//if-else	
}//getResult

int main(){	
	scanf("%d", &n);
	getResult(0, 0);
	printf("%d\n", cnt);	
	return 0;
}//main

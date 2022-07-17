#include<iostream>
using namespace std;
int r, cnt, target, flag;
int result[6];

void show(int x){
	// x+1 번째가 정해지면 x번째가 정해지는 함수
	if(flag==1) return;
		
	if(x>=r){
		cnt++;
		if(cnt==target){
			for(int i=0; i<r; i++){
				printf("%d ", result[i]*90);
			}
			flag=1;
		}		
	}else{
		for(int i=0; i<4; i++){
			result[x]=i;
			show(x+1);
		}//for-i
	}//if-else
	
}//show

int main(){	
	scanf("%d %d", &r, &target);
	show(0);	
	return 0;
}//main

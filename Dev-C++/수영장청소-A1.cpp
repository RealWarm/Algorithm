#include<iostream> 
using namespace std;
int cap[5];
int n, k, ttime; // 수도꼭지 갯수, 회전횟수, 지금까지 회전수 
int flag;

void get(int x){
	if(flag==1) return;
	if(x>=n){
		ttime++;		
		if(k==ttime){
			for(int i=0; i<n; i++){
				printf("%d ", cap[i]*90);
			}//for-i
			flag=1;
		}//if
	}else{
		for(int i=0; i<4; i++){
			cap[x]=i;
			get(x+1);
		}//for-i
	}//if
	
}//get

int main(){
	scanf("%d %d", &n, &k);
	get(0);
	return 0;
}//main

#include<iostream>
using namespace std;
int result[10];
int r=5, cnt=0; 
int d, k;

int check(int ttt[10]){
	//
	int sum=0;
	for(int i=0; i<5; i++){
		sum+=ttt[i];
	}//for-i
	
	if(sum%k==d){
		return 1;//각자릿수의 합을 k로 나눴을때 나머지가 d인 경우 
	}else{
		return 0;
	}//if-1
	
}//check

void get(int x){
	
	if(x>=r){
		if(check(result)==1){
			cnt++;
		}//if-2
	}else{
		for(int i=0; i<=9; i++){
			result[x]=i;
			get(x+1);			
		}//for-i
	}//if-1
	
}//get

int main(){
	scanf("%d %d", &d, &k);// 날짜, 숫자 
	get(0);
	printf("%d", cnt);
	return 0;
}//main 

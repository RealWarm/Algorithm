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
		return 1;//���ڸ����� ���� k�� �������� �������� d�� ��� 
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
	scanf("%d %d", &d, &k);// ��¥, ���� 
	get(0);
	printf("%d", cnt);
	return 0;
}//main 

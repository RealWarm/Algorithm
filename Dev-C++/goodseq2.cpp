#include<iostream> 
using namespace std;
int n, ended;
int result[100];

int check(int x, int len){	
	for(int i=0; i<len; i++){
		if(result[x-i] != result[x-i-len]){
			return 1;
		}
	}//for-i
	return 0;
}//check

void good(int x){//x: index
	
	if(ended==1) return;
	
	if(x>=n){
		for(int i=0; i<n; i++){
			printf("%d", result[i]);
		}//for-i
		ended=1;
		return;
	}
	
	for(int i=1; i<=3; i++){
		result[x]=i;
		int flag=0;
		for(int j=1; j<=(x+1)/2; j++){
			if(!check(x, j)){
				flag=1;
				break;
			}
		}//for-j
		
		if(flag==0){
			good(x+1);
		}//if
	}//for-i
	
	
}//good

int main(){
	cin >> n;
	good(0);
	return 0;
}//main

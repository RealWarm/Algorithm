#include<iostream>
using namespace std;
int result[100];
int n, ch;

int check(int x, int len){	
	for(int i=0; i<len; i++){
		if(result[x-i] != result[x-i-len]){
			return 1;
		}
	}//for-i
	return 0;
}//check

void good(int x){
	
	if(ch==1) return;
		
	if(x>=n){
		for(int i=0; i<n; i++){
			printf("%d", result[i]);
		}//for-i
		printf("\n");
		ch=1;
		return;
	}//if
	
	for(int i=1; i<=3; i++){
		result[x]=i;
		int flag=0;
		for(int k=1; k<=(x+1)/2; k++){
			if(!check(x,k)){					
				flag=1;
				break;
			}//if
		}//for-k
		if(flag==0){
			good(x+1);
		}//if-1
	}//for-i	
}//good

int main(){	
	cin >> n;
	good(0);
	return 0;
}//main

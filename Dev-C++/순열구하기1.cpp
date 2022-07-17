#include<iostream>
using namespace std;
int n, r;
char result[105];
int check[105];

void getResult(int x){	
	if(x>=r){
		printf("%s\n", result);		
	}else{
		for(int i=0; i<n; i++){
			char ch= i+'a';
			if(check[i]==0){
				result[x]=ch;
				check[i]=1;
				getResult(x+1);				
//				result[x]=0;
				check[i]=0;
			}//if			
		}//for-i
	}//if-else	
}//getResult

int main(){	
	cin >> n >> r;
	getResult(0);	
	return 0;
}

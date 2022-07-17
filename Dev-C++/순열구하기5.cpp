#include<iostream> 
using namespace std;
int n, r; //
int check[11];
char result[11];

void get(int x){
	//result[x]를 정하고 result[x+1]을 정한다.
	if(x>=r){
		printf("%s\n", result);
	}else{
		for(int i=0; i<n; i++){
			if(check[i]==0){
				check[i]=1;
				char ch=i+'a';
				result[x]=ch;
				get(x+1);
				check[i]=0;
				result[x]=0;
			}
		}//for-i 
	}//if-else	
}//get

int main(){
	scanf("%d %d", &n, &r);
	get(0);	
	return 0;
}//main

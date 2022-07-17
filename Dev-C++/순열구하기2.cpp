#include<iostream> 
using namespace std;
int result[20];
int check[20];
int n, r;

void get(int x){
	if(x==r){
		for(int i=0; i<r; i++){
			printf("%c", result[i]+'a');
		}
		printf("\n");		
	}else{
		for(int i=0; i<n; i++){
			if(check[i]==0){
				result[x]=i;
				check[i]=1;
				get(x+1);
				check[i]=0;				
			}
		}//for-i
	}//if-1
}//get

int main(){
	scanf("%d %d", &n, &r);
	get(0);
	return 0;
}//main

#include<iostream> 
using namespace std;
int arr[20];
int ch[11];
int n, r;

void get(int x){
	
	if(x>=r){
		for(int i=0; i<r; i++){
			printf("%c", 'a'+arr[i]);
		}//for-i
		printf("\n");
	}else{
		for(int i=0; i<n; i++){
			if(ch[i]==0){
				ch[i]=1;
				arr[x]=i;
				get(x+1);
				ch[i]=0;
			}//if
		}//for-i
	}//if
	
}//get

int main(){
	scanf("%d %d", &n, &r);
	get(0);	
	return 0;
}//main

#include<iostream> 
using namespace std;
int arr[100];
int n, flag;

void get(int x){
	//arr[x]를 정하는 함수
	if(flag==1) return;
	
	if(x>=n){
		for(int i=0; i<n; i++){
			printf("%d", arr[i]);
		}
		flag=1;
		return;
	}else{
		for(int i=1; i<=3; i++){
			arr[x]=i;
			int fg=0;
			for(int k=0; k<)
		}
		
	}//if-else
	 
}//get

int main(){
	scanf("%d", &n);
	get(n);
	return 0;
}//main

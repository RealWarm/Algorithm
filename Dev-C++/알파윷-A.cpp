#include<iostream> 
using namespace std;
int arr[15];
int n, r=10;
int cnt; //내가 지금 몇번째 분배이냐? 
int flag;

void get(int x){
	// 지금 n중 for문의 x번째 for문이다.
	// 따라서 arr[x]의 값을 결정해야할 차례다. 
	if(flag==1) return 0;	
	if(x>=r){
		cnt++;
		if(n==cnt){
			for(int i=0; i<10; i++){
				printf("%d ", arr[i]);
			}//for-i
			printf("\n");
			flag=1;
		}//if
	}else{
		//arr[x]에 값을 채움 
		for(int i=1; i<=4; i++){
			arr[x]=i;
			get(x+1);
		}//for-i
	}//if
}//get

int main(){
	scanf("%d", &n);
	get(0);
	return 0;
}//main

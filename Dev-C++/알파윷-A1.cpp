#include<iostream> 
using namespace std;
int ch[20];
int flag, cnt, target;

void get(int x){
	if(flag==1) return;
	
	if(x>=10){
		cnt++;
		if(cnt==target){
			for(int i=0; i<10; i++){
				printf("%d ", ch[i]);
			}//for-i
			printf("\n");
			flag=1;
		}//if		
	}else{
		for(int i=1; i<5; i++){
			ch[x]=i;
			get(x+1);
		}//for-i
	}//if
}//get

int main(){
	scanf("%d", &target);
	get(0);
	return 0;
}//main

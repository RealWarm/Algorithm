#include<iostream>
#include<cstdio>
using namespace std;
int bl[]={50,100,75,500};

int main(){
	
	int n; scanf("%d", &n);
	
	int cnt = 0;
	int sum = 0;
	int flag = 0; 
	for(int i=1; i<=n; i++){
		int num; cin >> num;
		cnt+=num;
		if(flag==1) break;
		
		if(cnt==5){
			printf("50 ");
		}else if(cnt==10){
			printf("100 ");
		}else if(cnt==15){
			printf("75 ");
		}else if(cnt==20){
			printf("500 ");
		}else if(cnt>=21){
			printf("1000 ");
			flag=1;
		}else{
			printf("%d ", cnt*5);
		}
	}//for-i
	
	return 0;
}//main

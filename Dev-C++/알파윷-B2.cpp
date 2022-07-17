#include<iostream>
using namespace std;
int grp[50]	={0, 5, 10, 15, 20,
			  50, 30, 35, 40, 45,
			  100, 55, 60, 65, 70,
			  75, 80, 85, 90, 95,
			  500, 1000
			  };
int ans[15];
int num, now, flag;


int main(){
	scanf("%d", &num);
	for(int i=0; i<num; i++){
		scanf("%d", &ans[i]);
	}//for-i
	
	for(int i=0; i<num; i++){
		if(flag==1) break;
		now+=ans[i];
		if(now>=21){
			now=21;
			flag=1;
		}
		printf("%d ", grp[now]);
	}
	return 0;
}//main

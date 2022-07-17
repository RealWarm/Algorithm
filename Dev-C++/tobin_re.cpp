#include<iostream>
using namespace std;
int grp[40];
int n, k;

void get(int x, int cnt){
	
	if(x>=n){
		if(cnt==k){
			for(int i=0; i<n; i++){
				printf("%d", grp[i]);
			}//for-i
			printf("\n");
		}//if
	}else{
		if(cnt<k){
			grp[x]=1;
			get(x+1, cnt+1);
			grp[x]=0;
			get(x+1, cnt);
		}else if(cnt>=k){
			grp[x]=0;
			get(x+1, cnt);
		}//if
	}//if
	
}//get

int main(){
	scanf("%d %d", &n, &k);
	get(0, 0);	
	return 0;
}//main

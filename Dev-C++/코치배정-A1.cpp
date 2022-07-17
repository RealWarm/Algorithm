#include<iostream> 
using namespace std;
int n, k, t, flag, cnt, total; 
int result[20];
int ans[20];

void get(int x, int ss){
	
	if(flag==1) return;
	
	if(x==k){
		cnt++;
		if(cnt==t){
			for(int i=0; i<k; i++){
				total+=ans[result[i]];
			}//for-i
			printf("%d\n", total);
			flag=1;
		}//if-2
	}else{
		for(int q=ss; q<n; q++){
			result[x]=q;
			get(x+1, q);
		}//for-q
	}//if-1
	
}//get

int main(){
	scanf("%d %d %d", &n, &k, &t);
	for(int i=0; i<n; i++){
		scanf("%d", &ans[i]);
	}//for-i
	get(0,0);
	return 0;
}//main

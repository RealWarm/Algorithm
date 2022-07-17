#include<iostream>
#include<cstdio>
using namespace std;
int grp[100010];
int n, k; 

void dfs(int x){
	grp[x]=1;
	
	if(x*2<=n && grp[x*2]==0){
		dfs(x*2);
	}
	if(x/3>0 && grp[x/3]==0){
		dfs(x/3);
	}
	
}//dfs

int main(){
	
	scanf("%d %d", &n, &k);
	dfs(k);
	
	int sum=0;
	for(int i=1; i<=n; i++){
//		if(grp[i]==0){
//			sum++;
//		}
		printf("%d ", grp[i]);
	}
	printf("%d",sum);
	
	return 0;
}//main

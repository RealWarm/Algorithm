#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> grp[105];
queue<int> q1;
int wei[105];

void dfs(int x){
	wei[x]=1;	
	for(int i=0; i<grp[x].size(); i++){
		int ntx=grp[x][i];
		if(wei[ntx]==0){
			dfs(ntx);
		}
	}//for-i	
}//dfs

int main(){
	
	int n, m; scanf("%d %d", &n, &m);
	
	while(m--){
		int a, b; scanf("%d %d", &a, &b);
		grp[a].push_back(b);
		grp[b].push_back(a);
	}//while
	dfs(1);
	int sum=0;
	for(int i=0; i<=101; i++){
		sum+=wei[i];
	}
	printf("%d", sum-1);
	
	return 0;
}//main


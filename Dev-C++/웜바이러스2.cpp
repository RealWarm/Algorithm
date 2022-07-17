#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> grp[101];
int wei[101];
queue<int> q1;

void bfs(int x){
	wei[x]=1;
	q1.push(x);
	
	while(!q1.empty()){
		int nwx = q1.front();
		q1.pop(); 
		for(int i=0; i<grp[nwx].size(); i++){
			int ntx = grp[nwx][i];
			if(wei[ntx]==0){
				wei[ntx]=1;
				q1.push(ntx);
			}
		}
	}//while
	
}//bfx

int main(){
	
	int n, m; scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a,b; scanf("%d %d", &a, &b);
		grp[a].push_back(b);
		grp[b].push_back(a);
	}//for-i
	bfs(1);
	int sum=0;
	for(int i=1; i<=n; i++){
		sum+=wei[i];
	}
	printf("%d", sum-1);
	return 0;
}//main

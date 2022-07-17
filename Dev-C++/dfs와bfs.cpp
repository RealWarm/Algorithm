#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> grp[1010];
queue<int> q1;
int wei[1010];

void dfs(int x){
	wei[x]=1;
	printf("%d ", x);
	for(int i=0; i<grp[x].size(); i++){
		int ntx = grp[x][i];
		if(wei[ntx]==0){
			dfs(ntx);
		}//if
	}//for-i	
}//dfs

void bfs(int x){
	wei[x]=1;
	q1.push(x);
	printf("%d ", x);
	
	while(!q1.empty()){
		int nwx = q1.front();
		q1.pop();		
		for(int i=0; i<grp[nwx].size(); i++){
				int ntx = grp[nwx][i];
				if(wei[ntx]==0){
					q1.push(ntx);
					wei[ntx]=1;
					printf("%d ", ntx);
				}
		}//for-i
	}//while	
}//bfs

int main(){
	
	int n, m; scanf("%d %d", &n, &m);
	
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		grp[a].push_back(b);
		grp[b].push_back(a);
	}//for-i
	
	for (int i=0; i<n; i++) {
        sort(grp[i].begin(), grp[i].end());
    }
		
	dfs(0);	
	printf("\n");
	memset(wei, 0, sizeof(wei));	
	bfs(0);
		
	return 0;
}//main

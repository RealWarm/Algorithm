#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n, a, b, m, x, y;
vector<int> grp[110];
int wei[110];

void bfs(int x){
	queue<int> q1;
	q1.push(x);
	wei[x]=0;
	
	while(!q1.empty()){
		int nwx=q1.front();
		q1.pop();
		for(int i=0; i<grp[nwx].size(); i++){
			int ntx=grp[nwx][i];
			if(wei[ntx]==-1){
				wei[ntx]=wei[nwx]+1;
				q1.push(ntx);
			}//if
		}//for-i
	}//while
		
	printf("%d\n", wei[b]);	
	
}//bfs

int main(){
	memset(wei, -1, sizeof(wei));
	scanf("%d %d %d %d", &n, &a, &b, &m);
	for(int i=0; i<m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		grp[x].push_back(y);
		grp[y].push_back(x);
	}//for-m
//	printf("-------------------\n");
//	for(int i=0; i<10; i++){
//		printf("%d\n", par[i]);
//	}//for-m
	
	
	bfs(a);	
	
	return 0;
}//main

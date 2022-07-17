#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> grp[110];
queue<int> q1;
int wei[110];
int n, m;

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
		}//for-i
	}//while
	
}//bfs

int main(){
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a, b; scanf("%d %d", &a, &b);
		grp[a].push_back(b);
		grp[b].push_back(a);
	}//for-i
	
	bfs(1);
	
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(wei[i]==1){
			cnt++;
		}//if
	}//for-i
	
	printf("%d", cnt-1);
	
	return 0;
}//main

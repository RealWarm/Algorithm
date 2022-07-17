#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
vector<int> grp[1010];
queue<pair<int, int> > q1;
int wei[1010];
int n, m;
//void dfs(int x, int c){
//	wei[x]=c;
//	
//	for(int i=0; i<grp[x].size(); i++){
//		int ntx = grp[x][i];
//		if(wei[ntx]==0){
//			dfs(ntx, c*-1);
//		}
//	}//for-i	
//}//bfs

void bfs(int x, int c){
	wei[x]=c;
	q1.push(make_pair(x, c));
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int clr=q1.front().second;
		q1.pop();
		for(int i=0; i<grp[nwx].size(); i++){
			int ntx=grp[nwx][i];
			if(wei[ntx]==0){
				wei[ntx]=clr*-1;
				q1.push(make_pair(ntx, clr*-1));
			}//if
		}//for-i
	}//while	
}//bfs

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a,b; scanf("%d %d", &a, &b);
		grp[a].push_back(b);
		grp[b].push_back(a);
	}	
	for(int i=1; i<=n; i++){
		if(wei[i]==0){
			bfs(i,1);
		}
	}//for-i	
	int flag=1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<grp[i].size(); j++){
			if(wei[i]==wei[grp[i][j]]){
				flag=0;
			}
		}//for-j
	}//for-i	
	printf("%s", flag ? "Yes" : "No");
	return 0;
}//main

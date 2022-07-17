#include<iostream>
#include<queue>
#include<vector>
using namespace std;
queue<int> q1;
vector<int> grp[1010];//간선그래프 원본 
int wei[1010];
int n, m; //정점의 갯수, 간선의 갯수 

void bfs(int x, int c){
	wei[x]=c;
	q1.push(x);
	
	while(!q1.empty()){
		int nwx=q1.front();
		q1.pop();
		for(int i=0; i<grp[nwx].size(); i++){
			int ntx=grp[nwx][i];
			if(grp[ntx]wei[ntx]==0){
				wei[ntx]=c;
				q1.push(ntx);
			}//if
		}//for-i
	}//while
}//bfs

int main(){
	
	scanf("%d %d", &n, &m);	
	for(int i=0; i<m; i++){
		int st, ed; scanf("%d %d", &st, &ed);
		grp[st].push_back(ed);
		grp[ed].push_back(st);
	}//for-i
	/////////////////////////////////////////////////////////////
	int color=0;
	for(int i=1; i<=n; i++){
		if(wei[i]==0){
			bfs(i, ++color);
		}//if
	}//for-i
	printf("%d\n", color);
	if(color==2){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}//main



//for(int i=0; i<n; i++){
//	printf("%d :: ", i);
//	for(int j=0; j<grp[i].size(); j++){
//		printf("%d ", grp[i][j]);
//	}//for-j
//	printf("\n");
//}//for-i

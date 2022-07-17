#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
queue<pair<int, int> > q1;
int grp[30][30];
int wei[30][30];
int cc[30*30];
int dx[]={-1, 1, 0, 0};//»óÇÏÁÂ¿ì 
int dy[]={ 0, 0,-1, 1};
int n;

void bfs(int x, int y, int c){
	wei[x][y]=c;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>n || nty>n) continue;
			if(grp[ntx][nty]==1 && wei[ntx][nty]==0){
				q1.push(make_pair(ntx, nty));
				wei[ntx][nty]=c;
			}//if
		}//for-k
	}//while
}//bfs

void dfs(int x, int y, int c){
	wei[x][y]=c;
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
		if(grp[ntx][nty]==1 && wei[ntx][nty]==0){
			dfs(ntx, nty, c);			
		}//if
	}//for-k
}//dfs

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d", &grp[i][j]);
		}//for-j
	}//for-i
	
	int color=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j]==1 && wei[i][j]==0){
				bfs(i, j, ++color);
			}//if
		}//for-j
	}//for-i
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", wei[i][j]);
		}//for-j
		printf("\n");
	}//for-i
	
//	printf("%d\n", color);	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			cc[wei[i][j]]++;
//		}//for-j
//	}//for-i
//	sort(cc+1, cc+color+1);
//	for(int i=1; i<=color; i++){
//		printf("%d\n", cc[i]);
//	}
	
	return 0;
}//main

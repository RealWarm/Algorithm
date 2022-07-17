#include <iostream>
#include <cstring>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int grp[510][510];
int wei[510][510];
int n, m; // 세로, 가로 
// dp[y][x] = (y, x) 지점일 때 존재하는 경로의 갯수

int dfs(int x, int y){
	if(x==n-1 && y==m-1){
		return 1;
	}//if
	
	if(wei[x][y]==-1){
		wei[x][y]=0;
		for(int k=0; k<4; k++){
			int ntx=x+dx[k];
			int nty=y+dy[k];
			if(ntx<0 || nty<0|| ntx>=n || nty>=m) continue;
			if(grp[x][y]>grp[ntx][nty]){
				wei[x][y]+=dfs(ntx, nty);
			}//if
		}//for-k
		
	}//if
	return wei[x][y];
}//dfs

//int dfs(int x, int y){	
//	if(x==n-1 && y==m-1){
//		return 1;
//	}//if
//	if(wei[x][y]!=0) return wei[x][y];
//	for(int k=0; k<4; k++){
//		int ntx=x+dx[k];
//		int nty=y+dy[k];
//		if(ntx<0 || nty<0|| ntx>=n || nty>=m) continue;
//		if(grp[x][y]>grp[ntx][nty]){
//			wei[x][y]+=dfs(ntx, nty);
//		}//if
//	}//for-k
//	return wei[x][y];	
//}//dfs

//wei[x][y]=1;
//int sum=0;
//for(int k=0; k<4; k++){
//	int ntx=x+dx[k];
//	int nty=y+dy[k];
//	if(ntx<0 || nty<0|| ntx>=n || nty>=m) continue;
//	if(grp[x][y]>grp[ntx][nty]){
//		if(wei[ntx][nty]==0){				
//			wei[x][y]+=dfs(ntx, nty);
//		}else if(wei[ntx][nty]!=0){
//			wei[x][y]=wei[ntx][nty]+1;
//			return wei[ntx][nty];
//		}//if			
//	}//if
//}//for-k

int main(){
	memset(wei, -1, sizeof(wei));
	scanf(" %d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %d", &grp[i][j]);
		}//for-j
	}//for-i
	//////////////////////////////////
	dfs(0,0);
	//////////////////////////////////
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%2d ", wei[i][j]);
		}//for-j
		printf("\n");
	}//for-i
	printf("%d\n", wei[0][0]);
	return 0;
}//main

// 내리막길 

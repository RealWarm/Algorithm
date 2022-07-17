#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int grp[30][30];
int wei[30][30];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pair<int, int> > q1;
int n, color;//가로, 세로 
int clr[26*26];

void dfs(int x, int y){
	wei[x][y]=color;
	for(int k=0; k<4; k++){
		int ntx = x+dx[k];
		int nty = y+dy[k];
		if(grp[ntx][nty]==1 && wei[ntx][nty]==0){//집이고, 방문안함 
			if(ntx<0 || ntx>=n || nty<0 || nty>=n){
				continue;
			}//if-2			
			dfs(ntx, nty);
		}//if-1
	}//for-k	
}//dfs

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d", &grp[i][j]);
		}//for-j
	}//fori
		
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j]==1 && wei[i][j]==0){ //집이 있고, 방문 안함 
				color++;
				dfs(i, j);
			}//if-1
		}//for-j
	}//for-i	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){			
			if(wei[i][j]!=0){
				clr[wei[i][j]-1]++;
			}
		}//for-j	
	}//for-i
	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){			
//			printf("%d ", wei[i][j]);
//		}//for-j	
//		printf("\n");
//	}//for-i
//	printf("%d", color);
	
	sort(clr, clr+color);
	printf("%d\n",color);
	for(int i=0; i<color; i++){
		printf("%d\n", clr[i]);
	}//for-i
	
	return 0;
}//main

/*
void bfs(int x, int y){
	wei[x][y]=color;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx = q1.front().first;
		int nwy = q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(grp[ntx][nty]==1 && wei[ntx][nty]==0){//집이고, 방문안함 
				if(ntx<0 || ntx>=n || nty<0 || nty>=n){
					continue;
				}//if-2
				wei[ntx][nty]=color;
				q1.push(make_pair(ntx, nty));
			}//if-1
		}//for-k
	}//while	
}//bfs
*/

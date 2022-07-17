#include<iostream>
#include<cstring>
using namespace std;
int grp[310][310];
int wei[310][310];
int dis[310][310];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n, m;

void dfs(int x, int y, int c){
	wei[x][y]=c;
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || ntx>=n || nty<0 || nty>=m) continue;
		if(wei[ntx][nty]==0 && grp[ntx][nty]>0){
			dfs(ntx, nty, c);
		}
	}//for-k
}//dfs

void make(int x, int y){
	//주변의 0의 갯수를 세어서 dis 배열에 저장한다. 
	int cnt=0;
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || ntx>=n || nty<0 || nty>=m) continue;
		if(grp[ntx][nty]==0){
			cnt++;
		}
	}//for-k	
	dis[x][y]=cnt;
}//make

int main(){	
	//그래프 입력
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	///////////////////////////////////////////////////
	//전체 영일때 예외처리
	int sum=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			sum+=grp[i][j];
		}//for-j
	}//for-i
	if(sum==0){
		printf("0");
		return 0;
	}
	/////////////////////////////////////////////////////////
	for(int t=1;;t++){
		//////주변의 0 갯수 세기////////////////////////////////////////
		memset(wei, 0, sizeof(wei));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(grp[i][j]>0)
					make(i,j);
			}//for-j
		}//for-i
		/////////////////빙산녹이기/////////////////// 
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				grp[i][j]-=dis[i][j];
				if(grp[i][j]<0) grp[i][j]=0;
			}//for-j
		}//for-i
		/////전체가 0이면 탈출////////////////////////////////
		sum=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				sum+=grp[i][j];
			}//for-j
		}//for-i
		if(sum==0){
			printf("0");
			return 0;
		}		
		/////덩어리가 몇개인지 세보자//////////////////////////////////
		int color=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(grp[i][j]>=1 && wei[i][j]==0){ 
					color++;
					dfs(i, j, color);
				}//if-1
			}//for-j
		}//for-i		
		if(color>=2){
			printf("%d", t);
			return 0;
		}//if-1
		/////////////////////////////////////////////////////////
	}//for-t
	
	return 0;
}//main

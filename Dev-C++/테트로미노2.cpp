#include<iostream>
#include<cstring> 
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int tet[4][4][2]={
	{{0,0}, {-1,0}, {0,-1}, {0,1}},
	{{0,0}, {-1,0}, {0, 1}, {1,0}},
	{{0,0}, {-1,0}, {0,-1}, {1,0}},
	{{0,0}, {0,-1}, {0, 1}, {1,0}}
};
int grp[510][510];
int wei[510][510];
int n, m;//세로, 가로 
int mmax; 

void dfs(int x, int y, int cnt, int sum){
	wei[x][y]=sum+grp[x][y];
	if(cnt==4){
		if(wei[x][y]>mmax){
			mmax=wei[x][y];
		}//if
		wei[x][y]=-1;
		return;
	}//if
	
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
		if(wei[ntx][nty]==-1){
			dfs(ntx, nty, cnt+1, wei[x][y]);
		}//if		
	}//for-k
	wei[x][y]=-1;	
}//dfs

void test(int x, int y){
	for(int i=0; i<4; i++){
		int flag=0;
		int tsum=0;
		for(int k=0; k<4; k++){
			int ntx=x+tet[i][k][0];
			int nty=y+tet[i][k][1];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m){
				flag=1;
				break;
			}//if-range	
			tsum+=grp[ntx][nty];
		}//for-j
		
		if(flag==0){
			if(mmax<tsum){
				mmax=tsum;
			}//if
		}//if
		
	}//for-i
	
}//test

int main(){
		
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i	
	memset(wei, -1, sizeof(wei));
	/////////////////////////////////////
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){			
			dfs(i, j, 1, 0);
		}//for-j
	}//for-i
	/////////////////////////////////////
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){			
			test(i, j);
		}//for-j
	}//for-i
	/////////////////////////////////////
	printf("%d\n", mmax);
	return 0;
}//main


// 입력 >> 0,0 부터 n,m까지 탐색 >>  

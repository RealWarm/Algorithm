#include<iostream>
#include<cmath>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[100][100];
int wei[100][100];
int ans[50];
int n, m, mmin, mmax, total, flag, cnt;

void dfs(int x, int y){
	wei[x][y]=1;
	for(int k=0; k<4; k++){
		int ntx = x + dx[k];
		int nty = y + dy[k];		
		if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
		int tnum= abs(grp[ntx][nty]-grp[x][y]);
		if(tnum>=mmin && tnum<=mmax && wei[ntx][nty]==0){
			if(flag==0){
				flag=1;
				cnt++;
			}
			dfs(ntx, nty);
			total++;
		}//if
	}//for-k	
}//dfs

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	scanf("%d %d", &mmin, &mmax);
		
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(wei[i][j]==0){
				flag=0;
				dfs(i, j);				
			}
		}//for-j
	}//for-i
	
	printf("%d", total+cnt);
	return 0;
}//main

#include<iostream>
#include<cmath>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[60][60];
int wei[60][60];
int n, m, mmin, mmax, total;

void dfs(int x, int y){
	wei[x][y]=1;
	
	for(int k=0; k<4; k++){
		int ntx = x+dx[k];
		int nty = y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
		if(abs(grp[ntx][nty]-grp[x][y])>=mmin && 
			abs(grp[ntx][nty]-grp[x][y])<=mmax && 
			wei[ntx][nty]==0){
			total++;
			dfs(ntx, nty);
		}
	}		
}//dfs

int main(){
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	scanf("%d %d", &mmin, &mmax);
	
	dfs(0, 0);
	
	printf("%d", total);
	
	return 0;
}//main

#include<iostream>
#include<algorithm> 
using namespace std;
int grp[30][30];
int wei[30][30];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int clr[25*25];
int n;

void dfs(int nwx, int nwy, int c){
	wei[nwx][nwy]=c;
	for(int k=0; k<4; k++){
		int ntx = nwx + dx[k];
		int nty = nwy + dy[k];
		if(ntx<0 || ntx>=n || nty<0 || nty>=n) continue;
		if(wei[ntx][nty]==0 && grp[ntx][nty]==1){
			wei[ntx][nty]=c;
			dfs(ntx, nty, c);
		}//if
	}//for-k	
}//dfs

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d", &grp[i][j]);
		}
	}
	
	int color=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(wei[i][j]==0 && grp[i][j]==1){
				dfs(i, j, ++color);
			}//if
		}//for-j
	}//for-i
	
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(wei[i][j]>0){
				clr[wei[i][j]-1]++;
			}
		}//for-j
	}//for-i
	
	sort(clr, clr+color);
	printf("%d\n", color);
	for(int i=0; i<color; i++){
		printf("%d\n",clr[i]);
	}
	
	return 0;	
}//main





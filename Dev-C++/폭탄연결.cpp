#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[]={-1, 1, 0, 0};//»óÇÏÁÂ¿ì 
int dy[]={ 0, 0,-1, 1};
queue<pair<int, int> > q1;
int grp[20][20];
int trp[20][20];
int wei[20][20];
int r, c;

void dfs(int x, int y, int c){
	trp[x][y]=c;
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=r || nty>=c) continue;
		if(grp[ntx][nty]==1 && trp[ntx][nty]==0){
			dfs(ntx, nty, c);			
		}//if
	}//for-k
}//dfs

void bfs(int x, int y, int c){
	trp[x][y]=c;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>r || nty>c) continue;
			if(grp[ntx][nty]==1 && trp[ntx][nty]==0){
				q1.push(make_pair(ntx, nty));
				trp[ntx][nty]=c;
			}//if
		}//for-k
	}//while
}//bfs

int main(){
	
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			scanf("%d", &grp[i][j]);			
		}//for-j
	}//for-i
	
	int color=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(grp[i][j]==1 && trp[i][j]==0){
				bfs(i, j, ++color);
			}//if
		}//for-j
	}//for-i
	
	printf("#d %d\n", color);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			printf("%d ", trp[i][j]);
		}//for-j
		printf("\n");
	}//for-i
	
	return 0;
}//main

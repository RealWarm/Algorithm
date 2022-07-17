#include<iostream>
#include<queue>
#include<algorithm> 
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
queue<pair<int, int> > q1;
int grp[30][30];
int wei[30][30];
int clr[25*25];
int n;

void bfs(int x, int y, int c){
	wei[x][y]=c;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx = nwx + dx[k];
			int nty = nwy + dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
			if(wei[ntx][nty]==0 && grp[ntx][nty]==1){
				wei[ntx][nty]=c;
				q1.push(make_pair(ntx, nty));
			}//if
		}//fork
	}//while	
}//bfs


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
				//집이고 방문 하지 않았다면
				bfs(i, j, ++color);
			}//if
		}//for-j
	}//for-i
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			clr[wei[i][j]]++;
		}//for-j
	}//for-i
		
	sort(clr+1, clr+color+1);
	printf("%d\n", color);
	for(int i=1; i<=color; i++){
		printf("%d\n", clr[i]);
	}//for-i
	
	
	return 0;
}//main







//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%d ", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i

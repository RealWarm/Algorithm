#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int grp[30][30];
int wei[30][30];
int n, dis, mnum; 	// 너비, 총이동거리, 적의 숫자. 
int ldis, inx, iny;	// 임시길의 최소값, 최소값의 좌표
queue<pair<int , int> > q1;
struct pp{
	int lv=2;
	int exp=0;
	int x, y;
};
pp p1;

void bfs(int x, int y){
	wei[x][y]=0;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx = nwx+dx[k];
			int nty = nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
			if(wei[ntx][nty]==-1 && grp[ntx][nty]<=p1.lv){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if 
		}//for-k		
	}//while	
}//bfs

int main(){
	
	memset(wei, -1, sizeof(wei));
	scanf("%d %d", &n, &p1.lv);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &grp[i][j]);
			if(grp[i][j]==9){
				//낙하지점이라면 				
				p1.x=i;
				p1.y=j;				
			}//if 
		}//for-j
	}//for-i	
	
	bfs(p1.x, p1.y);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){			
			if(grp[i][j]==p1.lv){ // 레벨이 같다면 
				printf(". ");
			}else if(grp[i][j]<=8 && grp[i][j]>=1 && grp[i][j]>p1.lv){
				//나보다 레벨이 높다면. 
				printf("X ");
			}else if(grp[i][j]<=8 && grp[i][j]>=1 && grp[i][j]<p1.lv && wei[i][j]==-1){
				//레벨은 낮지만 못먹는 다면. 
				printf("-1 ");
			}else if(grp[i][j]<=8 && grp[i][j]>=1 && grp[i][j]!=p1.lv){
				// 
				printf("%d ", wei[i][j]);
			}else if(grp[i][j]==9){
				// 사람의 위치 
				printf("* ");
			}else{
				printf("0 ");
			}
		}//for-j
		printf("\n");
	}//for-i
	
	return 0;
}//main

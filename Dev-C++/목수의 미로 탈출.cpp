#include<iostream> // 목수는 미로를 항상탈출할 수 있다. 
#include<cstdio>
#include<queue> 
using namespace std;
int grp[1010][1010];
int wei[1010][1010][2];
int dx[] = {0, 0,1,-1}; //동서남북 
int dy[] = {1,-1,0, 0};
queue<pair<int, int> > q1;
int st, n, m;

void bfs(int x, int y){//세로, 가로 	
	q1.push(make_pair(x,y));
	
	while(!q1.empty()){
		int nwx = q1.front().first;
		int nwy = q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(grp[ntx][nty]==0 && wei[ntx][nty][0]==0 && st==0){
				//벽아님, 방문안씀함, 도끼 안씀 
				if(ntx<0 || ntx>=n || nty<0 || nty>=m){
					 continue;
				}//if-2
				wei[ntx][nty][0]=wei[nwx][nwy][0]+1; 				
				q1.push(make_pair(ntx, nty));
			}else if(grp[ntx][nty]==1 && st==0){
				//벽만남, 도끼안 
				if(ntx<0 || ntx>=n || nty<0 || nty>=m){
					 continue;
				}//if-2
				st=1;
				wei[ntx][nty][1]=wei[nwx][nwy][0]+1; 				
				q1.push(make_pair(ntx, nty));
			}else if(grp[ntx][nty]==0 && wei[ntx][nty][1]==0 && st==1){//벽아님, 방문안함 
				if(ntx<0 || ntx>=n || nty<0 || nty>=m){
					 continue;
				}//if-2
				wei[ntx][nty][1]=wei[nwx][nwy][1]+1; 				
				q1.push(make_pair(ntx, nty));
			}//if-1		
		}//for-k
	}//while
}//bfs

int main(){
	
	int n, m; scanf("%d %d", &n, &m); //세로, 가로
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	wei[n-1][0][0]=1;
	bfs(n-1, 0);
//	printf("\n");
//	printf("\n");
	printf("%d", wei[0][m-1][0]==0 ? wei[0][m-1][1] : wei[0][m-1][0]);	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", wei[i][j][0]);
//		}//for-j
//		printf("\n");
//	}//for-i
//	printf("\n");
//	printf("\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", wei[i][j][1]);
//		}//for-j
//		printf("\n");
//	}//for-i
	
	return 0;
}//main

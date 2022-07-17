#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int grp[110][110];
int wei[110][110];
queue<pair<int, int> > q1;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n, m;

void bfs(){	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			if(wei[ntx][nty]==-1 && (grp[ntx][nty]==2 || grp[ntx][nty]==0)){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}
		}//for-k		
	}//while	
}//bfs

int main(){
	
	memset(wei, -1, sizeof(wei));
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
			if(grp[i][j]==2){
				q1.push(make_pair(i, j));
				wei[i][j]=1;
			} 
		}
	}
	
	bfs();
	int mmax=0;
	int flag=0;
	for(int i=0; i<n; i++){
		if(flag==1) break;
		for(int j=0; j<m; j++){
			if((grp[i][j]==2 || grp[i][j]==0) && wei[i][j]==-1){
				flag=1;		
				break;				
			}else if(wei[i][j]>mmax){
				mmax=wei[i][j];
			}
		}
	}
	
	if(flag==1) printf("-1\n");
	else printf("%d\n", mmax-1);
	
	return 0;
}//main

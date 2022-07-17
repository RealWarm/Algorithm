#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int grp[110][110];
int wei[110][110];
queue<pair<int, int> > q1;
vector<pair<int, int> > v1;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int tmin=987987987, flag;
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
			if(wei[ntx][nty]==0 && (grp[ntx][nty]==2 || grp[ntx][nty]==0)){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k		
	}//while	
}//bfs

int main(){
	
	int znum=0;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
			if(grp[i][j]==2){
				v1.push_back(make_pair(i, j));
			}else if(grp[i][j]==0){
				znum=1;
			}
		}//for-j
	}//for-i
	
	if(znum==0){
		printf("0\n");
		return 0;
	}
	
	for(int tp=0; tp<v1.size(); tp++){		
		int mmax=1;
		flag=0;
		memset(wei, 0, sizeof(wei));
		q1.push(make_pair(v1[tp].first, v1[tp].second));
		wei[v1[tp].first][v1[tp].second]=1;
		
		bfs();
			
		for(int i=0; i<n; i++){
			if(flag==1) break;
			for(int j=0; j<m; j++){
				if(grp[i][j] != 1 && wei[i][j]==0){
					flag=1;		
					break;				
				}else if(grp[i][j]==0 && wei[i][j]>mmax){
					mmax=wei[i][j];
				}//if
			}//for-j
		}//for-i		
	
		if(flag==0){
			if(mmax<tmin){
				tmin=mmax;
			}//if-2
		}//if-1	
		
	}//for-tp
	
	if(tmin==987987987){		
		printf("-1\n");	
	}else{		
		printf("%d\n", tmin-1);
	}
	
	
	return 0;
}//main

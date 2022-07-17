#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int grp[110][110];
int wei[110][110];
int tmp[110][110];
int ans[15];
queue<pair<int, int> > q1;
vector<pair<int, int> > v1;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int tmin, flag;
int n, m, k=2, vlen, mmax;

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


void get(int x){
	
	if(x==k){
		mmax=1;//임시 최대값 
		flag=0;
		memset(wei, 0, sizeof(wei));
		memcpy(grp, tmp, sizeof(tmp));
		
		for(int a=0; a<k; a++){			
			//k개의 향수를 큐에 넣는다.
			//향수가 있는 곳은 1로 방문 처리한다. 
			q1.push(make_pair(v1[ans[a]].first, v1[ans[a]].second));
			wei[v1[ans[a]].first][v1[ans[a]].second]=1;			
		}//for-a			
		
		bfs();
		
		for(int i=0; i<n; i++){
			if(flag==1) break;
			for(int j=0; j<m; j++){
				if(grp[i][j] != 1 && wei[i][j]==0){   
				// 길인데 방문하지 않았다. 
				// 빈칸이 없을때 해결부분 
					flag=1;		
					break;				
				}else if(grp[i][j]==0 && wei[i][j]>mmax){
					//방문한, 길이라면 
					mmax=wei[i][j];
				}//if
			}//for-j
		}//for-i		
	
		if(flag==0){
			if(mmax<tmin){
				tmin=mmax;
			}//if-3
		}//if-2
		
		
	}else{
		for(int i=0; i<vlen; i++){
			if(x==0 || ans[x]<i){
				ans[x]=i;
				get(x+1);
			}			
		}//for-i
	}//if-1	
}//get

int main(){
	
	int ts; scanf("%d", &ts);	
	for(int tt=1; tt<=ts; tt++){			
		//초기화
		int znum=0;			
		v1.clear();		
		tmin=987987;
		memset(ans, 0, sizeof(ans));
		memset(tmp, 0, sizeof(tmp));				
		scanf("%d %d %d", &n, &m, &k);
		//그래프입력 
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &tmp[i][j]);
				if(tmp[i][j]==2){
					v1.push_back(make_pair(i, j));
				}else if(tmp[i][j]==0){
					znum=1;
				}				
			}//for-j
		}//for-i
		
		if(znum==0){
			printf("#%d 0\n", tt);
			continue;
		}
		
		vlen=v1.size();
		get(0);
				
		if(tmin==987987){		
			printf("#%d -1\n", tt);	
		}else{		
			if(tmin>0) printf("#%d %d\n", tt, tmin-1);
			else printf("#%d 0\n", tt);
		}
		
	}//for-tt	
	
	return 0;
}//main

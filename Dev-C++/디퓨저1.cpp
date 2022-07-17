#include<iostream> 
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int dx[]={-1,1, 0,0};//상하좌우 
int dy[]={ 0,0,-1,1};
vector<pair<int, int> > v1;
queue<pair<int, int> > q1;
int grp[110][110];
int wei[110][110];
int ch[20];
int n, m, k;// 세로, 가로, 열어둘 디퓨저의 수 
int num;//디퓨저의 총갯수 
int mmin=987987;//디퓨저가 퍼지는데 필요한 최소 시간. 
int exflag;

void bfs(){	
	while(!q1.empty()){
		int nwx = q1.front().first;
		int nwy = q1.front().second;
		q1.pop();
		for(int a=0; a<4; a++){ //////////////////////////////여기 주의 하자. 
			int ntx=nwx+dx[a];
			int nty=nwy+dy[a];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			if(wei[ntx][nty]==-1 && (grp[ntx][nty]==0 || grp[ntx][nty]==2)){//여기 오타 실수!!!!!!!!!!!!!!!!!!!!!!!!! 
				//방문하지 않은 빈곳이라면.
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k		
	}//while	
}//bfs

void get(int x){
	
	if(x>=k){
		int flag=0;
		memset(wei, -1, sizeof(wei));
		for(int i=0; i<k; i++){
			int dfx=v1[ch[i]].first;
			int dfy=v1[ch[i]].second;
			q1.push(make_pair(dfx, dfy));
			wei[dfx][dfy]=0;
		}//for-i
		bfs();		
		int tmax=-1;
		for(int i=0; i<n; i++){
			if(flag==1) break;
			for(int j=0; j<m; j++){
				if(grp[i][j]==0 && wei[i][j]==-1){
					flag=1;
					break;
				}
				if(grp[i][j]==0 && wei[i][j]>tmax){					
					tmax=wei[i][j];
				}//if
			}//for-j
		}//for-i
		
		if(flag==1){
			return;
		}else{
			if(mmin>tmax){
				mmin=tmax;
			}
		}//if		
		
	}else{
		// 디퓨저 선택하기 
		for(int i=0; i<num; i++){
			if(x==0 || ch[x-1]<i){
				ch[x]=i;
				get(x+1);
			}//if
		}//for-i		
	}//if	
}//get

int main(){
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		v1.clear(); //	디퓨저의 좌표들을 담는 벡터 
		exflag=0; 	//	빈곳이 없고 && 벽과 디퓨저로 이루어져 있다면. 
		memset(ch, 0, sizeof(ch)); // 선택할 디퓨저의 번호를 담은 배열 
		mmin=987987987;
		scanf("%d %d %d", &n, &m, &k);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &grp[i][j]);
				if(grp[i][j]==2){
					v1.push_back(make_pair(i, j));
				}else if(grp[i][j]==0){
					exflag=1;
				}
			}//for-j
		}//for-i
		////////////////////////////////////////////////////////////
		if(exflag==0){
			printf("#%d 0\n", tt);
			continue;
		}		
		num=v1.size();
		get(0);
		
		if(mmin==987987987) printf("#%d -1\n", tt);
		else printf("#%d %d\n", tt, mmin);
	}//for-tt	

	return 0;
}//main




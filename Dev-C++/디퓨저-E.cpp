#include<iostream> 
#include<cstring> 
#include<vector>
#include<queue>
using namespace std;
int dx[]={-1,1, 0,0};
int dy[]={ 0,0,-1,1};
int grp[110][110];
int wei[110][110];
vector<pair<int, int> > v1;	
queue<pair<int, int> > q1;
int n, m, k, znum;

void bfs(){	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int a=0; a<4; a++){
			int ntx=nwx+dx[a];
			int nty=nwy+dy[a];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			if(wei[ntx][nty]==0 && (grp[ntx][nty]==0 || grp[ntx][nty]==2)){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k		
	}//while	
}//bfs

int main(){
	
	//입력 >> 배열복사 >> 향수 선택 >> 거리 세기 
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
	/////////////////////////////////////////////////////////////////////		
	int tmax=999999999; 
	int tf=0;
	
	for(int t=0; t<v1.size(); t++){
		memset(wei, 0, sizeof(wei));
		q1.push(make_pair(v1[t].first, v1[t].second));
		wei[v1[t].first][v1[t].second]=1;

		bfs();
		//만약 탐색하지 못한 칸이있고
		//max보다 큰값을 만나서 max 값이 갱신 되었다면
		//max의 초기값으로 다시 되돌린다. 
		int max=-987987; 
		int flag=0;	
		for(int i=0; i<n; i++){
			if(flag==1) break;
			for(int j=0; j<m; j++){
				if(grp[i][j]==0 && wei[i][j]>max){
					max=wei[i][j];
				}else if(wei[i][j]==0 && grp[i][j]==0){ // 여기 실수!!!!!!!!!!!!
					flag=1;					
					break;
				}//if
			}//for-j
		}//for-i
		if(flag==1){
			tf++;
		}else if(flag==0){
			if(tmax>max){
				tmax=max;
			}//if-2
		}//if-1		
	}//for-t	
	/////////////////////////////////////////////////////////////////////	
	if(tf==v1.size()){	
		printf("-1\n");
	}else{
		if(tmax==0) {
			printf("0\n");
		}else{
			printf("%d\n", tmax-1);
		}
	}//if-else	
	
	return 0;
}//main

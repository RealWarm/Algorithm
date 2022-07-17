#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n, m; // 세로 가로
int grp[110][110];
int wei[110][110];
int time, remain, tmp; // 다 녹는데 걸린 시간, 다 녹기 직전에 남은 갯수
queue<pair<int, int> > q1;

void bfs(int x, int y){
	// 표면이 치즈인것을 찾기
	// 찾은 치즈 0으로 바꾸기 
	tmp=0; 
	wei[x][y]=1;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx = q1.front().first;
		int nwy = q1.front().second;
		q1.pop();
		
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			if(wei[ntx][nty]==-1 && grp[ntx][nty]==0){
				wei[ntx][nty]=1;
				q1.push(make_pair(ntx, nty));
			}else if(wei[ntx][nty]==-1 && grp[ntx][nty]==1){
				wei[ntx][nty]=2;
				tmp++;
			}//if
		}//for-k
	}//while
		
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(wei[i][j]==2){
				grp[i][j]=0;
			}//if
		}//for-j
	}//for-i
//	printf("\n-----------\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
	
	if(tmp!=0){
		remain=tmp;
	}//if
	
}//bfs

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %d", &grp[i][j]);
		}//for-j
	}//for-i
	////////////////////////////////////////
	while(1){
		time++;
		memset(wei, -1, sizeof(wei));
		bfs(0, 0);
		if(tmp==0) break;
	}//while
	
	printf("%d\n%d\n", time-1, remain);
	
	return 0;
}//main


//printf("\n\n");
//for(int i=0; i<n; i++){
//	for(int j=0; j<m; j++){
//		printf("%d ", grp[i][j]);
//	}//for-j
//	printf("\n");
//}//for-i


// 설계
// 표면의 치즈를 체크한다 >> 녹인다 >> 남은갯수가 0이니? >> 종료
//									>> 아니라면 남은 갯수 저장. 


// 출력 
// 1. 치즈가 모두 녹아서 없어지는데 걸리는 시간을 출력
// 2. 모두 녹기 한시간 전에 남아 있는 치즈조각이 놓여 있는 칸의 갯수. 






















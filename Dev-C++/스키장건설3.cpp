#include<iostream> 
#include<vector> 
#include<cstring>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[20][20]; //원본배열 
int tmp[20][20]; //깎은산 
int wei[20][20]; //움직인거리 
int n, k;		 //세로가로, 최대깎기 
int mmax; //꺾인 횟수의 최대값 

void dfs(int x, int y, int dir, int cnt){
	// (xx, yy, -1, 0, grp[xx][yy]);
	// 좌표, 이전의 방향, 꺾인횟수, 이전 산의 높이	
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;		
		if(tmp[ntx][nty]<tmp[x][y] && wei[ntx][nty]==-1){
			// 다음 진행하려는 칸의 높이가 나보다 낮고
			if(dir==-1){
				wei[ntx][nty]=k+1;
				dfs(ntx, nty, k, cnt);
				wei[ntx][nty]=-1; // 요거 주의 하자 !! 
			}else if(dir==k){
				wei[ntx][nty]=k+1;
				dfs(ntx, nty, k, cnt);
				wei[ntx][nty]=-1;
			}else if(dir!=k){
				wei[ntx][nty]=k+1;
				dfs(ntx, nty, k, cnt+1);
				wei[ntx][nty]=-1;
			}//if
		}//if
	}//for-k
	
	if(mmax<cnt){
		mmax=cnt;
	}//if
	
}//dfs


int main(){	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		memset(grp, 0, sizeof(grp));		
		int top=0; 	// 정상의 높이 
		mmax=0;		// 최대로 꺾인 횟수 
		vector<pair<int, int> > v1;//꼭지점의 좌표들을 구한다. 
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf(" %d", &grp[i][j]);
				if(grp[i][j]>top){
					top=grp[i][j];
					v1.clear();
					v1.push_back(make_pair(i, j));
				}else if(grp[i][j]==top){
					v1.push_back(make_pair(i, j));
				}//if
			}//for-j
		}//for-i
		///////////////////////////////////////////////
		// 정상이 아닌 하나의 좌표를 1부터 K만큼 깎아본다.
		// 만약 0이상이라면 dfs탐색을 시작한다. 
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				 if(grp[i][j]==top) continue;
				 // 만약 지금 좌표가 정상좌표라면 다음 좌표로 
				 /////////////////////////////////////////////
				 // 해당좌표를 1~k만큼 깎아 본다. 
				 // 만약 깎았는데 높이가 음수라면 다른 점을 깎는다. 
				 for(int d=1; d<=k; d++){
				 	// 산을 복사하고 >> 깎는다. 
				 	memcpy(tmp, grp, sizeof(tmp));
				 	tmp[i][j]-=d;
				 	if(tmp[i][j]<0){
				 		// 만약 높이가 음수라면 다른좌표로 넘어간다. 
				 		break;
					 }//if
					 for(int dt=0; dt<v1.size(); dt++){
					 	memset(wei, -1, sizeof(wei));
					 	int xx=v1[dt].first;
					 	int yy=v1[dt].second;
					 	wei[xx][yy]=0;
					 	dfs(xx, yy, -1, 0);
					 }//for-dt
					 
				 }//for-d			 
				 
			}//for-j
			
		}//for-i
		
		printf("#%d %d\n", tt, mmax);
	}//for-tt
		
	return 0;
}//main

// 임의의 곳의 땅 높이를 최대 1~K 만큼 깎을 수 있는 상태다.
// (a, b)를 깎기로 했다면 다른 곳은 깎을 수 없다. 
// 꺾임이 많은 구간을 찾아야한다 
// >> 가장높은 곳에서부터 시작해서 가장 낮은곳으로 내려온다. 
// 구간내에는 같은 놓이는 있을 수 없다. 
// 산의 정상은 깎을수 없다.
// 지상의 높이는 0으로써 0미만으로는 깎을 수 없다. 

// 입력
// N(산의크기, 3<= n <=10), K(최대호 깎을 수 있는 깊이, 1<= k <= 5) // 3<=꼭대기수<=5 
// 그래프

// 출력
// 가장 많이 꺾였을 때의 꺾인 횟수를 출력하라 

// 설계

// 입력(산의 꼭대기 구하기) || 출력까지 테스트 완료 
// 정상이 아닌 임의읭 점을 선택한다 >> 1~k 만큼 깎아 본다.
// 각 정상에서 부터 dfs탐색을 시작한다. >> 꺾이는 횟수를 세어본다. 
//  










//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%d ", grp[i][j]);			
//		}//for-j
//		printf("\n");
//	}//for-i
//	
//	printf("top :: %d\n", top);
//	for(int i=0; i<v1.size(); i++){
//		printf("(%d, %d), ", v1[i].first, v1[i].second);
//	}//for-i
 

#include<iostream> 
#include<cstring>
#include<vector>
using namespace std;
int dx[]={0, 0,1,-1};
int dy[]={1,-1,0, 0};//우, 좌, 하, 상 
int grp[20][20];
int temp[20][20];
int wei[20][20];
int n, k, hmax; // 맵크기, 최대 깎을수 있는, 꼭대기의 높이 
int tmax, cmax; // 커브수, 최대 커브수 

void dfs(int ttt[20][20], int x, int y, int dir, int cnt){
//탐색할배열, 현재좌표 X,Y, 그점에서의 방향, 
// cnt : 해당점까지 오면서의 커브수(해당점에따라 커브수는 다르기때문에 지역변수를 썼음) 
	wei[x][y]=1;//시작점을 방문처리 
	for(int d=0; d<4; d++){// 4방향 모두로 탐색을 시작해보겠다. 
		int ntx=x+dx[d];
		int nty=y+dy[d];
		if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
		if(ttt[ntx][nty]<ttt[x][y] && wei[ntx][nty]==0){
			// 방문하지 않았고 
			// 자기보다 높이가 낮은 길을 찾아간다. 
			if(dir == -1){
				// 시작점에서 시작하는 방향에 따라서  
				// 커브를 세지 않기 위해서 
//				printf("(%d, %d)에서 (%d, %d)로 방향은 dir:: %d >>  d::%d  꺾임 >>  cnt ::  %d\n", x, y, ntx, nty, dir, d, cnt);				
			}else if(d!=dir){
				// 방향이 자신과 다르다면 cnt++ 한다. >> 커브라면 센다. 
				dfs(ttt, ntx, nty, d, ++cnt);
				wei[x][y]=0;//복귀할때 체크해제 	
				continue;			
//				printf("(%d, %d)에서 (%d, %d)로 방향은 dir:: %d >>  d::%d  꺾임 >>  cnt ::  %d\n", x, y, ntx, nty, dir, d, cnt);
			}
			dfs(ttt, ntx, nty, d, cnt);			
			wei[x][y]=0;//복귀할때 체크해제 				
		}//if
	}//for-d
	
	if(cnt>tmax){		
		tmax=cnt;
	} 
}//finder

int main(){
		
	///////////////////////////////////////////////////////////////////////////
	// 그래프 저장
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		memset(grp, 0, sizeof(grp));
		hmax=0;//초기화 주의하자.
		cmax=0;//초기화 주의하자.
		scanf("%d %d", &n, &k);
		vector<pair<int, int> > ttop;//산의 꼭짓점의 갯수는 3 이상 ttop 5이하 
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &grp[i][j]);
			}//for-j
		}//for-i
		// 꼭대기 높이 저장 && 꼭대기들의 좌표저장		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(hmax<grp[i][j]){
					hmax=grp[i][j];				
					ttop.clear();
					ttop.push_back(make_pair(i,j));
				}else if(hmax==grp[i][j]){
					ttop.push_back(make_pair(i,j));
				}//if-1
			}//for-j
		}//for-i
		///////////////////////////////////////////////////////////////////////////
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(grp[i][j]!=hmax){// 꼭대기가 아니면 k만큼 깎아보자.
				 	for(int a=0; a<=k; a++){//0부터 k만큼 산을 깎는다.	
				 		int result=grp[i][j]-a;
					 	if(result<0) break;//높이가 0미만이 되어서는 안된다.				 	
						for(int b=0; b<ttop.size(); b++){//모든 꼭대기에서 탐사를 시작한다. 
							memcpy(temp, grp, sizeof(grp));//테스트용 배열 복사. 
							memset(wei, 0, sizeof(wei));//방문을 체크하기 위한 배열 초기화 
							tmax=0;// 커브수 카운트 초기화 
							temp[i][j]-=a;// 해당점을 0~k 만큼 깎아본다. 
							int xx=ttop[b].first;
							int yy=ttop[b].second;
//							printf("(%d, %d)를 %d만큼 깎았고 (%d, %d)에서 탐색시작\n", i, j, a, xx, yy);
							dfs(temp, xx, yy, -1, 0);
							if(tmax>cmax) cmax=tmax;
//							printf("tmax :: %d  ||  cmax :: %d\n", tmax, cmax);
						}//for-b					
					 }//for-a
				}//if 
			}//for-j
		}//for-i
		
		printf("#%d %d\n", tt, cmax);
	}//for-tt
	
	
	return 0;
}//main

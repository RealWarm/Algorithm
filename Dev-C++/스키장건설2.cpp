#include<iostream> 
#include<cstring>
#include<vector>
using namespace std;
int dx[]={0, 0,1,-1};		//우, 좌, 하, 상 
int dy[]={1,-1,0, 0};
int grp[20][20];			//원본배열 
int temp[20][20];			//복사배열 
int wei[20][20];			//방문처리배열 VISITED 
int n, k;					//맵크기, 최대 깎을수 있는, 꼭대기의 높이 
int tmax, hmax, cmax;		//한경우에서의 최대 꺾임수, 전체에서 최대 꺾임수. 

void dfs(int x, int y, int dir, int cnt){
	// 현재좌표 X,Y, 그점에서의 방향, 
	// cnt : 해당점까지 오면서의 커브수
	// (해당점에따라 커브수는 다르기때문에 지역변수를 썼음)
	wei[x][y]=1;//방문처리 
	for(int k=0; k<4; k++){
		int ntx = x+dx[k];
		int nty = y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || ntx>=n) continue;
		if(wei[ntx][nty]==0 && temp[x][y]>temp[ntx][nty]){
			//방문하지 않았고 && 현재보다 작아야한다. 
			if(k!=dir){//만약 다른 방향으로 전진한다면. 
						//꺾이는 수를 증가시킨다.
				printf("1.(%d, %d)에서 (%d, %d)로 방향은 dir:: %d에서 k::%d로 바뀜 ||| cnt ::  %d\n", x, y, ntx, nty, dir, k, cnt);
				dfs(ntx, nty, k, ++cnt);
				wei[ntx][nty]=0; //방문했던 칸의 체크를 푼다. >> 다른경우도 해보기 위해서
				if(cnt>tmax){
					tmax=cnt;
				} 
			}else{
				//방향이 같다면 그냥 전진한다. 
				printf("2.(%d, %d)에서 (%d, %d)로 방향은 dir:: %d에서 k::%d로 바뀜 ||| cnt ::  %d\n", x, y, ntx, nty, dir, k, cnt);
				dfs(ntx, nty, k, cnt);	
				wei[ntx][nty]=0; //방문했던 칸의 체크를 푼다. >> 다른경우도 해보기 위해서
				if(cnt>tmax){
					tmax=cnt;
				} 							
			}//if
		}//if		
	}//for-k	
	
}//dfs


int main(){
	
	scanf("%d %d", &n, &k);
	vector<pair<int, int> > ttop;//산의 꼭짓점의 갯수는 3 이상 ttop 5이하 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &grp[i][j]);
			if(hmax<grp[i][j]){
				hmax=grp[i][j];				
				ttop.clear();
				ttop.push_back(make_pair(i,j));
			}else if(hmax==grp[i][j]){
				ttop.push_back(make_pair(i,j));
			}//if-1
		}//for-j
	}//for-i
	///////////////////////////////////////////////////////////////////////
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j]!=hmax){// 꼭대기가 아니면 0 부터 k만큼 깎아보자.
			 	for(int a=0; a<=k; a++){// 0부터 k만큼 산을 깎는다.	
			 		int result=grp[i][j]-a;
			 		if(result<0) break;// 높이가 0미만이면 다른점에 대해서 시도해본다.
					for(int b=0; b<ttop.size(); b++){//모든 꼭대기에서 탐사를 시작한다.  						
						memcpy(temp, grp, sizeof(grp));//테스트용 배열 복사. 
						memset(wei, 0, sizeof(wei));//방문을 체크하기 위한 배열 초기화 
						temp[i][j]-=a;// 해당점을 0~k 만큼 깎아본다. 
						tmax=0; //부분최대의 꺾임수 저장. 
						int xx=ttop[b].first;
						int yy=ttop[b].second;
						printf("(%d, %d)를 깎아서%d로 만들고  (%d, %d)에서 탐색시작\n", i, j, temp[i][j], xx, yy);
						dfs(xx, yy, 1111111, 0);//정상의 좌표, 전진하는 방향, 껏은횟수. 
						if(tmax>cmax){// 탐색했던 모든 경우중에서 최대값이 있다면 바꾼다. 
							cmax=tmax;
						}//if	
						printf("tmax :: %d  ||  cmax :: %d\n", tmax, cmax);
					}//for-b					
				}//for-a
			}//if
		}//for-j
	}//for-i 
	
	printf("#%d\n", cmax-1);
		
	return 0;
}//main










#include<iostream>
#include<cstring>
using namespace std;
int grp[110][110];
int wei[110][110];
int n, cnt;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void go(int x, int y, int dir){
	wei[x][y]=1;
	int nwx=x;
	int nwy=y;
	int gox=dx[dir];
	int goy=dy[dir];
	while(1){
		//일단 전진해보고 판단 
		nwx+=gox;
		nwy+=goy;
		if(nwx<0 || nwx>=n || nwy<0 || nwy>=n){
			//벽을 만나면 방향을 바꾼다.
			//원상태로 돌아온다. 
			nwx-=gox;
			nwy-=goy;
			
			gox*=-1;
			goy*=-1;			
		}else if(grp[nwx][nwy]==0 && wei[nwx][nwy]==0){
			//방문하지 않은 길이면
			//체크하고 걸음수를 증가시킨다. 
			wei[nwx][nwy]=1;
			cnt++;
			printf("*** %d", cnt);
		}else if(grp[nwx][nwy]==0 && wei[nwx][nwy]==1){
			//길이지만 왔던길이라면
			continue;			
		}else if(grp[nwx][nwy]==-1){
			//턱이면 바로 끝낸다. 
			return;
		}else if(grp[nwx][nwy]>=6 && grp[nwx][nwy]<=10){
			//워프를 밟는다. 
			if(wei[nwx][nwy]==0){
				wei[nwx][nwy]=1;
				cnt++;	
				printf("*** %d", cnt);
			}			
			// 워프를 만나면 해당자리를 체크하고(wei를 1로) 걸음수 증가(cnt++) 
			// 다른 워프로 좌표를 이동한다 >> 해당좌표를 체크하고 >> cnt++ 
			for(int a=0; a<n; a++){
				for(int b=0; b<n; b++){
					if(a==nwx && b==nwy){
						continue;
					}else if(grp[a][b]==grp[nwx][nwy]){
						nwx=a;
						nwy=b;
						if(wei[nwx][nwy]==0){
							wei[nwx][nwy]=1;
							cnt++;	
							printf("*** %d", cnt);
						}
					}//if-else
				}//for-b
			}//for-a
		}else if(grp[nwx][nwy]>=1 && grp[nwx][nwy]<=5){
			//장매물 체크하고 >> 걸음수를 센다. 
			if(wei[nwx][nwy]==0){
				wei[nwx][nwy]=1;
				cnt++;	
				printf("*** %d", cnt);
			}
			//장애물을 만난다면			
			if(grp[nwx][nwy]==1 && gox==1 && goy==0){
				gox	= 0;
				goy	= -1;
			}else if(grp[nwx][nwy]==1 && gox==0 && goy==1){
				gox	= -1;
				goy	= 0;
			}else if(grp[nwx][nwy]==2 && gox==1 && goy==0){
				gox	= 0;
				goy = 1;
			}else if(grp[nwx][nwy]==2 && gox==0 && goy==-1){
				gox = -1;
				goy = 0;
			}else if(grp[nwx][nwy]==3 && gox==0 && goy==-1){
				gox = 1;
				goy = 0;
			}else if(grp[nwx][nwy]==3 && gox==-1 && goy ==0){
				gox = 0;
				goy = 1;
			}else if(grp[nwx][nwy]==4 && gox==0 && goy==1){
				gox = 1;
				goy = 0;
			}else if(grp[nwx][nwy]==4 && gox==-1 && goy==0){
				gox = 0;
				goy = -1;
			}else{
				gox*=-1;
				goy*=-1;
			}//if-2			
		}//if-1
		
		if(nwx==x && nwy==y && gox==dx[dir] && goy==dy[dir]){
			//원위치와 좌표가 같고
			//방향이 같다면 종료 
			printf("%d %d %d %d", x, y, gox, goy);
			return;
		}//if-1
	}//while	
}//go

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &grp[i][j]);
		}
	}
	
	int max=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j]==0){
				for(int k=0; k<4; k++){
					memset(wei, 0, sizeof(wei));
					cnt=0;
					go(i, j, k);
					if(cnt>max){
						max=cnt; 
					}//if
				}//for-k				
			}//if
		}//for-j
	}//for-i
	
	printf("%d", max);
	
	return 0;
}//main

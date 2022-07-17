#include<iostream>
#include<cstring>
using namespace std;
int grp[110][110];
int wei[110][110];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n, cnt;

void go(int x, int y, int dir){	
	wei[x][y]=1;	
	int nwx=x;
	int nwy=y;
	int gox=dx[dir];
	int goy=dy[dir];
//	printf("*시작:(%d, %d) (%d, %d) dir :%d  \n", x, y, dx[dir], dy[dir], dir);
	while(1){
		//일단 전진해보고 판단 
		nwx+=gox;
		nwy+=goy;		
		if(nwx<0 || nwx>=n || nwy<0 || nwy>=n){
			//벽을 만나면 180도 방향을 바꾼다.
			//원상태로 돌아온다.
			gox=gox*-1;
			goy=goy*-1;			
			nwx+=gox;
			nwy+=goy;
//			printf("* 벽을 만남 :(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
			////////////////////////////////////////////////////////////////
			//워프를 했는데 벽에 바로 부딪힌경우 
			int flag=0; 
			if(grp[nwx][nwy]>=6 && grp[nwx][nwy]<=10){
				//워프를 밟는다. 
//				printf("* 벽만나고 바로 워프 밟음:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);				
				for(int a=0; a<n; a++){
					for(int b=0; b<n; b++){
						if(a==nwx && b==nwy){
							//워프자신이면 pass 
							continue;
						}else if(grp[a][b]==grp[nwx][nwy]){
							//워프이면서 자식과 번호가 같으면 이동
							if(flag==0){
								nwx=a;
								nwy=b;
//								printf("*벽만나고 바로 워프 이동:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);							
								flag=1;
							}//if							
						}//if-1
					}//for-b
				}//for-a
			}//if-1	
			
			if(grp[nwx][nwy]>=1 && grp[nwx][nwy]<=5){
				//장매물 체크하고 >> 걸음수를 센다. 
				//방향을 바꿔준다. 
//				printf("* %d 장애물 만남:(%d, %d) 방향변경전(%d, %d) cnt :%d  \n", grp[nwx][nwy], nwx, nwy, gox, goy, cnt);				
							
				if(grp[nwx][nwy]==1 && gox==1 && goy==0){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox	= 0;
					goy	= -1;
				}else if(grp[nwx][nwy]==1 && gox==0 && goy==1){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox	= -1;
					goy	= 0;
				}else if(grp[nwx][nwy]==2 && gox==1 && goy==0){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox	= 0;
					goy = 1;
				}else if(grp[nwx][nwy]==2 && gox==0 && goy==-1){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = -1;
					goy = 0;
				}else if(grp[nwx][nwy]==3 && gox==0 && goy==-1){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = 1;
					goy = 0;
				}else if(grp[nwx][nwy]==3 && gox==-1 && goy ==0){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = 0;
					goy = 1;
				}else if(grp[nwx][nwy]==4 && gox==0 && goy==1){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = 1;
					goy = 0;
				}else if(grp[nwx][nwy]==4 && gox==-1 && goy==0){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = 0;
					goy = -1;
				}else{
					if(wei[nwx][nwy]==0){//안해도되는건가? 
						wei[nwx][nwy]=1;						
					}//if-2
					gox=gox*-1;
					goy=goy*-1;				
				}//if-2			
//				printf("* %d 장애물 만남:(%d, %d) 방향변경후(%d, %d) cnt :%d  \n", grp[nwx][nwy], nwx, nwy, gox, goy, cnt);
			}//if-1 
											
		}else if(grp[nwx][nwy]==0 && wei[nwx][nwy]==0){
			//방문하지 않은 길이면
			//체크하고 걸음수를 증가시킨다. 
			wei[nwx][nwy]=1;
			cnt++;
//			printf("* 길:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
		}else if(grp[nwx][nwy]==0 && wei[nwx][nwy]==1){
			//길이지만 왔던길이라면
//			printf("* 길:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
//			continue;	///////////////////////////////		
		}else if(grp[nwx][nwy]==-1){
			//턱이면 바로 끝낸다. 
//			printf("* 턱만남:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
			return;
		}else if(grp[nwx][nwy]>=6 && grp[nwx][nwy]<=10){
			//워프를 밟는다. 
//			printf("* 워프 밟음:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
			if(wei[nwx][nwy]==0){
				wei[nwx][nwy]=1;
				cnt++;					
			}			
			// 워프를 만나면 해당자리를 체크하고(wei를 1로) 걸음수 증가(cnt++) 
			// 다른 워프로 좌표를 이동한다 >> 해당좌표를 체크하고 >> cnt++ 
			int flag=0;
			for(int a=0; a<n; a++){
				for(int b=0; b<n; b++){
					if(a==nwx && b==nwy){
						//워프자신이면 pass 
						continue;
					}else if(grp[a][b]==grp[nwx][nwy]){
						//워프이면서 자식과 번호가 같으면 이동 
						
//						printf("* 워프 이동:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
						
//실수!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
						if(wei[a][b]==0){
							wei[a][b]=1;
							cnt++;								
						}//if-2 
						
						if(flag==0){
							nwx=a;
							nwy=b;
//							printf("*벽만나고 바로 워프 이동:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);							
							flag=1;
						}//if
						
						
					}//if-1
				}//for-b
			}//for-a
		}else if(grp[nwx][nwy]>=1 && grp[nwx][nwy]<=5){
			//장매물 체크하고 >> 걸음수를 센다. 
			//방향을 바꿔준다. 
//			printf("* %d 장애물 만남:(%d, %d) 방향변경전(%d, %d) cnt :%d  \n", grp[nwx][nwy], nwx, nwy, gox, goy, cnt);				
						
			if(grp[nwx][nwy]==1 && gox==1 && goy==0){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox	= 0;
				goy	= -1;
			}else if(grp[nwx][nwy]==1 && gox==0 && goy==1){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox	= -1;
				goy	= 0;
			}else if(grp[nwx][nwy]==2 && gox==1 && goy==0){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox	= 0;
				goy = 1;
			}else if(grp[nwx][nwy]==2 && gox==0 && goy==-1){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = -1;
				goy = 0;
			}else if(grp[nwx][nwy]==3 && gox==0 && goy==-1){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = 1;
				goy = 0;
			}else if(grp[nwx][nwy]==3 && gox==-1 && goy ==0){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = 0;
				goy = 1;
			}else if(grp[nwx][nwy]==4 && gox==0 && goy==1){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = 1;
				goy = 0;
			}else if(grp[nwx][nwy]==4 && gox==-1 && goy==0){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = 0;
				goy = -1;
			}else{
				if(wei[nwx][nwy]==0){//안해도되는건가? 
					wei[nwx][nwy]=1;						
				}//if-2
				gox=gox*-1;
				goy=goy*-1;				
			}//if-2			
//			printf("* %d 장애물 만남:(%d, %d) 방향변경후(%d, %d) cnt :%d  \n", grp[nwx][nwy], nwx, nwy, gox, goy, cnt);
		}//if-1 
		
		if(nwx==x && nwy==y && gox==dx[dir] && goy==dy[dir]){
			//원위치와 좌표가 같고
			//방향이 같다면 종료 
//			printf("*return home :: %d %d %d %d\n", nwx, nwy, gox, goy);
			return;
		}//if-1
	}//while	
}//go

int main(){
		
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		memset(grp, 0, sizeof(grp));
		memset(wei, 0, sizeof(wei));
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &grp[i][j]);
			}
		}
		
		int max=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(grp[i][j]==0){//장애물, 턱이 아니면 탐색시작. 
					for(int k=0; k<4; k++){//4방향 모두 전진 시켜보기 
						memset(wei, 0, sizeof(wei));
						cnt=1;
						go(i, j, k);//x, y, dir
						if(cnt>max){
							max=cnt; 
						}//if
					}//for-k				
				}//if
			}//for-j
		}//for-i
	
	printf("#%d %d\n", tt, max);
	}//for-tt
	
	
	return 0;
}//main

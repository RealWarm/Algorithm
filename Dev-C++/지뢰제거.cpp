#include<iostream>
#include<cstring>
using namespace std;
int grp[20][20];
int sim1[20][20];
int sim2[20][20];
int b1x[]={0, 0,1,-1};//sizeof(b1x)/sizeof(int)
int b1y[]={1,-1,0, 0};
int b2x[]={-1, 1,-1,1};//sizeof(b2x)/sizeof(int)
int b2y[]={-1,-1, 1,1};
int b3x[]={-2,-2,-2, 0,0, 2,2,2};//sizeof(b3x)/sizeof(int)
int b3y[]={-2, 0, 2,-2,2,-2,0,2};
int n, m, cnt;
int mmax;

int bomb(int ttt[20][20], int x, int y, int n){//실행배열, x, y, 지뢰번호 
	//해당좌표의 지뢰를 터친다. 
	if(n==1){		
		ttt[x][y] = -1;//해당자리를 칠한다.
		for(int k=0; k<4; k++){
			int ntx = x+b1x[k];
			int nty = y+b1y[k];
			if(ntx<0 || ntx>=n || nty<0 || nty>=m ) continue;			
			if(ttt[ntx][nty]>0){//지뢰라면 
				bomb(ttt, ntx, nty, ttt[ntx][nty]);
			}else{//터진공간이거나 빈공간이라면 
				ttt[ntx][nty]=-1;
			}//if-else
		}//for-k
		
	}else if(n==2){		
		ttt[x][y]=-1;//해당자리를 칠한다.
		for(int k=0; k<4; k++){
			int ntx = x+b2x[k];
			int nty = y+b2y[k];
			if(ntx<0 || ntx>=n || nty<0 || nty>=m) continue;
			if(ttt[ntx][nty]>0){
				bomb(ttt, ntx, nty, ttt[ntx][nty]);
			}else{
				ttt[ntx][nty]=-1;
			}//if-else
		}//for-k
		
	}else if(n==3){		
		ttt[x][y]=-1;//해당자리를 칠한다.
		for(int k=0; k<8; k++){
			int ntx = x+b3x[k];
			int nty = y+b3y[k];
			if(ntx<0 || ntx>=n || nty<0 || nty>=m) continue;
			if(ttt[ntx][nty]>0){
				bomb(ttt, ntx, nty, ttt[ntx][nty]);
			}else{
				ttt[ntx][nty]=-1;
			}//if-else
		}//for-k
		
	}//if-else
	
}//bomb 

int main(){	

	int ts=0; scanf("%d", ts);
	for(int tt=1; tt<=ts; tt++){
		
	}//for-tt
	memset(grp, 0, sizeof(grp));
	memset(sim1, 0, sizeof(sim1));	
	memset(sim2, 0, sizeof(sim2));	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	
	int tq=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(grp[i][j]!=0) tq++;
			
	if(tq==0){
		printf("#%d 0\n", 11111111111);
//		continue;
	}
	
	memcpy(sim1, grp, sizeof(grp));
	/////////////////////////////////////////////////////
	//최댓값을 구한다.	
	for(int h=0; h<2; h++){
		int tmax=0, xinx=0, yinx=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){				
				int ct=0;
				memcpy(sim2, sim1, sizeof(sim1));
				if(grp[i][j]>0){//지뢰라면 터쳐보자. 
					bomb(sim2, i, j, grp[i][j]);
				}
				
				for(int a=0; a<n; a++){
					for(int b=0; b<m; b++){
						if(sim2[a][b]==-1){
							ct++;
						}
					}//for-b
				}//for-a
				
				if(ct>tmax){
					tmax=ct;
					xinx=i;
					yinx=j;
				}//if
				
				printf("************%d %d\n", i, j);						
				for(int a=0; a<n; a++){
					for(int b=0; b<m; b++){
						printf("%d ", sim2[a][b]);						
					}//for-b
					printf("\n");
				}//for-a
				printf("\n");
				printf("\n");
				
			}//for-i
		}//for-j
		bomb(sim1, xinx, yinx, grp[xinx][yinx]);
	}//for-h
	
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
////			if(sim1[i][j]!=0){
////				mmax++;
////			}
//			printf("%d ", sim1[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
	///////////////////////////////////////////////////////////
	//max에 해당되는 경우의 수를 세어본다. 
	memcpy(sim1, grp, sizeof(grp));	
	for(int h=0; h<2; h++){
		int tmax=0, xinx=0, yinx=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){				
				int ct=0;
				memcpy(sim2, sim1, sizeof(sim1));
				if(grp[i][j]>0){//지뢰라면 터쳐보자. 
					bomb(sim2, i, j, grp[i][j]);
				}
				
				for(int a=0; a<n; a++){
					for(int b=0; b<m; b++){
						if(sim2[a][b]==-1){
							ct++;
						}
					}//for-b
				}//for-a
				
				if(ct>tmax){
					tmax=ct;
					xinx=i;
					yinx=j;
				}//if
				
				int ttt=0;
				for(int a=0; a<n; a++){
					for(int b=0; b<m; b++){
						if(sim2[a][b]==-1){
							ttt++;							
						}
					}//for-b					
				}//for-a
				
				if(ttt==mmax){
					cnt++;
				}
			}//for-i
		}//for-j
		bomb(sim1, xinx, yinx, grp[xinx][yinx]);
	}//for-h
	
//	printf("%d %d", mmax, cnt);
	
	return 0;
}//main























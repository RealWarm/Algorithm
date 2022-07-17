#include<iostream>
#include<cstring>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[20][20];
int temp[20][20];
int n, m, k; 

void bomb(int ttt[20][20], int x, int y, int pw){
	ttt[x][y]=0;
	// 해당좌표에서 물풍선의 사정거리로 물풍선을 터뜨린다. 	
	for(int k=0; k<4; k++){
		int ntx = x;
		int nty = y;
		int dis = pw;
		while(dis--){
			ntx+=dx[k];
			nty+=dy[k];			
			if(ntx<0 || ntx>=n || nty<0 || nty>=m ) break;			
			if(ttt[ntx][nty]!=0){
				bomb(ttt, ntx, nty, ttt[ntx][nty]);
			}
		}//while
	}//for-k	
}//bomb

int main(){
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		scanf("%d %d %d", &n, &m, &k);	
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d", &grp[i][j]);	
						
		int tq=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(grp[i][j]!=0) tq++;
				
		if(tq==0){
			printf("#%d 0\n", tt);
			continue;
		}
		
		for(int t=1; ; t++){
			int max=0;
			int xinx=0;
			int yinx=0;
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(grp[i][j]!=0){
						memcpy(temp, grp, sizeof(grp));	
						bomb(temp, i, j, temp[i][j]);						
						int cnt=0;
						for(int a=0; a<n; a++){
							for(int b=0; b<m; b++){
								if(temp[a][b]==0){
									cnt++;
								}//if
							}//for-b
						}//for-a
						
						if(cnt>max){
							max=cnt;
							xinx=i;
							yinx=j;
						}//if
						
					}//if
				}//for-j
			}//for-i
			bomb(grp, xinx, yinx, grp[xinx][yinx]);
			int cnt=0;
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(grp[i][j]!=0){
						cnt++;
					}
				}
			}
			
			if(cnt==0){//다터졌을경우 
				if(k>=t){
					printf("#%d 0\n", tt);
					break;
				}else if(k<t){
					printf("#%d %d\n", tt,t-k);
					break; 
				}//if-2
			}//if-1
			
		}//for-t
	}//for-tt
		
	return 0;	
}//main

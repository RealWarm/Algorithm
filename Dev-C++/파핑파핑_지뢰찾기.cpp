#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int dx[]={-1, -1, -1, 0, 1, 1,  1,  0}; // 대각선 8가지 
int dy[]={-1,  0,  1, 1, 1, 0, -1, -1};
int wei[300][300];
vector<string> grp;
int n, mmin; // 표의 크기, 최소로 터친수 

void dfs(int x, int y, int cl){ 
	wei[x][y]=cl;
	
	int tnum=0; // 주변 지뢰 갯수	 
	for(int k=0; k<8; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
		if(grp[ntx][nty]=='*') tnum++;
	}//for-k
	
	if(tnum==0){
		for(int k=0; k<8; k++){
			int ntx=x+dx[k];
			int nty=y+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
			if(wei[ntx][nty]==-1){
				dfs(ntx, nty, cl);
			}//if
		}//for-k
	}else if(tnum>0){
		wei[x][y]=cl;
	}//if
	
}//dfs


int main(){
	int ts; scanf(" %d", &ts);	
	for(int tt=1; tt<=ts; tt++){
		grp.clear(); // 원본배열 
		memset(wei, -1, sizeof(wei));
		scanf(" %d", &n);
		grp.resize(n);
		for(int i=0; i<n; i++){
			cin>>grp[i];
		}//for-i
		////////////////////////////////////////////////
		int gnum=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){				
				int mnum=0;
				if(grp[i][j]=='.' && wei[i][j]==-1){					
					for(int k=0; k<8; k++){
						int nx=i+dx[k];
						int ny=j+dy[k];
						if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
						if(grp[nx][ny]=='*') mnum++;
					}//for-k

					if(mnum==0){
						gnum++;
						wei[i][j]=gnum;
						for(int k=0; k<8; k++){
							int nx=i+dx[k];
							int ny=j+dy[k];
							if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
							// dfs(i, j, gnum);
							if(wei[nx][ny]==-1){
								dfs(nx, ny, gnum);
							}//if
						}//for-k
					}//if

				}//if 
				
			}//for-j
			
		}//for-i
		////////////////////////////////////////////////////////////
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){	
				if(grp[i][j]=='.' && wei[i][j]==-1){
					wei[i][j]=++gnum;
				}//if
			}//for-j			
		}//for-i	
		/////////////////////////////////////////////////////////////
//		for(int i=0; i<n; i++){
//			for(int j=0; j<n; j++){	
//				printf("%2d ", wei[i][j]);
//			}//for-j			
//			printf("\n");
//		}//for-i
		
		printf("#%d %d\n", tt, gnum);
	}//for-tt
	
	return 0;
}//main


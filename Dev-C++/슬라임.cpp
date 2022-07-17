#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[100][100];
int wei[100][100];
int ans[50];
int n, m, mmin, mmax, total, flag, cnt, sum;

void dfs(int x, int y, int c){
	wei[x][y]=c;//그룹을 나눈다. 
	for(int k=0; k<4; k++){
		int ntx = x + dx[k];
		int nty = y + dy[k];		
		if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
		int tnum= abs(grp[ntx][nty]-grp[x][y]);//인접한 슬라임과의 무게차이 
		if(tnum>=mmin && tnum<=mmax && wei[ntx][nty]==-1){
			if(flag==0){
				//합치기 시작했다면. 
				flag=1;
				sum+=grp[x][y];
				cnt++;
				wei[x][y]=cnt;//그룹지정 
			}
			sum+=grp[ntx][nty];
			dfs(ntx, nty, cnt);
			total++;
		}//if
	}//for-k	
}//dfs

int main(){
	
	int tt; scanf("%d", &tt);	
	for(int ts=1; ts<=tt; ts++){
		memset(grp, 0, sizeof(grp));
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &grp[i][j]);
			}//for-j
		}//for-i
		scanf("%d %d", &mmin, &mmax);
		
		int q=0;
		for(; ; q++){
			
			cnt=0;//합치기 시작한 슬라임의 갯수. 
			memset(wei, -1, sizeof(wei));
			memset(ans, 0, sizeof(ans));
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(wei[i][j]==-1){
						flag=0;
						total=0;
						sum=0;
						dfs(i, j, 0);	
						if(flag==1){
							ans[cnt]=sum/(total+1);
						}//if-2
					}//if-1
				}//for-j
			}//for-i
			
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(wei[i][j]>0){
						grp[i][j]=ans[wei[i][j]];
					}//if
				}//for-j
			}//for-i
			
			if(cnt==0) break;
		}//for-q
		
	
		
		printf("#%d %d\n", ts, q);
	}//for-ts
	
	return 0;
}//main






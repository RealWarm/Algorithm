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

void dfs(int x, int y){
	wei[x][y]=1;
	for(int k=0; k<4; k++){
		int ntx = x + dx[k];
		int nty = y + dy[k];		
		if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
		int tnum= abs(grp[ntx][nty]-grp[x][y]);
		if(tnum>=mmin && tnum<=mmax && wei[ntx][nty]==0){
			if(flag==0){
				flag=1;
				sum+=grp[x][y];
				cnt++;
			}
			sum+=grp[ntx][nty];
			dfs(ntx, nty);
			total++;
		}//if
	}//for-k	
}//dfs

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	scanf("%d %d", &mmin, &mmax);
	
	for(int tq=0; tq<2; tq++){
		cnt=0;		
		memset(wei, 0, sizeof(wei));
		memset(ans, 0, sizeof(ans));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(wei[i][j]==0){
					flag=0;
					total=0;
					sum=0;
					dfs(i, j);	
					if(flag==1){
						ans[cnt]=sum/(total+1);
					}//if-2
				}//if-1
			}//for-j
		}//for-i
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(wei[i][j]!=0){
					grp[i][j]=ans[wei[i][j]];
				}
			}
		}
	}//for-tq
	
	
	sort(ans, ans+cnt+1, greater<int>());
	if(cnt==0){
		printf("-1\n");
	}else{
		for(int i=1; i<=cnt; i++){
			printf("%d\n", ans[i]);
		}
	}
	
	return 0;
}//main

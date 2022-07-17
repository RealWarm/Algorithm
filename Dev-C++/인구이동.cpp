#include<iostream> 
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<pair<int, int> > v1;
int dx[]={0, 0,1,-1};
int dy[]={1,-1,0, 0};
int clr[10010];
int grp[60][60];
int wei[60][60];
int n, l, r;
int sum, cnt;//진행해 가면서 더하기, 갯수 세기. 
int color;

void dfs(int x, int y, int c){
	v1.push_back(make_pair(x, y));
	sum+=grp[x][y];
	cnt++;
	wei[x][y]=c;
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
		int diff=abs(grp[ntx][nty]-grp[x][y]);
		if(wei[ntx][nty]==0 && 	// 방문 하지 않았고 
			diff>=l && diff<=r){// 인구수의 차이가 범위내라면 
			wei[ntx][nty]=c;
			dfs(ntx, nty, c);					
		}//if
	}//for-k	
}//dfs

int main(){
		
	sum=0;
	cnt=0;
	color=0;
	v1.clear();	
	scanf("%d %d %d", &n, &l, &r);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i				
	
	int day=0;
	while(1){								
		color=0;
		memset(wei, 0, sizeof(wei));				
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(wei[i][j]==0){
					sum=0;
					cnt=0;
					v1.clear();	
					dfs(i, j, ++color);				
					int mid=sum/cnt;
					for(int i=0; i<v1.size(); i++){
						grp[v1[i].first][v1[i].second]=mid;
					}//for-i					
				}//if
			}//for-j
		}//for-i
		if(color==n*n) break;		
		day++;					
	}//while
	
	printf("%d\n", day);	
	
	return 0;
}//main

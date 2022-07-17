#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
queue<pair<int, int> > q1;
vector<pair<int, int> > v1; // 변경되어야할 좌표 
vector<int> v2;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[100][100];
int wei[100][100];
int n, m, mmin, mmax, total;
int sum; 

void bfs(int x, int y){	
	total++;
	sum+=grp[x][y];	
	v1.push_back(make_pair(x, y));
	wei[x][y]=1;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx = nwx + dx[k];
			int nty = nwy + dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			int tnum= abs(grp[ntx][nty]-grp[nwx][nwy]);
			if(tnum>=mmin && tnum<=mmax && wei[ntx][nty]==0){				
				total++;				
				sum+=grp[ntx][nty];
				v1.push_back(make_pair(ntx, nty));
				wei[ntx][nty]=1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//fork
	}//while	
}//bfs

int main(){
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &grp[i][j]);
			}//for-j
		}//for-i
		scanf("%d %d", &mmin, &mmax);	
		
		int day=0;
		while(1){		
			memset(wei, 0, sizeof(wei));
			v1.clear();//바꿀값들의 좌표들 
			v2.clear();//평균값들을 저장 
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					if(wei[i][j]==0){
						v1.clear();				
						sum=0;
						total=0;
						bfs(i, j);
						int mid=sum/total;
						if(total>1){
							v2.push_back(mid);
							for(int i=0; i<v1.size(); i++){
								grp[v1[i].first][v1[i].second]=mid;
							}//for-i						
						}//if
					}//if
				}//for-j
			}//for-i
			if(v2.size()==0) break;
			day++;
		}//while	
		
		printf("#%d %d\n", tt, day);
	}//for-tt
	
	
	return 0;
}//main










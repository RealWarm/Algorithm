#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
queue<pair<int, int> > q1;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[100][100];
int wei[100][100];
int n, m, mmin, mmax, total;

void bfs(int x, int y){
	total++;
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
				wei[ntx][nty]=1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//fork
	}//while	
}//bfs

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	scanf("%d %d", &mmin, &mmax);
	
	int sum=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(wei[i][j]==0){
				total=0;
				bfs(i, j);					
				if(total>1){
					sum+=total;
				}//if
				printf("total :: %d\n", total);
			}//if
		}//for-j
	}//for-i
	printf("%d", sum);
	
	return 0;
}//main










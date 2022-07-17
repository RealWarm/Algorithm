#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int grp[110][110];
int wei[110][110];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<pair<int , int> > q1;
int n, m; // 세로, 가로 

void bfs(int x, int y){
	wei[x][y]=1;
	q1.push(make_pair(x, y));	
	while(!q1.empty()){
		int nwx = q1.front().first;
		int nwy = q1.front().second;
		q1.pop();		
		for(int k=0; k<4; k++){
			int ntx = nwx+dx[k];
			int nty = nwy+dy[k];
			if(ntx<0 || ntx>=n || nty<0 || nty>=m) continue;
			if(grp[ntx][nty]==1 && wei[ntx][nty]==0){			
				wei[ntx][nty]=1;
				grp[ntx][nty]=0;
			}else if(grp[ntx][nty]==0 && wei[ntx][nty]==0){
				wei[ntx][nty]=1;
				q1.push(make_pair(ntx, nty));
			}//if-1			
		}//for-k		
	}//while	
}//bfs

int main(){
	
	int time=0, sum=0;
	scanf("%d %d", &n, &m);	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			sum+=grp[i][j];
		}//for-j			
	}//for-i
		
	if(sum==0){
		printf("0\n0");
		return 0;
	}//if-1	
	
	while(1){
		int temp=0;
		memset(wei, 0, sizeof(wei));		
		bfs(0,0);
		time++;
				
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				temp+=grp[i][j];
			}//for-j			
		}//for-i
		
		if(temp!=0){
			sum=temp;			
		}else if(temp==0){			
			break;
		}//if-1
	}//while
	
	printf("%d\n", time);
	printf("%d", sum);
	
	return 0;
}//main

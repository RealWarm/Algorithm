#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int grp[1010][1010];
int wei[1010][1010];
queue<pair<int, int> > q1;
int n, m;//����, ����
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(int x, int y){//����, ���� 
	wei[x][y]=1;	
	q1.push(make_pair(x,y));
	
	while(!q1.empty()){
		int nwx = q1.front().first;
		int nwy = q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || ntx>=n || nty<0 || nty>=m) continue;
			if(grp[ntx][nty]==0 && wei[ntx][nty]==0){//���ƴ�, �湮���� 			
				wei[ntx][nty]=wei[nwx][nwy]+1; 				
				q1.push(make_pair(ntx, nty));
			}//if-1			
		}//for-k
	}//while
}//bfs

int main(){
	
	scanf("%d %d", &n, &m); //����, ����
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
		
	bfs(n-1,0);
	printf("%d",wei[0][m-1]-1);
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", wei[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
	return 0;
}//main

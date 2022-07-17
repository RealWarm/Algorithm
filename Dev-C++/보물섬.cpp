#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<string> grp;
queue<pair<int, int> > q1;
int wei[60][60];
int n, m; 	// 세로 가로 
int mmax;	//둘사이의 최단거리 

void bfs(int x, int y){
	int tmax=0;
	wei[x][y]=0;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			if(wei[ntx][nty]==-1 && grp[ntx][nty]=='L'){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				if(wei[ntx][nty]>tmax) tmax=wei[ntx][nty];
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
		
	}//while
//	printf("----------------------------------\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%2d ", wei[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
	
	
	if(tmax>mmax){		
		mmax=tmax;
//		printf("%d\n", tmax);
	}//if
	
}//bfs

int main(){
	scanf("%d %d", &n, &m);
	grp.resize(n);
	for(int i=0; i<n; i++){
		cin >> grp[i];
	}//for-i
	///////////////////////////////////////////
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grp[i][j]=='L'){
				//방문하지 않았다면 
				memset(wei, -1, sizeof(wei));
				bfs(i, j);
			}//if
		}//for-j
	}//for-i
	///////////////////////////////////////////

	///////////////////////////////////////////
	printf("%d\n", mmax);
	
	return 0;
}//main



// 입력
// N M
// 육지(L), 바다(W)

// 

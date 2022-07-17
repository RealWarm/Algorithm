#include <iostream> 
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[30][30];
int wei[30][30];
int gg[25*25];
int n;

void dfs(int x, int y, int c){
	wei[x][y]=c;
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
		if(wei[ntx][nty]==-1 && grp[ntx][nty]==1){
			dfs(ntx, nty, c);
		}//if
	}//for-k
}//dfs

void bfs(int x, int y, int c){
	wei[x][y]=c;
	queue<pair<int, int> > q1;
	q1.push(make_pair(x, y));
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
			if(wei[ntx][nty]==-1 && grp[ntx][nty]==1){
				wei[ntx][nty]=c;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while
}//bfs

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%1d", &grp[i][j]);
		}//for-j
	}//for-i
	///////////////////////////////////////////////
	memset(wei, -1, sizeof(wei));
	int clr=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(wei[i][j]==-1 && grp[i][j]==1){
				bfs(i, j, clr++);
			}//if
		}//for-j
	}//for-i	
	//////////////////////////////////////////////
	vector<int> ans;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			gg[wei[i][j]]++;
		}//for-j		
	}//for-i	
	//////////////////////////////////////////////
	for(int i=0; i<25*25; i++){
		if(gg[i]!=0){
			ans.push_back(gg[i]);
		}//if
	}//for-i
	//////////////////////////////////////////////
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for(int i=0; i<ans.size(); i++){
		printf("%d\n", ans[i]);
	}//for-i
	return 0;
}//main

// 단지번호 붙이기 >> 단지 갯수 세기 






//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%d", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i

//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%2d ", wei[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i

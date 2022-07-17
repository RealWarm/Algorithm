#include<iostream> 
#include<vector>
#include<queue>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int n, m, k;
int sum;
int grp[110][110];
int wei[110][110];
int result[20];
vector<pair<int, int> > v1;	
queue<pair<int, int> > q1;

void bfs(){	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			if(wei[ntx][nty]==0 && grp[ntx][nty]==0){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k		
	}//while
	
	printf("\n\n\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ", wei[i][j]);
		}//for-j
		printf("\n");
	}//for-i
	printf("\n");
}//bfs

int main(){
	
	scanf("%d %d ", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);			
			if(grp[i][j]==2){
				v1.push_back(make_pair(i, j));
				sum++;
			}//if
		}//for-j
	}//for-i
	
	for(int i=0; i<sum; i++){
		q1.push(make_pair(v1[i].first, v1[i].second));
		wei[v1[i].first][v1[i].second]=1;
	}
	
	bfs();
		
	int max=0; 
	int flag=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(wei[i][j]>max){
				max=wei[i][j];
			}else if(wei[i][j]==0 && grp[i][j]==0){
				flag=1;
			}
		}//for-j
	}//for-i
	
	if(flag==1){
		printf("-1\n");
	}else{
		printf("%d\n", max-1);	
	}	
	
	return 0;
}//main

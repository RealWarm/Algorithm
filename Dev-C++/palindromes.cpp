#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct pp{
	int x;
	int y;
	int b;
};//pp
int grp[1010][1010];
int wei[1010][1010][2];
int n, m;

int main(){
	scanf(" %d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d", &grp[i][j]);
		}//for-j
	}//for-i	
	//////////////////////////////////////////////////////////////////////
	queue<pp> q1;
	q1.push({0, 0, 0});
	wei[0][0][0]=1;
	wei[0][0][1]=1;
	while(!q1.empty()){
		int nwx=q1.front().x;
		int nwy=q1.front().y;
		int nst=q1.front().b;		
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			if(grp[ntx][nty]==0){
//				printf("in here\n");
				if(wei[ntx][nty][nst]==0){
					if(nst==0){
//						printf("abn :: %d %d\n", ntx, nty);
					}//if
					wei[ntx][nty][nst]=wei[nwx][nwy][nst]+1;
					q1.push({ntx, nty, nst});
				}//if
			}else if(grp[ntx][nty]==1 && nst==0){
				if(wei[ntx][nty][1]==0){
					wei[ntx][nty][1]=wei[nwx][nwy][0]+1;
					q1.push({ntx, nty, 1});
				}//if
			}//if
		}//for-k			
	}//while
	//////////////////////////////////////////////////////////////////////
	if(wei[n-1][m-1][0]==0 && wei[n-1][m-1][1]==0){
		printf("-1\n");
	}else if(wei[n-1][m-1][0]!=0 && wei[n-1][m-1][1]==0){
		printf("%d\n", wei[n-1][m-1][0]);
	}else if(wei[n-1][m-1][0]==0 && wei[n-1][m-1][1]!=0){
		printf("%d\n", wei[n-1][m-1][1]);
	}else{
		printf("%d\n", wei[n-1][m-1][0]>=wei[n-1][m-1][1]
						? wei[n-1][m-1][1] :wei[n-1][m-1][0]);
	}//if
	return 0;
}//main



//		printf("%d %d %d\n", nwx, nwy, nst);









//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i




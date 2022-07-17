#include<iostream> 
#include<cstring>
#include<queue>
using namespace std;
int dx[]={-1,-2,-2,-1, 1,2,2,1};
int dy[]={-2,-1,1,2, -2,-1,1,2};
int wei[310][310];

int main(){
	int ts; scanf("%d", &ts);
	while(ts--){
		memset(wei, 0, sizeof(wei));
		int n; scanf("%d", &n);
		queue<pair<int, int> > q1;		
		int sx, sy; scanf("%d %d", &sx, &sy);
		int ex, ey; scanf("%d %d", &ex, &ey);
		if(sx==ex && sy==ey){
			printf("0\n");
			continue;
		}
		
		q1.push(make_pair(sx, sy));
		wei[sx][sy]=0;
		
		while(!q1.empty()){
			int nwx=q1.front().first;
			int nwy=q1.front().second;
			q1.pop();
			for(int k=0; k<8; k++){
				int ntx=nwx+dx[k];
				int nty=nwy+dy[k];
				if(ntx<0 || nty<0|| ntx>=n || nty >=n) continue;
				if(wei[ntx][nty]==0){
					wei[ntx][nty]=wei[nwx][nwy]+1;
					q1.push(make_pair(ntx, nty));
				}//if
			}//for-k
		}//while
		printf("%d\n", wei[ex][ey]);
	}//while
	return 0;
}//main

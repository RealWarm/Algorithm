#include<iostream>
#include<queue>
using namespace std;
int grp[110][110];
int dx[] = {0, 0,1,-1}; //동서남북 
int dy[] = {1,-1,0, 0};
int nx, ny, ndir;
int px, py, pdir;
int n, m; // 세로, 가로 
struct tup{	
	int x;
	int y;
	int dir;
	int cnt;
};//tuple
queue<tup> q1;
tup wei[110][110];

tup make_tup(int x, int y, int dir, int cnt){	
	tup t1;	
	t1.x=x;
	t1.y=y;
	t1.dir=dir;
	t1.cnt=cnt;	
	return t1;
}//make_tup

void bfs(int x, int y, int dir, int cnt1){
	wei[x][y].cnt=cnt1;// 1. 체크한다.	
	q1.push({x, y, dir, cnt1}); // 2. 해당좌표를 큐에 넣는다. 
	
	while(!q1.empty()){
		int nwx=q1.front().x;
		int nwy=q1.front().y;
		int nwdir=q1.front().dir;
		int nwcnt=q1.front().cnt;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			///////////////////////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////////////
			if(wei[ntx][nty].cnt==0 && grp[ntx][nty]==0 
				&& ntx==px && nty==py ){
				if(nwdir!=k){
					while(1){
						nwdir++;
						nwcnt++;
						if(nwdir>=4){
							nwdir=0;							
						}
						if(nwdir==k){
							printf("%d\n",nwcnt);
							return;
						}
					}
					
				}else if(nwdir==k){
					printf("%d\n",nwcnt);
					return;
				}
				wei[ntx][nty]=make_tup(ntx, nty, nwdir, nwcnt);
			}
			if(wei[ntx][nty].cnt==0 && grp[ntx][nty]==0){
				//방문하지 않았고 && 길이라면 
				if(nwdir!=k){
					//방향이 다르면
					// 1. 방향을 바꾸고
					// 2. 전진을 해야한다. 
					nwcnt+=2;
					nwdir=k;
				}				
				wei[ntx][nty]=make_tup(ntx, nty, nwdir, nwcnt);
				q1.push(make_tup(ntx, nty, nwdir, nwcnt));
			}
		}//for-k		
	}//while	
}//bfs

int main(){
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	scanf("%d %d", &n, &m);	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i			
	scanf("%d %d %d", &nx, &ny, &ndir);
	scanf("%d %d %d", &px, &py, &pdir);
	nx-=1; ny-=1; px-=1; py-=1; ndir-=1; pdir-=1; // 0,0 기준으로 바꾸기 위해서 
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	bfs(nx, ny, ndir, 1);
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////
	printf("\n");
	printf("\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
//			wei[i][j].cnt-=1;
			printf("%d ", wei[i][j].cnt);
		}//for-j		
		printf("\n");
	}//for-i
	printf("\n");
	printf("\n");
	///////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////	
//	if(wei[px][py].dir==pdir){
////		printf(" =================\n");
//		printf("%d", wei[px][py].cnt);		
//	}else if(wei[px][py].dir!=pdir){
////		printf("!!!!!!!!!!!!======\n");
//		printf("%d", wei[px][py].cnt+1);
//	}
	
	return 0;
}//main

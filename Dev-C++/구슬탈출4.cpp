#include<iostream> 
#include<string> 
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct bead{
	int rx;
	int ry;	
	int bx;
	int by;
	int cnt=0;
};
char grp[15][15];
int wei[15][15][15][15]; // rx, ry, bx, by
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int n, m;// 세로, 가로 
int hx, hy;
bead bbd;
queue<bead> q1;
int mmin=987987987; // 기울인 횟수 

bead go(int rx, int ry, int bx, int by, int d){
	// 구슬을 해당 방향으로 쭉 이동시킨다
	bead ntb;	
	
	while(1){
		// 파랑구슬 전진. 
		// '.' 이면 전진한다, 구멍이면 전진한다. 그리고 바로 반환 
		int ntx=bx+dx[d];
		int nty=by+dy[d];
//		if(wei[rx][ry][ntx][nty] != -1) break;
		if(grp[ntx][nty]=='.'){
			bx=ntx;
			by=nty;
		}else if(grp[ntx][nty]=='O'){
			ntb.bx=ntx;
			ntb.by=nty;
			return ntb;
		}else if(grp[ntx][nty]=='#'){
			break;	
		}//if				
	}//while
	ntb.bx=bx;
	ntb.by=by;
	
	while(1){//빨강구슬전진
		int ntx=rx+dx[d];
		int nty=ry+dy[d];
//		if(wei[ntx][nty][bx][by] != -1) break;
		if(grp[ntx][nty]=='.'){
			rx=ntx;
			ry=nty;
		}else if(grp[ntx][nty]=='O'){
			ntb.rx=ntx;
			ntb.ry=nty;
			return ntb;
		}else if(grp[ntx][nty]=='#'){
			break;	
		}//if)
	}//while 
 	ntb.rx=rx;
 	ntb.ry=ry;
 	
	return ntb;
	
}//go

int main(){
	memset(wei, -1, sizeof(wei));
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %c", &grp[i][j]);
			if(grp[i][j]=='R'){
				grp[i][j]='.';
				bbd.rx=i;
				bbd.ry=j;
			}else if(grp[i][j]=='B'){
				grp[i][j]='.';
				bbd.bx=i;
				bbd.by=j;
			}else if(grp[i][j]=='O'){
				hx=i;
				hy=j;
			}//if
		}//for-j
	}//for-i
	///////////////////////////////////////////////
	q1.push(bbd);
	wei[bbd.rx][bbd.ry][bbd.bx][bbd.by]=0;
	
	while(!q1.empty()){
		
		int nrx=q1.front().rx, nry=q1.front().ry;
		int nbx=q1.front().bx, nby=q1.front().by;
		int ncnt=q1.front().cnt;		
		q1.pop();		
		if(ncnt>10 || ncnt>=mmin) continue;		
		
		for(int k=0; k<4; k++){
			// 구슬을 해당 방향으로 전진
			bead ntbd = go(nrx, nry, nbx, nby, k);
			// 파란구슬이 구멍에 들어갔다면 탈출 
			if(ntbd.bx==hx && ntbd.by==hy) continue;
			// 움직이지 않으면 넘어가기			
			if(ntbd.rx==nrx && ntbd.ry==nry &&
				ntbd.bx==nbx && ntbd.by==nby) continue;
			// 서로 겹쳐있다면 >> 지금점과 거리가 더먼 구슬을 뒤로 보내기
			if(ntbd.rx==ntbd.bx && ntbd.by==ntbd.ry){
				int rdis=abs(ntbd.rx-nrx)+abs(ntbd.ry-nry);
				int bdis=abs(ntbd.bx-nbx)+abs(ntbd.by-nby);
				if(rdis>bdis){
					ntbd.rx-=dx[k];
					ntbd.ry-=dy[k];
				}else if(rdis <= bdis){
					ntbd.bx-=dx[k];
					ntbd.by-=dy[k];
				}//if
			}//if
			// 빨간구슬이 구멍에 들어갔다면 최소값 설정
			if(ntbd.rx==hx && ntbd.ry==hy){
				if(mmin > ncnt+1){
					mmin = ncnt+1;
					break;
				}//if
			}//if
			
			// 구슬이 움직엿고, 구멍에 빠지지 않았고, 
			ntbd.cnt=ncnt+1;
			q1.push(ntbd);
						
		}//for-k
		
	}//while
	
	if(mmin==987987987) printf("-1\n");
	else printf("%d\n", mmin);

	return 0;
}//main



//	printf("\n");
//	printf("\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%c ", grp[i][j]);			
//		}//for-j
//		printf("\n");
//	}//for-i

// 입력 n, m
// '.'은 빈 칸을 의미하고, 
// '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 
// 'O'는 구멍의 위치를 의미한다. 
// 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬 

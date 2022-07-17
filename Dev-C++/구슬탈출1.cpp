#include<iostream> 
#include<queue>
using namespace std;
struct bead{
	int rx, ry, bx, by, d;
};
char a[20][20];	//원본저장 
int check[20][20][20][20];	//빨간좌표(x, y) || 파란좌표(x, y)
queue<bead> q;
int dx[]={-1, 0, 1, 0};//상 우 하 좌 
int dy[]={ 0, 1, 0,-1};
int n, m;//세로 가로

void move(int &x, int &y, int &c, int dx, int dy) {
	//x, y 에서 dx, dy 방향으로 전진 시킨다. 
	while(a[x+dx][y+dy]!='#' && a[x][y]!='O'){
		//벽이 아니고 구멍이 아니라면 전진시킨다. 
		x+=dx;
		y+=dy;
		c+=1;
	}//while
}//move
 
void bfs(){
	
	while(!q.empty()){
		int rx=q.front().rx, ry=q.front().ry;// 현재 red의 좌표 추출 
		int bx=q.front().bx, by=q.front().by;// 현재 blue의 좌표 추출 
		int d = q.front().d; //명령의 횟수. 
		q.pop();
		if(d>=10) break; //굴리는 과정이 10번을 넘어가면 그대로 종료한다. 
		for(int k=0; k<4; k++){
			int nrx=rx, nry=ry;
			int nbx=bx, nby=by;
			int rc=0, bc=0, nd=d+1;
			move(nrx, nry, rc, dx[k], dy[k]);
			move(nbx, nby, bc, dx[k], dy[k]);
			if(a[nbx][nby]=='O') continue;
			if(a[nrx][nry]=='O'){
				printf("%d\n", nd);
				return;
			}//if
			if(nrx==nbx && nry==nby){
				if(rc>bc) nrx-=dx[k], nry-=dy[k];
				else nbx-=dx[k], nby-=dy[k];
			}//if
			if(check[nrx][nry][nbx][nby]==1)continue;
			check[nrx][nry][nbx][nby]=1;
			q.push({nrx, nry, nbx, nby, nd});
		}//for-k		
	}//while
	printf("-1\n"); // 10번이하로 움직여서 빼낼 수 없으면 '-1'을 출력한다. 
	
}//bfs

int main(){
	
	scanf("%d %d", &n, &m);
	int rx, ry, bx, by;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %c", &a[i][j]);
			if(a[i][j]=='R'){
				rx=i;
				ry=j;
			}else if(a[i][j]=='B'){
				bx=i;
				by=j;
			}//if
		}//for-j
	}//for-i
		
	q.push({rx, ry, bx, by, 0});
	check[rx][ry][bx][by]=1;
	bfs();
		
	return 0;
}//main

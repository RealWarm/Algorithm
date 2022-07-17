#include<iostream> 
#include<queue>
using namespace std;
struct bead{
	int rx, ry, bx, by, d;
};
char a[20][20];	//�������� 
int check[20][20][20][20];	//������ǥ(x, y) || �Ķ���ǥ(x, y)
queue<bead> q;
int dx[]={-1, 0, 1, 0};//�� �� �� �� 
int dy[]={ 0, 1, 0,-1};
int n, m;//���� ����

void move(int &x, int &y, int &c, int dx, int dy) {
	//x, y ���� dx, dy �������� ���� ��Ų��. 
	while(a[x+dx][y+dy]!='#' && a[x][y]!='O'){
		//���� �ƴϰ� ������ �ƴ϶�� ������Ų��. 
		x+=dx;
		y+=dy;
		c+=1;
	}//while
}//move
 
void bfs(){
	
	while(!q.empty()){
		int rx=q.front().rx, ry=q.front().ry;// ���� red�� ��ǥ ���� 
		int bx=q.front().bx, by=q.front().by;// ���� blue�� ��ǥ ���� 
		int d = q.front().d; //����� Ƚ��. 
		q.pop();
		if(d>=10) break; //������ ������ 10���� �Ѿ�� �״�� �����Ѵ�. 
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
	printf("-1\n"); // 10�����Ϸ� �������� ���� �� ������ '-1'�� ����Ѵ�. 
	
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

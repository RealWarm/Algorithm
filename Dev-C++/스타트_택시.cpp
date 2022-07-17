#include <iostream> 
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct person{
	int px;
	int py;
	int gx;
	int gy;
	int dist=0; 
};
struct taxi{
	int x;
	int y;
	int f=0;
};
vector<person> v1; // ��� �迭 
int wei[25][25];
int grp[25][25];
int n, m, f;	//���Ǳ���, �°��Ǽ�, �ʱ� ���ᷮ 
taxi tx;		//�ý� 

person make_pp(int px, int py, int gx, int gy){
	person ps;
	ps.px=px;
	ps.py=py;
	ps.gx=gx;
	ps.gy=gy;
	return ps;
}//make_pp

int cmp(person p1, person p2){
	// �Ÿ� ª�� >> ���۰� >> ���۰� >> ����
	if(p1.dist<p2.dist){
		return 1;
	}else if(p1.dist==p2.dist){
		if(p1.py<p2.py){
			return 1;
		}else if(p1.py==p2.py){
			if(p1.px<p2.px){
				return 1;				
			}else{
				return 0;
			}//if
		}else{
			return -1;
		}//if-2
	}else{
		return 0;
	}//if
}//cmp

// �°��� �������� �°��� ��ġ��� 


int go(){
	// bfs�� �����Ѵ� >> �ִܰŸ��� �մ��� ã�´� >> ������������ �Ÿ��� ���Ѵ�
	// ���� ����� �Ÿ��� ���ϱ� >> ���ᰡ ���ų� ���ٸ� �̵��Ѵ� >> ���ᰪ �������ֱ�
	// �ýø� �̵���Ų�� >> ���Ḧ ä��� >> �ش� �մ��� �����Ѵ�. 
	///////////////////////////////////////////////////////////////////
	// �ýú��� ��������� �ִܰŸ��� ���Ѵ� 
	memset(wei, -1, sizeof(wei));
	queue<pair<int, int> > q1;
	q1.push(make_pair(tx.x, tx.y));
	wei[tx.x][tx.y]=0;
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
			if(grp[ntx][nty]==0 && wei[ntx][nty]==-1){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while
	// ��ֹ��� ���� �������� ���� 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j]==0 && wei[i][j]==-1){
				return -1;
			}//if
		}//for-j
	}//for-i	
	///////////////////////////////////////////////////////////
	// ������� �Ÿ��� �ʱ�ȭ ���ش�
	// �Ÿ� ª�� >> ���۰� >> ���۰� >> ����
	// 0���� ��ǥ�� ��´�. 
	for(int i=0; i<v1.size(); i++){
		int fx=v1[i].px;
		int fy=v1[i].py;
		v1[i].dist=wei[fx][fy];
	}//for-i
	sort(v1.begin(), v1.end(), cmp);	
	int del=0;
	if(tx.f<v1[0].dist) return -1;
	tx.f-=v1[0].dist;
	
//	printf("move1=======================\n");
//	for(int i=0; i<v1.size(); i++){
//		printf("%d %d %d\n", v1[i].px, v1[i].py, v1[i].dist);
//	}//for-i
	
//	printf("%d, %d :: %d", v1[del].px, v1[del].py, mmin);
	////////////////////////////////////////////////////////////
	// �մԿ��� ������������ �ִܰŸ� ���ϱ� 
	memset(wei, -1, sizeof(wei));	
	q1.push(make_pair(v1[del].px, v1[del].py));
	wei[v1[del].px][v1[del].py]=0;	
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
			if(grp[ntx][nty]==0 && wei[ntx][nty]==-1){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j]==0 && wei[i][j]==-1){
				return -1;
			}//if
		}//for-j
	}//for-i
	
	// ���ᰡ �ȴٸ� �ýø� �������� �̵���Ų��. 
	int ggx=v1[del].gx;
	int ggy=v1[del].gy;
	if(tx.f>=wei[ggx][ggy]){
		tx.f=tx.f-wei[ggx][ggy]; // ���� �߰� 
		tx.f=tx.f+2*wei[ggx][ggy]; // ���� �߰�
		tx.x=ggx;
		tx.y=ggy;
		v1.erase(v1.begin()+del);	
//		printf("���� ���� :: %d\n", tx.f);
	}else{
		return -1;
	}//if 
	return -1;
}//go

int main(){
	
	scanf("%d %d %d", &n, &m, &f);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %d", &grp[i][j]);
		}//for-j
	}//for-i	
	scanf("%d %d", &tx.x, &tx.y);
	tx.x--, tx.y--;
	tx.f=f;
	for(int i=0; i<m; i++){
		int px, py, gx, gy;
		scanf("%d %d %d %d", &px, &py, &gx, &gy);
		px--, py--, gx--, gy--;
		v1.push_back(make_pp(px, py, gx, gy));
	}//for-i	
	/////////////////////////////////////////////////////////////
//	go();
	for(int i=0; i<m; i++){
		if(go()==-1){
			printf("-1\n");
			return 0;
		}else if(v1.size()<=0){
			break;
		}//if
	}//for-i
	
	printf("%d\n", tx.f);
	
	return 0;
}//main



//	int mmin=987987, del=0;
//	for(int i=0; i<v1.size(); i++){		
//		if(mmin>wei[v1[i].px][v1[i].py]){
//			mmin=wei[v1[i].px][v1[i].py];
//			del=i;
//		}//if
//	}//for-i
//	if(tx.f>=mmin){
//		tx.f-=mmin;	
//	}else{
//		return 988;
//	}

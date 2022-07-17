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
	int dis=-987;//�մ԰� �ýû����� �Ÿ� 
};
struct taxi{
	int x;
	int y;
	int f=0;
};
vector<person> v1;
int grp[25][25];
int wei[25][25];
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

int comp(person p1, person p2){
	if(p1.dis<p2.dis){
		return 1;
	}else if(p1.dis==p2.dis){
		if(p1.py<p2.py){
			return 1;
		}else if(p1.py==p2.py){
			if(p1.px<p2.px){
				return 1;
			}else{
				return 0;
			}//if-3
		}else if(p1.py>p2.py){
			return 0;
		}//if-2
	}else if(p1.dis>p2.dis){
		return 0;
	}//if-1
}//comp

int go(){
	// ���� ����� �մ��� �����Ѵ� >> Ȥ�� �մ԰� �����ڸ���?
	// >> yes >> �ý��� ��ǥ�ʱ�ȭ
	// >> No  >> �ýø� �������� bfs�� ���� >> ���� ����� �մ� ����
	// �մԱ��� �����ִ� ���ᰡ �Ǵ�? >> NO >> �Լ�����
	//						>> yes >> �ý��� ��ǥ �ʱ�ȭ && ���� ���� 
	
	// �մ��� �������� bfs ���� >> ���������� �� ���ᰡ �Ǵ�? >> NO >>����
	// >> yes >> �ý��� ��ǥ �ʱ�ȭ && ���� ���� 
	///////////////////////////////////////////////////////////////////
	// �ýú��� ��������� �ִܰŸ��� ���Ѵ� 
	queue<pair<int, int> > q1;
	int mmin=987987, del=0; // �մ԰��� �ּҰŸ�, �¿� �մ� �ε��� 
	int flag=0;
	for(int i=0; i<v1.size(); i++){
		if(v1[i].px==tx.x &&
			v1[i].py==tx.y){
			flag=1;
			tx.x=v1[i].px;
			tx.y=v1[i].py;	
			mmin=0;
			del=i;		
			break;
		}//if
	}//for-i
		
	if(flag==0){
		memset(wei, -1, sizeof(wei));		
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
		// ������ �մ��� �ִٸ� -1 ���� 
		for(int i=0; i<v1.size(); i++){
			// �մ��� ��ġ�߿��� ���� ���� �����ִٸ� Ż�� 
			int xx=v1[i].px;
			int yy=v1[i].py;			
			if(wei[xx][yy]==-1) return -1;
			v1[i].dis=wei[xx][yy];
		}//for-i
		/////////////////////////////////////////		
		// ���� ����� �մ���ǥ ���� 
		// 1) �Ÿ��� ����ª�� 2) �� �۰� 3) �� �۰� 
		sort(v1.begin(), v1.end(), comp);
		/////////////////////////////////////////
		// ���ᰡ �Ǵ�? 
		if(tx.f>=v1[0].dis){
			tx.f-=v1[0].dis;	
		}else{
			return -1;
		}//if 	
		
	}//if-1
	///////////////////////////////////////////////////////////	
//	printf("==========================================\n");
//	printf("�մ���ǥ::(%d, %d) || �ִܰŸ�:: %d\n", 
//						v1[del].px, v1[del].py, mmin);
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
	
	// �ýÿ��� ��ǥ���� �����°� �ִٸ�. 
	for(int i=0; i<v1.size(); i++){
		// �մ��� ��ġ�߿��� ���� ���� �����ִٸ� Ż�� 
		int xx=v1[i].gx;
		int yy=v1[i].gy;			
		if(wei[xx][yy]==-1) return -1;		
	}//for-i
				
	int ggx=v1[del].gx;
	int ggy=v1[del].gy;
//	printf("������ ��ǥ::(%d, %d) || �Ÿ�:: %d\n", 
//			v1[del].gx, v1[del].gy, wei[ggx][ggy]);
	if(tx.f>=wei[ggx][ggy]){
		tx.f=tx.f+wei[ggx][ggy];
		tx.x=ggx;
		tx.y=ggy;
		v1.erase(v1.begin()+del);
	}else{
		return -1;
	}//if 
//	printf("���� ���� :: %d\n", tx.f);
		
	return 0;
}//go

int main(){
	/////////////////////////////////////////////////////////////
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
	sort(v1.begin(), v1.end(), comp);
//	printf("=====================================\n");
//	for(int i=0; i<v1.size(); i++){
//		printf("%d %d %d %d\n", v1[i].px, v1[i].py, v1[i].gx, v1[i].gy);
//	}//for-i
	/////////////////////////////////////////////////////////////
	for(int i=0; i<m; i++){
//		printf("v1 size ::: %d \n", v1.size());
		if(v1.size()==0 || go()==-1){
			// ���� ��� �մ��� �¿��� ���ߴµ�
			// ������ -1 ��� 
			printf("-1\n");
			return 0;
		}//if
	}//for-i
	/////////////////////////////////////////////////////////////
	printf("%d\n", tx.f);
	
	return 0;
}//main

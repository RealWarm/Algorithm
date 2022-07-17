#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int grp[30][30];
int wei[30][30];
int n, dis, mnum; 	// �ʺ�, ���̵��Ÿ�, ���� ����. 
queue<pair<int , int> > q1;

struct pp{
	int lv=2;
	int exp=0;
	int x, y;
};

pp p1;

void calDis(int x1, int y1){	
	//�Ÿ��� ����Ͽ� �ѰŸ����� ���ϰ�
	//p1�� ��ǥ�� ���� ��ǥ�� �ٲ۴�. 
	dis+=wei[x1][y1];
	mnum--;
	grp[x1][y1]=0;
	p1.x=x1;
	p1.y=y1;
	p1.exp++;
	if(p1.lv==p1.exp){
		p1.exp=0;
		p1.lv++;
	}//if	
//	printf("��ǥ: (%d, %d), �Ÿ� : %d\n", p1.x, p1.y, dis);
}//calDis

void bfs(int x, int y){	
	wei[x][y]=0;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx = nwx+dx[k];
			int nty = nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
			if(wei[ntx][nty]==-1 && grp[ntx][nty]<=p1.lv){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}
		}//for-k		
	}//while
	
}//bfs

int main(){
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		p1.lv=2;
		p1.exp=0;
		dis=0;	
		mnum=0;			
		memset(grp, 0, sizeof(grp));		
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &grp[i][j]);
				if(grp[i][j]<=8 && grp[i][j]>=1){
					mnum++;//���� ����. 
				}else if(grp[i][j]==9){				
					grp[i][j]=0;
					p1.x=i;
					p1.y=j;				
				}//if 			
			}//for-j		
		}//for-i	
		
		
		while(1){
			memset(wei, -1, sizeof(wei));		
			bfs(p1.x, p1.y);					
			int min=99999999;
			int inx=0;
			int iny=0;
			if(mnum==0)	break;
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					if(wei[i][j]>0 			// �湮�� ���� 
						&& wei[i][j]<min 	// �Ÿ��� �ּҰ� 
						&& grp[i][j]<p1.lv 	// ������ ������ �۰� 
						&& grp[i][j]!=0){ 	// 						
						min=wei[i][j];
						inx=i;
						iny=j;
					}//if
				}//for-j
			}//for-i
			if(min==99999999) break;
			calDis(inx, iny);
		}//while
		
		printf("#%d %d\n",tt, dis);
	}//for-tt
		
	
	
	return 0;
}//main

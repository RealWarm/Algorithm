#include<iostream> 
#include<cstring>
#include<vector>
using namespace std;
int dx[]={0, 0,1,-1};		//��, ��, ��, �� 
int dy[]={1,-1,0, 0};
int grp[20][20];			//�����迭 
int temp[20][20];			//����迭 
int wei[20][20];			//�湮ó���迭 VISITED 
int n, k;					//��ũ��, �ִ� ������ �ִ�, ������� ���� 
int tmax, hmax, cmax;		//�Ѱ�쿡���� �ִ� ���Ӽ�, ��ü���� �ִ� ���Ӽ�. 

void dfs(int x, int y, int dir, int cnt){
	// ������ǥ X,Y, ���������� ����, 
	// cnt : �ش������� ���鼭�� Ŀ���
	// (�ش��������� Ŀ����� �ٸ��⶧���� ���������� ����)
	wei[x][y]=1;//�湮ó�� 
	for(int k=0; k<4; k++){
		int ntx = x+dx[k];
		int nty = y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || ntx>=n) continue;
		if(wei[ntx][nty]==0 && temp[x][y]>temp[ntx][nty]){
			//�湮���� �ʾҰ� && ���纸�� �۾ƾ��Ѵ�. 
			if(k!=dir){//���� �ٸ� �������� �����Ѵٸ�. 
						//���̴� ���� ������Ų��.
				printf("1.(%d, %d)���� (%d, %d)�� ������ dir:: %d���� k::%d�� �ٲ� ||| cnt ::  %d\n", x, y, ntx, nty, dir, k, cnt);
				dfs(ntx, nty, k, ++cnt);
				wei[ntx][nty]=0; //�湮�ߴ� ĭ�� üũ�� Ǭ��. >> �ٸ���쵵 �غ��� ���ؼ�
				if(cnt>tmax){
					tmax=cnt;
				} 
			}else{
				//������ ���ٸ� �׳� �����Ѵ�. 
				printf("2.(%d, %d)���� (%d, %d)�� ������ dir:: %d���� k::%d�� �ٲ� ||| cnt ::  %d\n", x, y, ntx, nty, dir, k, cnt);
				dfs(ntx, nty, k, cnt);	
				wei[ntx][nty]=0; //�湮�ߴ� ĭ�� üũ�� Ǭ��. >> �ٸ���쵵 �غ��� ���ؼ�
				if(cnt>tmax){
					tmax=cnt;
				} 							
			}//if
		}//if		
	}//for-k	
	
}//dfs


int main(){
	
	scanf("%d %d", &n, &k);
	vector<pair<int, int> > ttop;//���� �������� ������ 3 �̻� ttop 5���� 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &grp[i][j]);
			if(hmax<grp[i][j]){
				hmax=grp[i][j];				
				ttop.clear();
				ttop.push_back(make_pair(i,j));
			}else if(hmax==grp[i][j]){
				ttop.push_back(make_pair(i,j));
			}//if-1
		}//for-j
	}//for-i
	///////////////////////////////////////////////////////////////////////
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j]!=hmax){// ����Ⱑ �ƴϸ� 0 ���� k��ŭ ��ƺ���.
			 	for(int a=0; a<=k; a++){// 0���� k��ŭ ���� ��´�.	
			 		int result=grp[i][j]-a;
			 		if(result<0) break;// ���̰� 0�̸��̸� �ٸ����� ���ؼ� �õ��غ���.
					for(int b=0; b<ttop.size(); b++){//��� ����⿡�� Ž�縦 �����Ѵ�.  						
						memcpy(temp, grp, sizeof(grp));//�׽�Ʈ�� �迭 ����. 
						memset(wei, 0, sizeof(wei));//�湮�� üũ�ϱ� ���� �迭 �ʱ�ȭ 
						temp[i][j]-=a;// �ش����� 0~k ��ŭ ��ƺ���. 
						tmax=0; //�κ��ִ��� ���Ӽ� ����. 
						int xx=ttop[b].first;
						int yy=ttop[b].second;
						printf("(%d, %d)�� ��Ƽ�%d�� �����  (%d, %d)���� Ž������\n", i, j, temp[i][j], xx, yy);
						dfs(xx, yy, 1111111, 0);//������ ��ǥ, �����ϴ� ����, ����Ƚ��. 
						if(tmax>cmax){// Ž���ߴ� ��� ����߿��� �ִ밪�� �ִٸ� �ٲ۴�. 
							cmax=tmax;
						}//if	
						printf("tmax :: %d  ||  cmax :: %d\n", tmax, cmax);
					}//for-b					
				}//for-a
			}//if
		}//for-j
	}//for-i 
	
	printf("#%d\n", cmax-1);
		
	return 0;
}//main










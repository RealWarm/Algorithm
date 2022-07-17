#include<iostream> 
#include<cstring>
#include<vector>
using namespace std;
int dx[]={0, 0,1,-1};
int dy[]={1,-1,0, 0};//��, ��, ��, �� 
int grp[20][20];
int temp[20][20];
int wei[20][20];
int n, k, hmax; // ��ũ��, �ִ� ������ �ִ�, ������� ���� 
int tmax, cmax; // Ŀ���, �ִ� Ŀ��� 

void dfs(int ttt[20][20], int x, int y, int dir, int cnt){
//Ž���ҹ迭, ������ǥ X,Y, ���������� ����, 
// cnt : �ش������� ���鼭�� Ŀ���(�ش��������� Ŀ����� �ٸ��⶧���� ���������� ����) 
	wei[x][y]=1;//�������� �湮ó�� 
	for(int d=0; d<4; d++){// 4���� ��η� Ž���� �����غ��ڴ�. 
		int ntx=x+dx[d];
		int nty=y+dy[d];
		if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
		if(ttt[ntx][nty]<ttt[x][y] && wei[ntx][nty]==0){
			// �湮���� �ʾҰ� 
			// �ڱ⺸�� ���̰� ���� ���� ã�ư���. 
			if(dir == -1){
				// ���������� �����ϴ� ���⿡ ����  
				// Ŀ�긦 ���� �ʱ� ���ؼ� 
//				printf("(%d, %d)���� (%d, %d)�� ������ dir:: %d >>  d::%d  ���� >>  cnt ::  %d\n", x, y, ntx, nty, dir, d, cnt);				
			}else if(d!=dir){
				// ������ �ڽŰ� �ٸ��ٸ� cnt++ �Ѵ�. >> Ŀ���� ����. 
				dfs(ttt, ntx, nty, d, ++cnt);
				wei[x][y]=0;//�����Ҷ� üũ���� 	
				continue;			
//				printf("(%d, %d)���� (%d, %d)�� ������ dir:: %d >>  d::%d  ���� >>  cnt ::  %d\n", x, y, ntx, nty, dir, d, cnt);
			}
			dfs(ttt, ntx, nty, d, cnt);			
			wei[x][y]=0;//�����Ҷ� üũ���� 				
		}//if
	}//for-d
	
	if(cnt>tmax){		
		tmax=cnt;
	} 
}//finder

int main(){
		
	///////////////////////////////////////////////////////////////////////////
	// �׷��� ����
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		memset(grp, 0, sizeof(grp));
		hmax=0;//�ʱ�ȭ ��������.
		cmax=0;//�ʱ�ȭ ��������.
		scanf("%d %d", &n, &k);
		vector<pair<int, int> > ttop;//���� �������� ������ 3 �̻� ttop 5���� 
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &grp[i][j]);
			}//for-j
		}//for-i
		// ����� ���� ���� && �������� ��ǥ����		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(hmax<grp[i][j]){
					hmax=grp[i][j];				
					ttop.clear();
					ttop.push_back(make_pair(i,j));
				}else if(hmax==grp[i][j]){
					ttop.push_back(make_pair(i,j));
				}//if-1
			}//for-j
		}//for-i
		///////////////////////////////////////////////////////////////////////////
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(grp[i][j]!=hmax){// ����Ⱑ �ƴϸ� k��ŭ ��ƺ���.
				 	for(int a=0; a<=k; a++){//0���� k��ŭ ���� ��´�.	
				 		int result=grp[i][j]-a;
					 	if(result<0) break;//���̰� 0�̸��� �Ǿ�� �ȵȴ�.				 	
						for(int b=0; b<ttop.size(); b++){//��� ����⿡�� Ž�縦 �����Ѵ�. 
							memcpy(temp, grp, sizeof(grp));//�׽�Ʈ�� �迭 ����. 
							memset(wei, 0, sizeof(wei));//�湮�� üũ�ϱ� ���� �迭 �ʱ�ȭ 
							tmax=0;// Ŀ��� ī��Ʈ �ʱ�ȭ 
							temp[i][j]-=a;// �ش����� 0~k ��ŭ ��ƺ���. 
							int xx=ttop[b].first;
							int yy=ttop[b].second;
//							printf("(%d, %d)�� %d��ŭ ��Ұ� (%d, %d)���� Ž������\n", i, j, a, xx, yy);
							dfs(temp, xx, yy, -1, 0);
							if(tmax>cmax) cmax=tmax;
//							printf("tmax :: %d  ||  cmax :: %d\n", tmax, cmax);
						}//for-b					
					 }//for-a
				}//if 
			}//for-j
		}//for-i
		
		printf("#%d %d\n", tt, cmax);
	}//for-tt
	
	
	return 0;
}//main

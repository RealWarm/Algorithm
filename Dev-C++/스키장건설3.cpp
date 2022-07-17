#include<iostream> 
#include<vector> 
#include<cstring>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[20][20]; //�����迭 
int tmp[20][20]; //������ 
int wei[20][20]; //�����ΰŸ� 
int n, k;		 //���ΰ���, �ִ��� 
int mmax; //���� Ƚ���� �ִ밪 

void dfs(int x, int y, int dir, int cnt){
	// (xx, yy, -1, 0, grp[xx][yy]);
	// ��ǥ, ������ ����, ����Ƚ��, ���� ���� ����	
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;		
		if(tmp[ntx][nty]<tmp[x][y] && wei[ntx][nty]==-1){
			// ���� �����Ϸ��� ĭ�� ���̰� ������ ����
			if(dir==-1){
				wei[ntx][nty]=k+1;
				dfs(ntx, nty, k, cnt);
				wei[ntx][nty]=-1; // ��� ���� ���� !! 
			}else if(dir==k){
				wei[ntx][nty]=k+1;
				dfs(ntx, nty, k, cnt);
				wei[ntx][nty]=-1;
			}else if(dir!=k){
				wei[ntx][nty]=k+1;
				dfs(ntx, nty, k, cnt+1);
				wei[ntx][nty]=-1;
			}//if
		}//if
	}//for-k
	
	if(mmax<cnt){
		mmax=cnt;
	}//if
	
}//dfs


int main(){	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		memset(grp, 0, sizeof(grp));		
		int top=0; 	// ������ ���� 
		mmax=0;		// �ִ�� ���� Ƚ�� 
		vector<pair<int, int> > v1;//�������� ��ǥ���� ���Ѵ�. 
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf(" %d", &grp[i][j]);
				if(grp[i][j]>top){
					top=grp[i][j];
					v1.clear();
					v1.push_back(make_pair(i, j));
				}else if(grp[i][j]==top){
					v1.push_back(make_pair(i, j));
				}//if
			}//for-j
		}//for-i
		///////////////////////////////////////////////
		// ������ �ƴ� �ϳ��� ��ǥ�� 1���� K��ŭ ��ƺ���.
		// ���� 0�̻��̶�� dfsŽ���� �����Ѵ�. 
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				 if(grp[i][j]==top) continue;
				 // ���� ���� ��ǥ�� ������ǥ��� ���� ��ǥ�� 
				 /////////////////////////////////////////////
				 // �ش���ǥ�� 1~k��ŭ ��� ����. 
				 // ���� ��Ҵµ� ���̰� ������� �ٸ� ���� ��´�. 
				 for(int d=1; d<=k; d++){
				 	// ���� �����ϰ� >> ��´�. 
				 	memcpy(tmp, grp, sizeof(tmp));
				 	tmp[i][j]-=d;
				 	if(tmp[i][j]<0){
				 		// ���� ���̰� ������� �ٸ���ǥ�� �Ѿ��. 
				 		break;
					 }//if
					 for(int dt=0; dt<v1.size(); dt++){
					 	memset(wei, -1, sizeof(wei));
					 	int xx=v1[dt].first;
					 	int yy=v1[dt].second;
					 	wei[xx][yy]=0;
					 	dfs(xx, yy, -1, 0);
					 }//for-dt
					 
				 }//for-d			 
				 
			}//for-j
			
		}//for-i
		
		printf("#%d %d\n", tt, mmax);
	}//for-tt
		
	return 0;
}//main

// ������ ���� �� ���̸� �ִ� 1~K ��ŭ ���� �� �ִ� ���´�.
// (a, b)�� ���� �ߴٸ� �ٸ� ���� ���� �� ����. 
// ������ ���� ������ ã�ƾ��Ѵ� 
// >> ������� ���������� �����ؼ� ���� ���������� �����´�. 
// ���������� ���� ���̴� ���� �� ����. 
// ���� ������ ������ ����.
// ������ ���̴� 0���ν� 0�̸����δ� ���� �� ����. 

// �Է�
// N(����ũ��, 3<= n <=10), K(�ִ�ȣ ���� �� �ִ� ����, 1<= k <= 5) // 3<=������<=5 
// �׷���

// ���
// ���� ���� ������ ���� ���� Ƚ���� ����϶� 

// ����

// �Է�(���� ����� ���ϱ�) || ��±��� �׽�Ʈ �Ϸ� 
// ������ �ƴ� ���ǟ� ���� �����Ѵ� >> 1~k ��ŭ ��� ����.
// �� ���󿡼� ���� dfsŽ���� �����Ѵ�. >> ���̴� Ƚ���� �����. 
//  










//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%d ", grp[i][j]);			
//		}//for-j
//		printf("\n");
//	}//for-i
//	
//	printf("top :: %d\n", top);
//	for(int i=0; i<v1.size(); i++){
//		printf("(%d, %d), ", v1[i].first, v1[i].second);
//	}//for-i
 

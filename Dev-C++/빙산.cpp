#include<iostream>
#include<cstring>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[310][310]; // ���� �迭
int icb[310][310]; // ���� �ֺ��� �ٴ��� ��
int wei[310][310]; // ������ ���� >> ������ȣ ���̱� 
int n, m;

void cnt(int x, int y){
	int total=0;
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
		if(grp[ntx][nty]==0){
			total++;
		}//if
	}//for-k
	icb[x][y]=total;
}//cnt

void dfs(int x, int y, int cc){
	wei[x][y]=cc;
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
		if(grp[ntx][nty]!=0 && wei[ntx][nty]==0){
			dfs(ntx, nty, cc);
		}//if
	}//for-k
}//dfs

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %d", &grp[i][j]);
		}//for-j
	}//for-i
	// ����ó�� :: ó������ 2���� �̻��̾��ٸ� 
	int clr1=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grp[i][j]!=0 && wei[i][j]==0){
				dfs(i, j, ++clr1);
			}
		}//for-j
	}//for-i
	if(clr1>=2){
		printf("0\n");
		return 0;
	}//if
//	// ��� ���̶��
//	int sum=0;
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			sum+=grp[i][j];
//		}//for-j
//	}//for-i
//	if(sum==0){
//		printf("0");
//		return 0;
//	}	 
		
	///////////////////////////////////
	for(int time=1; ; time++){	
		memset(wei, 0, sizeof(wei));
		memset(icb, 0, sizeof(icb));
		// ���긶�� �ѷ��� �ٴ��� �� ���� 
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cnt(i, j);
			}//for-j
		}//for-i		
		///////////////////////////////////
		// ������� ����
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				grp[i][j]-=icb[i][j];
				if(grp[i][j]<0){
					grp[i][j]=0;
				}//if
			}//for-j
		}//for-i
		// ����ó�� :: ���� �ٴٶ�� 
		int sum=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				sum+=grp[i][j];
			}//for-j
		}//for-i
		if(sum==0){
			printf("0");
			return 0;
		}	 
		
		// ������ ���ܼ� ���� 
		int clr=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(grp[i][j]!=0 && wei[i][j]==0){
					dfs(i, j, ++clr);
				}
			}//for-j
		}//for-i
		if(clr>=2){
			printf("%d\n", time);
			break;
		}//if
		
		
	}//for-time
	///////////////////////////////////
	
	
	return 0;
}//main

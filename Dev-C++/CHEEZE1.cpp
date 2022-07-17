#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n, m; // ���� ����
int grp[110][110];
int wei[110][110];
int time, remain, tmp; // �� ��µ� �ɸ� �ð�, �� ��� ������ ���� ����
queue<pair<int, int> > q1;

void bfs(int x, int y){
	// ǥ���� ġ���ΰ��� ã��
	// ã�� ġ�� 0���� �ٲٱ� 
	tmp=0; 
	wei[x][y]=1;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx = q1.front().first;
		int nwy = q1.front().second;
		q1.pop();
		
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			if(wei[ntx][nty]==-1 && grp[ntx][nty]==0){
				wei[ntx][nty]=1;
				q1.push(make_pair(ntx, nty));
			}else if(wei[ntx][nty]==-1 && grp[ntx][nty]==1){
				wei[ntx][nty]=2;
				tmp++;
			}//if
		}//for-k
	}//while
		
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(wei[i][j]==2){
				grp[i][j]=0;
			}//if
		}//for-j
	}//for-i
//	printf("\n-----------\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
	
	if(tmp!=0){
		remain=tmp;
	}//if
	
}//bfs

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %d", &grp[i][j]);
		}//for-j
	}//for-i
	////////////////////////////////////////
	while(1){
		time++;
		memset(wei, -1, sizeof(wei));
		bfs(0, 0);
		if(tmp==0) break;
	}//while
	
	printf("%d\n%d\n", time-1, remain);
	
	return 0;
}//main


//printf("\n\n");
//for(int i=0; i<n; i++){
//	for(int j=0; j<m; j++){
//		printf("%d ", grp[i][j]);
//	}//for-j
//	printf("\n");
//}//for-i


// ����
// ǥ���� ġ� üũ�Ѵ� >> ���δ� >> ���������� 0�̴�? >> ����
//									>> �ƴ϶�� ���� ���� ����. 


// ��� 
// 1. ġ� ��� ��Ƽ� �������µ� �ɸ��� �ð��� ���
// 2. ��� ��� �ѽð� ���� ���� �ִ� ġ�������� ���� �ִ� ĭ�� ����. 






















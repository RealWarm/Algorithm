#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
using namespace std;
int dx[]={-1,1, 0,0};// �� �� �� �� 
int dy[]={ 0,0,-1,1};
queue<pair<int, int> > q1, q2; // �Ķ�, ����
int wei1[20][20][3];//�Ķ� ��ɰ���, �ɸ��� �ð�, ������ ��ȣ 
int wei2[20][20][3];//���� 
vector<string> grp;
int n, m;//���� ���� 
int rx, ry, bx, by; //R�� B�� ��ǥ���� 
int hx, hy;

void bfs1(int x, int y){ //�Ķ����� 
	q1.push(make_pair(x, y));
	wei1[x][y][0]=0; // ����� �� 
	wei1[x][y][1]=0; // ������ �Ÿ� 
	wei1[x][y][2]=99; // ������ ���� 
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx;
			int nty=nwy;
			int step=1; 
			while(1){
				ntx+=dx[k];
				nty+=dy[k];				
				if(grp[ntx][nty]=='#') break;
				if(wei1[ntx][nty][0]==-1){
					wei1[ntx][nty][0]=wei1[nwx][nwy][0]+1;
					wei1[ntx][nty][1]=wei1[nwx][nwy][1]+step;
					wei1[ntx][nty][2]=k;
					step++;
					q1.push(make_pair(ntx, nty));
				}
			}//while
		}//for-k		
	}//while	
}//bfs1

void bfs2(int x, int y){
	q2.push(make_pair(x, y));
	wei2[x][y][0]=0;
	wei2[x][y][1]=0;
	wei2[x][y][2]=99;
	while(!q2.empty()){
		int nwx=q2.front().first;
		int nwy=q2.front().second;
		q2.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx;
			int nty=nwy;
			int step=1;
			while(1){
				ntx+=dx[k];
				nty+=dy[k];
				if(grp[ntx][nty]=='#') break;
				if(wei2[ntx][nty][0]==-1 && 
				((wei1[ntx][nty][0]==-1)||
				(wei2[nwx][nwy][0]<wei1[ntx][nty][0] && wei2[ntx][ntx][1]<wei1[ntx][nty][1])
					)){
					//�湮���� �ʾҰ� 
					//B���� ���� �����δٸ�. 
					wei2[ntx][nty][0]=wei2[nwx][nwy][0]+1;
					wei2[ntx][nty][1]=wei2[nwx][nwy][1]+step;
					wei2[ntx][nty][2]=k;
					step++;
					q2.push(make_pair(ntx, nty));
				}//if
			}//while
		}//for-k		
	}//while
	
}//bfs2

int main(){
	memset(wei1, -1, sizeof(wei1));
	memset(wei2, -1, sizeof(wei2));
	scanf("%d %d", &n, &m);
	grp.resize(n);
	for(int i=0; i<n; i++){
		cin >> grp[i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grp[i][j]=='R'){
				rx=i;
				ry=j;
			}else if(grp[i][j]=='B'){
				bx=i;
				by=j;
			}else  if(grp[i][j]=='O'){
				hx=i;
				hy=j;
			}//if
		}//for-j
	}//for-i
	
	printf("R::(%d, %d) || B::(%d, %d) || H::(%d, %d)\n", rx, ry, bx, by, hx, hy);
	bfs1(bx, by);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%2d ", wei1[i][j][0]);
		}//for-j
		printf("\n");
	}//for-i
	printf("=============================================\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%2d ", wei1[i][j][1]);
		}//for-j
		printf("\n");
	}//for-i
	printf("=============================================\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%2d ", wei1[i][j][2]);
		}//for-j
		printf("\n");
	}//for-i
	printf("=============================================\n");	
	printf("\n\n\n");
	
	bfs2(rx, ry);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%2d ", wei2[i][j][0]);
		}//for-j
		printf("\n");
	}//for-i
	printf("=============================================\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%2d ", wei2[i][j][1]);
		}//for-j
		printf("\n");
	}//for-i
	printf("=============================================\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%2d ", wei2[i][j][2]);
		}//for-j
		printf("\n");
	}//for-i
	printf("=============================================\n");
	if(wei1[hx][hy][1]>wei2[hx][hy][1]){
		//�������� �Ķ����� ���� ���ۿ� �����ߴٸ�.
		if(wei2[hx][hy][0]<=10){	
			printf("good shot!!\n");
			printf("%d\n", wei2[hx][hy][0]);
		}else if(wei2[hx][hy][0]>10){
			printf("bigger than 10\n");
			printf("-1\n");
		}
	}else if(wei1[hx][hy][1]>=0 &&
	 			wei2[hx][hy][1]>=0 &&
				 wei1[hx][hy][1]<wei2[hx][hy][1]){
		printf("blue in hole\n");
		printf("-1\n");
	}else if(wei1[hx][hy][1]!=-1&&wei1[hx][hy][1]==wei2[hx][hy][1]){
		if(wei2[hx][hy][0]>10){
			printf("bigger than 10\n");
			printf("-1\n");
		}else if(wei1[hx][hy][2]>wei2[hx][hy][2]){
			printf("%d\n", wei2[hx][hy][0]);
		}else if(wei1[hx][hy][2]<=wei2[hx][hy][2]){
			printf("-1\n");
		}//if-2
	}//if-1
			
	
	return 0;
}//main

























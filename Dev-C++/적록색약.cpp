#include<iostream>
#include<cstring>
#include<string> 
#include<vector>
#include<queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp2[110][110];	//	���ϻ����� ���� �׷��� 
int wei[110][110];	// 	�湮 ���θ� üũ 
vector<string> grp;	// 	���� �׷��� 
int n;				// 	�׷����� ũ�� 

void bfs1(int x, int y, char dd, int cc){
	//���� ��ǥ, ������ ����, �׷��ȣ 
//	printf("x :: %d || y:: %d \n", x, y) ;
	queue<pair<int, int> > q1;
	q1.push(make_pair(x, y));
	wei[x][y]=cc;
		
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx = nwx + dx[k];
			int nty = nwy + dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n){				
//				printf("in :: %d %d \n", ntx, nty);
				continue;
			} 
//			printf("grp :: %c || dd :: %c \n", grp[ntx][nty], dd);
//			printf("ininin\n");
			if(wei[ntx][nty]==0 && grp[ntx][nty]==dd){				
				wei[ntx][nty]=cc;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while		
}//bfs1

void bfs2(int x, int y, int dd, int cc){
//	printf("x :: %d || y:: %d \n", x, y) ;
	queue<pair<int, int> > q1;
	q1.push(make_pair(x, y));
	wei[x][y]=cc;
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
			if(wei[ntx][nty]==0 && grp2[ntx][nty]==dd){
//				printf("ininin\n");
				wei[ntx][nty]=cc;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while
	
}//bfs2

int main(){
	scanf("%d", &n);
	grp.resize(n);
	for(int i=0; i<n; i++){
		cin >> grp[i];
	}//for-i
	////////////////////////////////////////
	//���ϻ��� �׷��� ����� 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j]=='R' || grp[i][j]=='G'){
				grp2[i][j]=1;
			}else{
				grp2[i][j]=2;
			}
		}//for-j
	}//for-i	
	////////////////////////////////////////
	//���ϻ����� �ƴѰ�� 
	memset(wei, 0, sizeof(wei));
	int clr=0;//������ ���� 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(wei[i][j]==0){
				bfs1(i, j, grp[i][j], ++clr);
			}//if
		}//for-j
	}//for-i
//	printf("%d\n", clr);
	////////////////////////////////////////
	//���ϻ����� ��� 
	memset(wei, 0, sizeof(wei));
	int cc=0;//������ ���� 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(wei[i][j]==0){
				bfs2(i, j, grp2[i][j], ++cc);
			}//if
		}//for-j
	}//for-i
//	printf("%d\n", cc);
//	/////////////////////////////////////////
	printf("%d %d\n", clr, cc);	
	
	return 0;
}//main








//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%d ", grp2[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i

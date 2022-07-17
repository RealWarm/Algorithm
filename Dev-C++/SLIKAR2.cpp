#include<iostream> 
#include<cstring>
#include<string>
#include<queue>
#include<vector>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pair<int, int> > q1;
vector<string> grp;
int wei1[60][60];// 물이 퍼지는 상황 
int wei2[60][60];// 비버가 움직이는 상황
int r, c;
int ddx, ddy, sx, sy;//비버굴의 좌표, 고슴도치의 좌표

int main(){
	memset(wei1, -1, sizeof(wei1));
	memset(wei2, -1, sizeof(wei2));
	scanf("%d %d", &r, &c);
	grp.resize(r);
	for(int i=0; i<r; i++){
		cin >> grp[i];
	}//for-i
	/////////////////////////////////////////////////////////////////
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(grp[i][j]=='D'){
				ddx=i;
				ddy=j;
			}else if(grp[i][j]=='S'){
				sx=i;
				sy=j;
				wei2[i][j]=0;
			}else if(grp[i][j]=='*'){
				q1.push(make_pair(i, j));
				wei1[i][j]=0;
			}//if 
		}//for-j
	}//for-i
	/////////////////////////////////////////////////////////////////
	// 물을 퍼뜨린다.
	// 돌, 비버의 굴을 통과할 수 없다. 
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=r || nty>=c) continue;
			if(wei1[ntx][nty]==-1 &&
				grp[ntx][nty]!='X' &&
				grp[ntx][nty]!='D' ){
				wei1[ntx][nty]=wei1[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k		
	}//while
	
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			printf("%2d ", wei1[i][j]);
//		}
//		printf("\n");
//	}
//	printf("=========================================\n");
	/////////////////////////////////////////////////////////////////
	// 고슴도치를 퍼뜨린다.
	// 돌을 통과할수 없다.
	// 물이 차있는 구역은 이동할 수 없다.
	// 물이 찰 예정인 칸으로 이동할 수 없다
	q1.push(make_pair(sx, sy));
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=r || nty>=c) continue;
			if(wei2[ntx][nty]==-1 &&
				grp[ntx][nty]!='X' &&
				(wei1[ntx][nty]>wei2[nwx][nwy]+1 || 
//					grp[ntx][nty]=='D'
					wei1[ntx][nty]==-1)){
				wei2[ntx][nty]=wei2[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
		
	}//while
	
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			printf("%2d ", wei2[i][j]);
//		}
//		printf("\n");
//	}
//	printf("=========================================\n");
	/////////////////////////////////////////////////////////////////
	if(wei2[ddx][ddy]==-1){
		printf("KAKTUS\n");
	}else{
		printf("%d\n", wei2[ddx][ddy]);
	}
	
	return 0;
}//main

//R행 C열로 이루어져 있다. 
//빈곳 : '.'
//물 :'*', 
//돌:'X',
//비버의 굴: 'D', 
//고슴도치:'S'
//물과 고슴도치는 돌을 통과할 수 없다. 
//또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 
//물도 비버의 소굴로 이동할 수 없다.
//고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 


// 입력 >> 물을 퍼뜨리기 >> 고슴도치 퍼뜨리기 >> 갔는 지 확인하기.

// 입력 >>  



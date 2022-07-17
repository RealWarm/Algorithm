#include<iostream>
#include<cstring> 
#include<queue> 
#include<vector>
#include<string>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[20][20];
int wei[20][20];
int n, m;
queue<pair<int, int> > q1, q2; //파랑, 빨강 
int bx, by, rx, ry;
int gx, gy; 

int main(){
	memset(wei, -1, sizeof(wei));
	scanf("%d %d", &n, &m);	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int nn;
			char ch; scanf(" %c", &ch);// 이거 주의하자. 
			if(ch=='.'){
				nn=0;
			}else if(ch=='#'){
				nn=1;
			}else if(ch=='O'){
				nn=0;
				gx=i;
				gy=j;
			}else if(ch=='R'){
				nn=0;
				rx=i;
				ry=j;				
			}else if(ch=='B'){
				nn=0;
				bx=i;
				by=j;				
			}//if
			grp[i][j]=nn;			
		}//for-a
	}//for-i
	/////////////////////////////////////////////////////////////////
	// 파랑구슬 움직이기 
	// 벽을 만날때까지 전진시킨다.
	//  
	wei[bx][by]=0;
	q1.push(make_pair(bx, by));
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx= nwx;
			int nty= nwy;
			while(1){
				ntx+=dx[k];
				nty+=dy[k];
				
				if(ntx<1 || nty<1 || ntx>n-1 || nty>m-1){
					printf("inhere range\n");
					if(ntx-dx[k] != nwx || nty-dy[k] != nwy){
						// 바로 직전이 출발점이 아니었다면 
						printf("invoked\n");
						q1.push(make_pair(ntx-dx[k], nty-dy[k]));
					}
					break;
				}//if
				
				if(wei[ntx][nty]==-1 && grp[ntx][nty]==0){
					wei[ntx][nty]=wei[nwx][nwy]+1;					
				}else if(grp[ntx][nty]==1){
					printf("inhere\n");
					if(ntx-dx[k]!=nwx || nty-dy[k]!=nwy){
						printf("invoked\n");
						q1.push(make_pair(ntx-dx[k], nty-dy[k]));
					}
					break;
				}//if
				
			}//while
			
//			if(ntx-dx[k]!=nwx && nty-dy[k]!=nwy){
//				printf("invoked\n");
//				q1.push(make_pair(ntx-dx[k], nty-dy[k]));
//			}
			
		}//for-k
	}//while
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%2d ", wei[i][j]);
		}//for-j
		printf("\n");
	}//for-i
	/////////////////////////////////////////////////////////////////
//	// 빨강구슬 움직이기 
//	wei[rx][ry]=0;
//	q1.push(make_pair(rx, ry));
//	while(!q1.empty()){
//		int nwx=q1.front().first;
//		int nwy=q1.front().second;
//		q1.pop();
//		for(int k=0; k<4; k++){
//			int ntx = nwx+dx[k];
//			int nty = nwy+dy[k];
//			if(ntx<1 || nty<1 || ntx>n-1 || nty>m-1) break;
//			if(wei[ntx][nty]>wei[nwx][nwy] && grp[ntx][nty]==0){
//				wei[ntx][nty]=wei[nwx][nwy]+1;
//				q1.push(make_pair(ntx, nty));
//			}//if
//		}//for-k
//	}//while
//	
//
//	/////////////////////////////////////////////////////////////////	
//	if(wei[gx][gy]<=10 && wei[gx][gy]!=-1){
//		printf("%d\n", wei[gx][gy]);
//	}else if(wei[gx][gy]>10 || wei[gx][gy]==-1){
//		printf("-1\n");
//	}//if

	return 0;
}//main



//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", grp[i][j]);
//		}//for-a
//		printf("\n");
//	}//for-i

// 출력
// 보드의 상태가 주어졌을 때, 
// 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 
// 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력


// 입력 n, m
// '.'은 빈 칸을 의미하고, 
// '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 
// 'O'는 구멍의 위치를 의미한다. 
// 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬 

// 그래프 입력 
//	for(int i=0; i<n; i++){
//		cout << grp[i] << endl;
//	}//for-i

// 문제 설계 bfs 
// 입력 >> 
// 파란구슬 퍼뜨리기 >> 빨간구슬 퍼뜨리기 >> 목표지점의 값을 비교하기 



















	

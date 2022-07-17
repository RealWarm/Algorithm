#include<iostream>
#include<queue>
using namespace std;
struct robot{
	int x;
	int y;
	int dir;
};
int dx[]={0,0, 0,1,-1};//동서남북 
int dy[]={0,1,-1,0, 0};
int grp[110][110];
int wei[110][110];
int n, m;	// 세로 가로
int tx, ty, tdir;	// 목적지의 좌표, 방향 
queue<robot> q1

robot make_b(int x, int y, int dir){
	robot rr;
	rr.x=x;
	rr.y=y;
	rr.dir=dir
	return rr;	
}//make_b

int main(){
	scanf("%d %d", &n, &m);//세로 가로
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %d", &grp[i][j]);
		}//for-j
	}//for-i
	robot r1;
	scanf("%d %d %d", &r1.x, &r1.y, &r1.dir);
	scanf("%d %d %d", &tx, &ty, &tdir);
	////////////////////////////////////////////////////////////
	q1.push() 
	
	////////////////////////////////////////////////////////////
	
	return 0;
}//main

















//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
//	printf("%d %d %d\n", r1.x, r1.y, r1.dir);
//	printf("%d %d %d\n", tx, ty, tdir);

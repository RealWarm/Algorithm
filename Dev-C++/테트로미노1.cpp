#include<iostream> 
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[510][510];
int n, m, mmax=-987987; // 세로, 가로, 최댓값

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %d", &grp[i][j]);
		}//for-j
	}//for-i
	////////////////////////////////////////////////
	
	
	return 0;
}//main

// dfs 탐색하면서 길이가 4이면 비교
// ㅗ는 따로 해준다. 

#include<iostream> 
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[510][510];
int n, m, mmax=-987987; // ����, ����, �ִ�

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

// dfs Ž���ϸ鼭 ���̰� 4�̸� ��
// �Ǵ� ���� ���ش�. 

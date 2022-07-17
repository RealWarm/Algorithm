#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=10;

//Q1. ���� x, y�� ������ �Ǿ� �ִ°�? 
int connected(int grp[MAX][MAX], int x, int y){
	return grp[x][y]==1 ? 1 : 0;
}//connected

//Q2. ���� x�� ������ �Ǿ��ִ� ��� ������ ����϶�. 
void showAll(int grp[MAX][MAX], int x){
	//n���� ������ ���� �׷������� x�� ����Ǿ� �ִ� ��� ������ ����ϴ� �Լ� 
	for(int i=0; i<MAX-1; i++){
		if(grp[i][x]==1) printf("%d ", i);		 
	}
	printf("\n");	
}//showAll

int main(){
	
	int grp[MAX][MAX]={0};
	int n, m; scanf("%d %d", &n, &m);	
	
	for(int i=0; i<m; i++){
		int a, b; scanf("%d %d", &a, &b);
		grp[a][b]=1;
		grp[b][a]=1;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			printf("%d", grp[i][j]);
		}
		printf("\n");
	}
	
	printf("%d\n", connected(grp,1,2));
	printf("%d\n", connected(grp,1,5));
	printf("%d\n", connected(grp,3,5));
	
	showAll(grp, 2);
	showAll(grp, 4);
	
	return 0;
}

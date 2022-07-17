#include<iostream>
#include<cstring>
using namespace std;
int dx[] = { -1, 0, 1, 0 }; //╩С,©Л,го,аб 
int dy[] = { 0, 1, 0,-1 };
int grp[10][10];
int n, m, k, t, cnt8;

int dir[][4] = {
	{0,0,0,0},
	{1,0,0,0},
	{1,0,1,0},
	{1,1,0,0},
	{1,1,0,1},
	{1,1,1,1}
};

void fill(int x1, int y1, int num, int tr) {
	
	int darr[4];
	memcpy(darr, dir[num], sizeof(darr));		
	
//	printf("00000000000darr :: ");
//	for(int i=0; i<4; i++){
//		printf("%d ", darr[i]);
//	}
//	printf("\n");
	
	for(int a=0; a<tr; a++){	
		int le=darr[3];
		for(int i=3; i>=1; i--){
			darr[i]=darr[i-1];
		}
		darr[0]=le;
	}//while
	
//	printf("111111darr :: ");
//	for(int i=0; i<4; i++){
//		printf("%d ", darr[i]);
//	}
//	printf("\n");
	
	for (int k = 0; k < 4; k++) {
		if (darr[k] == 1) {
			int ntx = x1;
			int nty = y1;
			while (1) {
				ntx += dx[k];
				nty += dy[k];
				if (ntx < 0 || nty < 0 || ntx >= n || nty >= m) break;
				if (grp[ntx][nty] == 6) break;
//				if (grp[ntx][nty] >= 1 && grp[ntx][nty] <= 5) continue;
				if (grp[ntx][nty] == 0) {
					grp[ntx][nty] = 8;
				}//if

			}//while
		}//if
	}//for-k

}//fill

int main() {
	
	scanf("%d %d %d %d", &n, &m, &k, &t);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	

	int gnum=0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grp[i][j] >= 1 && grp[i][j] <= 5) {
				gnum++;
				if(k==gnum)	fill(i, j, grp[i][j], t);
			}//if
		}//for-j
	}//for-i
		
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(grp[i][j]==8) cnt8++;
		}//for-j		
	}//for-i
	
	printf("%d", cnt8);

	return 0;
}//main

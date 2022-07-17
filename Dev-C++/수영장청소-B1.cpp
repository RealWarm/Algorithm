#include<iostream>
using namespace std;
int dx[] = { -1, 0, 1, 0 }; //╩С,©Л,го,аб 
int dy[] = { 0, 1, 0,-1 };
int grp[10][10];
int n, m;

int dir[][4] = {
	{0,0,0,0},
	{1,0,0,0},
	{1,0,1,0},
	{1,1,0,0},
	{1,1,0,1},
	{1,1,1,1}
};

void fill(int x1, int y1, int num) {
	
	for (int k = 0; k < 4; k++) {
		if (dir[num][k] == 1) {
			int ntx = x1;
			int nty = y1;
			while (1) {
				ntx += dx[k];
				nty += dy[k];
				if (ntx < 0 || nty < 0 || ntx >= n || nty >= m) break;
				if (grp[ntx][nty] == 6) break;
				if (grp[ntx][nty] >= 1 && grp[ntx][nty] <= 5) continue;
				if (grp[ntx][nty] == 0) {
					grp[ntx][nty] = 8;
				}//if

			}//while
		}//if
	}//for-k

}//fill

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grp[i][j] >= 1 && grp[i][j] <= 5) {
				fill(i, j, grp[i][j]);
			}//if
		}//for-j
	}//for-i

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", grp[i][j]);
		}//for-j
		printf("\n");
	}//for-i

	return 0;
}//main

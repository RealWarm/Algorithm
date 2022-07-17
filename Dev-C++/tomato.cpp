#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
using namespace std;
int grp[110][110][110];
int wei[110][110][110];
int dx[] = { 0,0,1,-1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
queue<tuple<int, int, int> > q1;
int n, m, h;

int main() {
	memset(wei, -1, sizeof(wei));
	scanf("%d %d %d", &m, &n, &h);
	for (int z = 0; z < h; z++){
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &grp[i][j][z]);
				if (grp[i][j][z] == 1) {
					q1.push(make_tuple(i, j, z));
					wei[i][j][z] = 0;
				}
			}//for-j
		}//for-i
	}//for-z

	while (!q1.empty()) {
		int nwx, nwy, nwz;
		tie(nwx, nwy, nwz) = q1.front();
		q1.pop();
		for (int k = 0; k < 6; k++) {
			int ntx = nwx + dx[k];
			int nty = nwy + dy[k];
			int ntz = nwz + dz[k];
			if (ntx < 0 || ntx >= n || nty < 0 || nty >= m || ntz < 0 || ntz >= h) continue;
			if (grp[ntx][nty][ntz] == 0 && wei[ntx][nty][ntz] == -1) {
				wei[ntx][nty][ntz] = wei[nwx][nwy][nwz] + 1;				
				q1.push(make_tuple(ntx, nty, ntz));
			}//if-1
		}//for-k
	}//while
		
	int max = -1;
	for (int z = 0; z < h; z++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grp[i][j][z] == 0 && wei[i][j][z] == -1) {
					printf("%d", -1);
					return 0;
				}else if (wei[i][j][z] > max) {
					max = wei[i][j][z];
				}
			}//for-j			
		}//for-i		
	}//for-z	
	printf("%d", max);

	return 0;
}//main



//3 3 3
//1 1 0
//1 1 1
//1 1 1
//
//1 1 1
//1 0 1
//1 1 1
//
//1 1 1
//1 1 1 
//1 1 1
////
////
//3 3 3
//0 0 0
//0 0 0
//0 0 0
//0 0 0
//0 0 0
//0 0 0
//0 0 0



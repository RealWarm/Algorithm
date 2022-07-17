#include<cstdio>
#include<tuple>
#include<queue>
#include<cstring> 
using namespace std;
int grp[1000][1000];
int dist[1000][1000][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main() {

	int  n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &grp[i][j]);
		}
	}

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(n-1, 0, 0));
	memset(dist, -1, sizeof(dist));
	dist[n-1][0][0] = 0;

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ntx = x + dx[k];
			int nty = y + dy[k];

			if (ntx < 0 || ntx >= n || nty < 0 || nty >= m) continue;
			if (grp[ntx][nty] == 0 && dist[ntx][nty][z] == -1) {
				dist[ntx][nty][z] = dist[x][y][z] + 1;
				q.push(make_tuple(ntx, nty, z));
			}
			if (z == 0 && dist[ntx][nty][z + 1] == -1 && grp[ntx][nty] == 1) {
				dist[ntx][nty][z + 1] = dist[x][y][z] + 1;
				q.push(make_tuple(ntx, nty, z + 1));
			}

		}//for-k

	}//while
	
	if (dist[0][m - 1][0] != 0 && dist[0][m - 1][1] != 0) {
		printf("%d", min(dist[0][m - 1][0], dist[0][m - 1][1]));
	}
	else if (dist[0][m - 1][0] != 0) {
		printf("%d", dist[0][m - 1][0]);
	}
	else if (dist[0][m - 1][1] != 0) {
		printf("%d", dist[0][m - 1][1]);
	}else {
		printf("%d", -1);
	}

	return 0;
}//main

#include<iostream>
#include<queue>
using namespace std;
struct robot {
    int x, y, d;
};
int n, m;
int sx, sy, sd;
int ex, ey, ed;
int a[100][100];
int dist[100][100][4];
int dx[] = {0,  0, 1, -1};
int dy[] = {1, -1, 0,  0};

void bfs() {
    queue<robot> q;
    q.push({sx-1, sy-1, sd-1});
    while (!q.empty()) {
        int x = q.front().x; 
		int y = q.front().y; 
		int d = q.front().d; 
		q.pop();
        if (x == ex-1 && y == ey-1 && d == ed-1) {
            printf("%d\n", dist[x][y][d]);
            return;
        }//if
        for (int i=1; i<=3; i++) {   
            int nx = x+dx[d]*i;
			int ny = y+dy[d]*i;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;
            if (a[nx][ny]) break;           // Cannot pass the wall.
            if (dist[nx][ny][d]) continue;  // Already visited.
            q.push({nx, ny, d});
            dist[nx][ny][d] = dist[x][y][d]+1;
        }//for-i
        for (int i=0; i<4; i++) {
             if (i == d) continue;  // Same direction.
             int k = (i+d)%4 == 1 ? 2 : 1;  // Check rotation. 180 degree (+2), 90 degree (+1)
             if (dist[x][y][i]) continue;   // Already visited.
             q.push({x, y, i});
             dist[x][y][i] = dist[x][y][d]+k;
        }//for-i
    }//while
}//bfs

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &a[i][j]);
        }//for-j
    }//for-i
    scanf("%d %d %d", &sx, &sy, &sd);
    scanf("%d %d %d", &ex, &ey, &ed);
    bfs();
    return 0;
}//main

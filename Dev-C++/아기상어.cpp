#include<iostream>
#include<cstring> 
#include<queue>
#include<cmath>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int grp[30][30];
int wei[30][30];
queue<pair<int, int> > q1;
int mindis;
int n, step;
struct sh {
	int x;
	int y;
	int exp;
	int lv;
};
sh s1;

void bfs() {
	wei[s1.x][s1.y] = 0;
	q1.push(make_pair(s1.x, s1.y));

	while (!q1.empty()) {
		int nwx = q1.front().first;
		int nwy = q1.front().second;
		q1.pop();
		for (int k = 0; k < 4; k++) {
			int ntx = nwx + dx[k];
			int nty = nwy + dy[k];
			if (ntx < 0 || nty < 0 || ntx >= n || nty >= n) continue;
			//방문하지 않았고 && 물고기의 레벨이 자신과 같거나 작다면
			if (wei[ntx][nty] == -1 && grp[ntx][nty] <= s1.lv) {
				wei[ntx][nty] = wei[nwx][nwy] + 1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while
}//bfs


void grown(int x, int y) {
	// 상어의 경험지를 증가시키고 >> 경험치와 레벨이 같다면 >> 레벨업 시킴
	// 상어의 좌표를 변경한다.
	s1.exp++;
	if (s1.lv == s1.exp) { 
		// 레벨을 증가 시키고
		// 경혐치를 0으로 다시만든다.
		s1.lv++; 
		s1.exp = 0;
	}//if
	s1.x = x;
	s1.y = y;
}//grown

int main() {

		step = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &grp[i][j]);
				if (grp[i][j] == 9) {
					s1.x = i;
					s1.y = j;
					s1.lv = 2;
					s1.exp = 0;
					grp[i][j] = 0;
				}
			}//for-j
		}//for-i

		while (1) {
			memset(wei, -1, sizeof(wei));
			mindis = 987987;
			int inx, iny;
			bfs();
			// 먹을수 있는 물고기(자신의 레벨보다 낮은 물고기)
			// 방문을 했고 && 거리가 여태까지의 거리중에서 가장작다면.
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (grp[i][j] > 0 && grp[i][j] < s1.lv && 
							wei[i][j]>0 && wei[i][j] < mindis) {
						mindis = wei[i][j];
						inx = i;
						iny = j;
					}//if
				}//for-j
			}//for-i

			if (mindis == 987987) break; //잡아 먹을 물고기가 없다면
			else {
				//최단거리의 물고기를 잡았다면.
				//물고기를 먹고 >> 걸음 수 더하고
				//상어 경험치 증가시키기 >> 레벨업 시키기 >> 상어 좌표바꾸기
				grp[inx][iny] = 0;
				step += mindis;
				grown(inx, iny);
			}
		}//while

		printf("%d\n", step);

	return 0;
}//main

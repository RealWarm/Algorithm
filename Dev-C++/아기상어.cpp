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
			//�湮���� �ʾҰ� && ������� ������ �ڽŰ� ���ų� �۴ٸ�
			if (wei[ntx][nty] == -1 && grp[ntx][nty] <= s1.lv) {
				wei[ntx][nty] = wei[nwx][nwy] + 1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while
}//bfs


void grown(int x, int y) {
	// ����� �������� ������Ű�� >> ����ġ�� ������ ���ٸ� >> ������ ��Ŵ
	// ����� ��ǥ�� �����Ѵ�.
	s1.exp++;
	if (s1.lv == s1.exp) { 
		// ������ ���� ��Ű��
		// ����ġ�� 0���� �ٽø����.
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
			// ������ �ִ� �����(�ڽ��� �������� ���� �����)
			// �湮�� �߰� && �Ÿ��� ���±����� �Ÿ��߿��� �����۴ٸ�.
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

			if (mindis == 987987) break; //��� ���� ����Ⱑ ���ٸ�
			else {
				//�ִܰŸ��� ����⸦ ��Ҵٸ�.
				//����⸦ �԰� >> ���� �� ���ϰ�
				//��� ����ġ ������Ű�� >> ������ ��Ű�� >> ��� ��ǥ�ٲٱ�
				grp[inx][iny] = 0;
				step += mindis;
				grown(inx, iny);
			}
		}//while

		printf("%d\n", step);

	return 0;
}//main

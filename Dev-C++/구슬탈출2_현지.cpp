#include <cstdio>
struct dot {
	int i;
	int j;
};
int n, m, result = 9879779;
int ei, ej;
int map[15][15];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
int cdi[4] = { 1,-1,0,0 };
int cdj[4] = { 0,0,1,-1 };
dot tilt(dot prev, int dir) {
	int r = prev.i;
	int c = prev.j;
	while (1) {
		int ni = r + di[dir];
		int nj = c + dj[dir];
		if (map[ni][nj] == 1) break;
		r = ni;
		c = nj;
		if (map[ni][nj] == -1) break;
	}
	prev.i = r;
	prev.j = c;
	return prev;
}
int getdistance(dot prev, dot next) {
	int idif = prev.i - next.i;
	int jdif = prev.j - next.j;
	if (idif < 0) idif *= -1;
	if (jdif < 0) jdif *= -1;
	return idif + jdif;
}
void getResult(int depth, dot pred, dot pblue) {
	if (depth >= 10 || depth >= result) return;
	for (int i = 0; i < 4; i++) {
		dot nred = tilt(pred,i);
		dot nblue = tilt(pblue,i);
		bool rhole = false, bhole = false;
		if (pred.i == nred.i && pred.j == nred.j && pblue.i == nblue.i && pblue.j == nblue.j) continue;
		if (nred.i == ei && nred.j == ej) rhole = true;
		if (nblue.i == ei && nblue.j == ej) bhole = true;
		if (bhole) continue;
		else if (rhole) {
			if (result > depth + 1) result = depth + 1;
			return;
		}
		if (nred.i == nblue.i && nred.j == nblue.j) {
			int rdist = getdistance(pred, nred);
			int bdist = getdistance(pblue, nblue);
			if (rdist < bdist) {//blue 이동
				nblue.i += cdi[i];
				nblue.j += cdj[i];
			}
			else {//red 이동
				nred.i += cdi[i];
				nred.j += cdj[i];
			}
		}
		getResult(depth + 1, nred, nblue);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	dot red, blue;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp;
			scanf(" %c", &tmp);
			if (tmp == '#') map[i][j] = 1;
			else if (tmp == 'O') {
				map[i][j] = -1;
				ei = i;
				ej = j;
			}
			else {
				map[i][j] = 0;
				if (tmp == 'R') {
					red.i = i;
					red.j = j;
				}
				else if (tmp == 'B') {
					blue.i = i;
					blue.j = j;
				}
			}
		}
	}
	getResult(0, red, blue);
	if (result == 9879779) printf("-1");
	else printf("%d", result);
	return 0;
}

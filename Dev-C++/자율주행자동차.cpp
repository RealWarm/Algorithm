#include<iostream>
#include<cstring>
#include<vector> 
#include<cmath>
#include<queue>
using namespace std;
int dx[] = { 1,-1, 0,0 }; // �� �� �� �� 
int dy[] = { 0, 0,-1,1 };
struct car {
	int x;
	int y;
	int r;
	int is = 0;//������ �⵹�ߴ�?.
};
vector<car> c1;
int s, n = 2000, cnt;

void forward() {
	for (int i = 0; i < c1.size(); i++) {
		// ��� �ڵ����� ������ 1��ŭ ������Ų��.
		c1[i].x += dx[c1[i].r];
		c1[i].y += dy[c1[i].r];
		//������ �ߴµ� ������ �Ѿ�ٸ� �����Ѵ�.		
		if (c1[i].x < -1000 || c1[i].x > 1000 || c1[i].y < -1000 || c1[i].y > 1000) {
			/*printf("����(%d %d)���� ���� \n",
					c1[i].y - 1000, c1[i].x - 1000);*/
			c1.erase(c1.begin() + i);
			i--;//����!!! 
		}//if
	}//for-i

	//printf("-----------------------------------------\n");
	//for (int i = 0; i < c1.size(); i++) {
	//	printf("�̵� �� :: (%2d %2d) || r :: %d\n", c1[i].y - 1000, c1[i].x - 1000, c1[i].r);
	//}//for-i
}//forward

void clash1() {

	// ������ ��ǥ���� �浹�� ���� ����
	for (int i = 0; i < c1.size(); i++) {
		for (int j = i + 1; j < c1.size(); j++) {
			if (c1[i].x == c1[j].x &&
				c1[i].y == c1[j].y) {
				if (c1[i].is == 0 && c1[j].is == 0) {
					//printf("clash1 :: �����浹\n");
					/*printf("clash1 :: (%d %d)���� �����浹\n",
						c1[i].y - 1000, c1[i].x - 1000);*/
					cnt++;
				}
				c1[i].is = 1;
				c1[j].is = 1;
			}//if
		}//for-j
	}//for-i

	for (int i = 0; i < c1.size(); i++) {
		if (c1[i].is == 1) {
			c1.erase(c1.begin() + i);
			i--;
		}//if		
	}//for-i

}//clash1

void clashh() {
	// ���� ���� :: �ڵ������� ��ǥ�� ��� �ٸ���.
	// 0.5�� �Ŀ� �߻��� �浹�� ó���Ѵ�. 
	for (int i = 0; i < c1.size(); i++) {
		for (int j = i + 1; j < c1.size(); j++) {
			int sumdir = dx[c1[i].r] + dx[c1[j].r] +
				dy[c1[i].r] + dy[c1[j].r];
			int sumxy = abs(c1[i].x - c1[j].x) +
				abs(c1[i].y - c1[j].y);
			if (sumdir == 0 &&	// ������ ���ݴ��̰�
				sumxy == 1 &&	// �Ÿ��� ���̰� 1 �̴�. 
				(c1[i].x == c1[j].x || c1[i].y == c1[j].y)) {//���� ��ǥ���� �ִ�.
				if (c1[i].is == 0 && c1[j].is == 0) {
					//printf("clashh :: �����浹\n");
					/*printf("clashh :: (%d %d)�� (%d %d) �浹\n",
						c1[i].y - 1000, c1[i].x - 1000,
						c1[j].y - 1000, c1[j].x - 1000);*/
					cnt++;
				}//if
				c1[i].is = 1;
				c1[j].is = 1;
				break;
			}//if
		}//for-j
	}//for-i

	for (int i = 0; i < c1.size(); i++) {
		if (c1[i].is == 1) {
			c1.erase(c1.begin() + i);
			i--;
		}//if		
	}//for-i

}//clashh

int main() {

	int ts; scanf("%d", &ts);
	for (int tt = 1; tt <= ts; tt++) {
		cnt = 0;
		c1.clear();
		scanf("%d", &s);
		c1.resize(s);
		for (int i = 0; i < c1.size(); i++) {
			scanf("%d %d %d", &c1[i].y, &c1[i].x, &c1[i].r);
		}//for-i	

		//printf("----------------------------------------------------\n");
		//for (int i = 0; i < c1.size(); i++) {
		//	printf("%2d %2d %d\n", c1[i].y-1000, c1[i].x - 1000, c1[i].r);
		//}//for-i
		///////////////////////////////////////////////////////////////////
		int time = 0;
		while (!c1.empty()) {
			//printf("%d �ð� :: %d�� ����\n", time++, c1.size());
			forward();
			clash1();
			clashh();
		}//while
		///////////////////////////////////////////////////////////////////
		printf("#%d %d\n", tt, cnt);
	}//fpr-tt

	return 0;
}//main




//printf("----------------------------------------------------\n");
//for (int i = 0; i < c1.size(); i++) {
//	printf("%d %d %d\n", c1[i].y, c1[i].x, c1[i].r);
//}//for-i

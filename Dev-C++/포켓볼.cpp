#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dx[] = { 0,-1,1,0,0 };	// �� �� �� �� 
int dy[] = { 0,0,0,-1,1 };
int n, m, s, k;				// (����, ����, �ð�, �籸�� ����)
typedef struct ball {
	int bnum; 	// �籸���� ��ȣ 
	int x;		// ���� 
	int y;		// ���� 
	int dx;		// ���� >> ƨ���� ������ -1 ���ؼ� ���� �ٲٱ� ���ؼ�
	int dy;		// ����
	int f;		// �Ŀ�	
	int time = 0;	// ��ÿ� �浹�ߴ�?
};
vector<ball> grp;

ball make_ball(int bnum, int x, int y, int d, int f) {
	ball bb;
	bb.bnum = bnum;
	bb.x = x;
	bb.y = y;
	bb.dx = dx[d];
	bb.dy = dy[d];
	bb.f = f;
	return bb;
}//make_ball 

int comp(pair<int, int> p1, pair<int, int> p2) {
	// ��ȣ, ��
	// ������ �����Ѵ� >> ���̰��ٸ� ��ȣ�� �������� ������ �����Ѵ�.
	if (p1.second > p2.second) {
		return 1;
	}
	else if (p1.second == p2.second) {
		if (p1.first < p2.first) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else if (p1.second < p2.second) {
		return 0;
	}
}//coll

void coll(int time) {
	// �浹�� �������� 
	for (int i = 0; i < grp.size()-1; i++) {
		vector<pair<int, int> > ccar;		// �浹�� ������ ����
		int flag = 0;						// �浹�� ������ �ִ�?
		if (grp[i].time == time) continue;	// �տ��� �̹� ó�������� �ִٸ� ó�� �ʰڴ�.
		if (grp[i].f == 0) continue;		// �̹� ����� ���� ó������ �ʰڴ�.
		for (int j = i+1; j < grp.size(); j++) {
			if (i == j) continue;
			if (grp[i].x == grp[j].x &&
				grp[i].y == grp[j].y) {
			
				if (flag == 0) {
					flag = 1;
					grp[i].time = time;
					grp[j].time = time;
					ccar.push_back(make_pair(grp[i].x, grp[i].y));
					ccar.push_back(make_pair(grp[j].x, grp[j].y));
				}
				else {
					grp[j].time = time;
					ccar.push_back(make_pair(grp[j].x, grp[j].y));
				}//if-2
			}//if-1
		}//for-j

		if (flag == 1) {
			sort(ccar.begin(), ccar.end(), comp);
			grp[ccar[0].first].f /= 2;
			for (int w = 1; w < ccar.size(); w++) {
				grp[ccar[w].first].f = 0;
			}//for-w
		}//if

	}//for-i
}//coll

void go() {
	// ������ ������Ų��.
	// ���� ƨ�� ���� ���� ��������, ������ ���ݴ�� �����.
	for (int i = 0; i < grp.size(); i++) {
		if (grp[i].f != 0) { // ����� ���� �ƴ϶��
			grp[i].x += grp[i].dx;
			grp[i].y += grp[i].dy;
			if (grp[i].x <= 0 || grp[i].x >= n - 1 || grp[i].y <= 0 || grp[i].y >= m - 1) {
				grp[i].x -= grp[i].dx;
				grp[i].y -= grp[i].dy;
				grp[i].dx *= -1;
				grp[i].dy *= -1;
				grp[i].f /= 2;
			}//if
		}//if
	}//for-i
}//go

int main() {
	grp.clear();
	scanf("%d %d %d %d", &n, &m, &s, &k);
	for (int i = 0; i < k; i++) {
		int xx, yy, dd, ff;
		scanf("%d %d %d %d", &yy, &xx, &dd, &ff);// ����, ����, ��, ���� 
		grp.push_back(make_ball(i, xx, yy, dd, ff));
	}//for-i
	///////////////////////////////////////////////////////////////////////////
	for (int tm = 1; tm <= s; tm++) {
		go();
		coll(tm);
	}//for-tm
	///////////////////////////////////////////////////////////////////////////
	int z=0; 
	printf("#d ");
	for (int i = 0; i < grp.size(); i++) {
		if (grp[i].f == 0) {
			z=1;			
			printf("%d ", grp[i].bnum);
		}//if
	}//for-i
	
	if(z==0){
		printf("-1\n");
	}

	return 0;
}//main

// �Է�
// T
// n, m, s, k (����, ����, �ð�, �籸�� ����) 
// y, x, f, d (��ǥ, �籸���� ��, �̵�����) 

// ���
// �� �׽�Ʈ ���̽��� ���� �ð� S�ʰ� �帥 �� ����� �籸���� ��ȣ�� 
// ������������ �� �ٿ� ������ ���� �����Ͽ� ����Ѵ�. 
// ���� ����� �籸���� ���ٸ� "-1"�� ����Ѵ�. 

// ����
// ���� 2�� �̻��� �籸���� ���� ���, ���� ���� ū �籸���� ���� 
// �籸���� ���� ���� 0�� �� ���, �ش� �籸�� ���� �������.
// ���� �ε����� ������ �ݴ� && �� ũ�� ����

// ūƲ
// �Է� >> �ڽ��� �������� ���� >> �浹üũ >> 

// �Է� >> �������� �ڵ��� ó�� ���� >> ������ 2���� �迭������ ����� �����Ѱ��̴ϱ�

// �����ϱ�
// �ڽ��� ������ 1ĭ �����ϱ�
// ���� ������ ���� �ݴ�� && �� �������� >> ���� "0"�Ǹ� �����.
// ���� :: ���� ƨ��°� ��� ǥ������?


// �浹üũ >> ��Ȳ ����
// �籸�� ���� "0"�� �Ǹ� �������.
// 2�� �̻� ������ ���� ���� ū �籸���� ���� >> �� �籸���� ���� �������� ��
// ���� ū ���� ���� �籸���� 2�� �̻��� ���, ��ȣ�� ���� �籸���� ���´�

// ���� :: 0������ �ڱ�� �浹�� �籸������ ã�Ƽ� ���Ϳ� ��´�.


//for (int i = 0; i < k; i++) {
//	printf("%d :: (%d, %d) (%d, %d) %d\n",
//		grp[i].bnum, grp[i].x, grp[i].y,
//		grp[i].dx, grp[i].dy, grp[i].f);// ����, ����, ����, ��		
//}//for-i

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dx[] = { 0,-1,1,0,0 };	// 상 하 좌 우 
int dy[] = { 0,0,0,-1,1 };
int n, m, s, k;				// (세로, 가로, 시간, 당구공 개수)
typedef struct ball {
	int bnum; 	// 당구공의 번호 
	int x;		// 세로 
	int y;		// 가로 
	int dx;		// 방향 >> 튕겨져 나갈때 -1 곱해서 방향 바꾸기 위해서
	int dy;		// 방향
	int f;		// 파워	
	int time = 0;	// 몇시에 충돌했니?
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
	// 번호, 힘
	// 힘으로 정렬한다 >> 힘이같다면 번호가 작은것이 앞으로 오게한다.
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
	// 충돌한 차량들을 
	for (int i = 0; i < grp.size()-1; i++) {
		vector<pair<int, int> > ccar;		// 충돌한 차들의 집합
		int flag = 0;						// 충돌한 차량이 있니?
		if (grp[i].time == time) continue;	// 앞에서 이미 처리한적이 있다면 처리 않겠다.
		if (grp[i].f == 0) continue;		// 이미 사라진 차는 처리하지 않겠다.
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
	// 모든공을 전진시킨다.
	// 벽에 튕긴 공은 힘은 절반으로, 방향은 정반대로 만든다.
	for (int i = 0; i < grp.size(); i++) {
		if (grp[i].f != 0) { // 사라진 공이 아니라면
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
		scanf("%d %d %d %d", &yy, &xx, &dd, &ff);// 가로, 세로, 힘, 방향 
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

// 입력
// T
// n, m, s, k (세로, 가로, 시간, 당구공 개수) 
// y, x, f, d (좌표, 당구공의 힘, 이동방향) 

// 출력
// 각 테스트 케이스에 대해 시간 S초가 흐른 뒤 사라진 당구공의 번호를 
// 오름차순으로 한 줄에 공백을 통해 구분하여 출력한다. 
// 만약 사라진 당구공이 없다면 "-1"을 출력한다. 

// 설계
// 만약 2개 이상의 당구공이 만날 경우, 힘이 가장 큰 당구공만 남고 
// 당구공이 가진 힘이 0이 될 경우, 해당 당구공 또한 사라진다.
// 벽에 부딪히면 방향은 반대 && 힘 크기 절반

// 큰틀
// 입력 >> 자신의 방향으로 전진 >> 충돌체크 >> 

// 입력 >> 자율주행 자동차 처럼 했음 >> 하지만 2차원 배열에서의 모습을 구현한것이니까

// 전진하기
// 자신의 방향대로 1칸 전진하기
// 벽에 맞으면 방향 반대로 && 힘 절반으로 >> 힘이 "0"되면 사라짐.
// 구현 :: 벽에 튕기는걸 어떻게 표현하지?


// 충돌체크 >> 상황 적용
// 당구공 힘이 "0"이 되면 사라진다.
// 2개 이상 만나면 힘이 가장 큰 당구공만 남음 >> 그 당구공의 힘은 절반으로 됨
// 가장 큰 힘을 가진 당구공이 2개 이상일 경우, 번호가 작은 당구공만 남는다

// 구형 :: 0번부터 자기와 충돌한 당구공들을 찾아서 벡터에 담는다.


//for (int i = 0; i < k; i++) {
//	printf("%d :: (%d, %d) (%d, %d) %d\n",
//		grp[i].bnum, grp[i].x, grp[i].y,
//		grp[i].dx, grp[i].dy, grp[i].f);// 가로, 세로, 방향, 힘		
//}//for-i

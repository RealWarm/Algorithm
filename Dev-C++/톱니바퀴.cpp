#include<iostream> 
#include<vector> 
#include<cstring> 
using namespace std;
struct rot {
	int num;
	char dir;
};
vector<rot> v1;
vector<int> grp[6]; // 톱니바퀴들을 저장 
//vector<int>::iterator it; >> insert를 사용하려고 그랬는데 안써도 됨. 
int wei[5];
int con[8][4] = {{1,5,2,1},
				{1,3,3,7},
				{2,1,1,5},
				{2,3,4,7},
				{3,7,1,3},
				{3,5,4,1},
				{4,7,2,3},
				{4,1,3,5} };
int k;

void gturn(int num, char dir) {
	//wei의 원소가 1인 톱니바퀴를 해당방향으로 회전시킨다
	if (dir == '+') {//시계방향으로 회전 >>
//		it = grp[num].begin();
		grp[num].insert(grp[num].begin(), grp[num][7]);
		grp[num].pop_back();
	}else if (dir == '-') {//반시계방향으로 회전 <<
		grp[num].push_back(grp[num][0]);
//		it = grp[num].begin();
		grp[num].erase(grp[num].begin());
	}//if
}//gturn

void dfs(int num, char dir) {
	wei[num] = 1;
	for (int i = 0; i < 8; i++) {
		if (con[i][0] == num) {
			if (wei[con[i][2]] == 0 && //방문 하지 않았고
					grp[con[i][0]][con[i][1]]!= 
						grp[con[i][2]][con[i][3]]) {
					//맞닿는 기어의 부호가 서로 다르다면
				if (dir == '+') {
					dfs(con[i][2], '-');
				}else if(dir=='-'){
					dfs(con[i][2], '+');
				}//if-3
			}//if-2
		}//if-1
	}//for-i
	gturn(num, dir);
}//dfs

int main() {

	int ts; scanf("%d", &ts);
	for (int tt = 1; tt <= ts; tt++) {
		v1.clear();
		for (int i = 0; i < 6; i++) {
			grp[i].clear();
		}
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			int a;
			char pm;
			scanf("%d %c", &a, &pm);
			v1.push_back({ a, pm });
		}//for-i
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				int a; scanf("%d", &a);
				grp[i].push_back(a);
			}//for-j
		}//for-i
		///////////////////////////////////////////////////////////////////
		// k번 회전 시킨다.
		for (int a = 0; a < k; a++) {
			memset(wei, 0, sizeof(wei));
			int gnum = v1[a].num;
			char gdir = v1[a].dir;
			dfs(gnum, gdir);
		}//for-a
		///////////////////////////////////////////////////////////////////
		printf("#%d %d %d %d %d\n", tt, grp[1][0], grp[2][6], grp[3][2], grp[4][4]);

	}//for-tt
	
	return 0;
}//main
















//printf("k :: %d\n", k);
//for (int i = 0; i < k; i++) {
//	printf("num :: %d || dir :: %c \n", v1[i].num, v1[i].dir);
//}//for-i
//printf("\n\n");
//for (int i = 1; i <= 4; i++) {
//	for (int j = 0; j < 8; j++) {
//		printf("%d ", grp[i][j]);
//	}//for-j
//	printf("\n");
//}//for-i

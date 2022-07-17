#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
struct fish {
	int num;
	int x;
	int y;
	int dir;
};//fis
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int grp[10][10];	// 상어들의 번호만 저장하겠다. 
vector<fish> vv; 	// 물고기들 정보
fish stk; 			// 상어의 정보  
int n = 4, mmax;	// 상어가 먹을 수 있는 물고기 번호의 합의 최댓값

int cmp(fish aa, fish bb) {
	if(aa.num < bb.num){
		return 1;
	} else{
		return 0;
	}//if
}//cmp

void get(int x, int sum, fish sk){
//	printf("x :: %d ||  sum :: %d\n", x, sum);
	// 물고기 움직이기	
	for(int i = 0; i < vv.size(); i++){
		int nwx = vv[i].x;
		int nwy = vv[i].y;
		int nwd = vv[i].dir;
		for(int k = 0; k < 8; k++){
			int ntd = (nwd + k) % 8;
			int ntx = nwx + dx[ntd];
			int nty = nwy + dy[ntd];
			// 경계를 넘어가면 안됨 && 상어면 진행 안됨
			if(ntx < 0 || nty < 0 || ntx >= n || nty >= n) continue;
			if(grp[ntx][nty] == 100) continue;
			// 물고기와 빈칸이라면
			if(grp[ntx][nty] == 0){ // 다음칸이 빈칸이라면
				int tnum = grp[ntx][nty]; // 영저장
				grp[ntx][nty] = grp[nwx][nwy];
				grp[nwx][nwy] = tnum;
				vv[i].dir = ntd;
				vv[i].x = ntx;
				vv[i].y = nty;
			} else{ // 물고기라면
				int tnum = grp[ntx][nty]; // 다음칸 물고기 번호 저장 
				grp[ntx][nty] = grp[nwx][nwy];
				grp[nwx][nwy] = tnum;
				for(int q = 0; q < vv.size(); q++){
					if(tnum == vv[q].num){ // 다음칸 물고기 찾기 
						vv[q].x = nwx;
						vv[q].y = nwy;
						vv[i].x = ntx;
						vv[i].y = nty;
						vv[i].dir = ntd;
					}//if
				}//for-q
			}//if
			break;
		}//for-k		
//		printf("%d 번째 물고기 ==========================\n", i+1);
//		for(int i = 0; i < 4; i++){
//			for(int j = 0; j < 4; j++){
//				printf("%3d ", grp[i][j]);
//			}//for-j
//			printf("\n");
//		}//for-i
	}//for-i
	////////////////////////////////////////////////////////////////
//	for(int i = 0; i < vv.size(); i++){
//		printf("%d :: %d (%d, %d) dir: %d\n",
//			   i, vv[i].num, vv[i].x, vv[i].y, vv[i].dir);
//	}//for-i
	////////////////////////////////////////////////////////////////
	int tmp[10][10]; 
	memcpy(tmp, grp, sizeof(tmp)); // 깜빡 
	vector<fish> tvv = vv; 
	fish tsk=sk;
	// 상어 움직이기 	
	int flag = 0; // 상어가 물고기를 먹은적이 한번이라도 있다면 
	int stx = sk.x;
	int sty = sk.y;
	int swd = sk.dir;
	while(1){
		sk=tsk;// 요거 !!!!!!!!!!!!!!!!! 
		stx += dx[swd];
		sty += dy[swd];
		if(stx < 0 || sty < 0 || stx >= n || sty >= n) break;
		if(grp[stx][sty] == 0) continue;
		// 물고기가 있으면 먹는다. 
		if(grp[stx][sty] >= 1 && grp[stx][sty] <= 16){
			flag = 1;
			int sn = grp[stx][sty]; 	// 물고기 번호 
			grp[sk.x][sk.y] = 0; 		// 상어의 원래위치 0 
			grp[stx][sty] = 100;		// 상어를 물고기 위치로 이동 
			for(int i = 0; i < vv.size(); i++){ // 그 물고기 찾기 
				if(vv[i].num == sn){
					sk.x = stx;
					sk.y = sty;
					sk.dir = vv[i].dir;
//					printf("x :: %d ||  %d deleted\n", x, sn);
					vv.erase(vv.begin() + i);
					get(x + 1, sum + sn, sk);
					memcpy(grp, tmp, sizeof(tmp));					
					vv = tvv;
					break;
				}//if
			}//for-i			
		}//if	
	}//while
	if(flag == 0){		
		mmax = max(sum, mmax);
//		printf("x :: %d || mmax :: %d\n", x, mmax);
		return;
	}//if
}//get


int main() {
	//////////////////////////////////////////////
	int vinx = 0; // 물고기 번호
	vv.resize(16);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int a, b; scanf(" %d %d", &a, &b);
			grp[i][j] = a;
			vv[vinx].num = a;
			vv[vinx].x = i;
			vv[vinx].y = j;
			vv[vinx].dir = b - 1; // 방향은 1부터 시작한다. 
			vinx++;
		}//for-j
	}//for-i
	sort(vv.begin(), vv.end(), cmp);
	/////////////////////////////////////////////
	// 상어넣기 >> (0, 0)의 상어번호 찾기
	int en = grp[0][0] - 1;
	grp[0][0] = 100;
	stk.num = 100;
	stk.x = vv[en].x;
	stk.y = vv[en].y;
	stk.dir = vv[en].dir;
	vv.erase(vv.begin() + en);
	/////////////////////////////////////////////	
	/////////////////////////////////////////////
	get(0, en+1, stk);
	/////////////////////////////////////////////
	printf("%d\n", mmax);
	/////////////////////////////////////////////
	return 0;
}//main

//printf("%d 번째 물고기 ==========================\n", i);
//		for(int i = 0; i < 4; i++){
//			for(int j = 0; j < 4; j++){
//				printf("%3d ", grp[i][j]);
//			}//for-j
//			printf("\n");
//		}//for-i
//		printf("%d\n", mmax);




//for(int i = 0; i < 4; i++){
//	for(int j = 0; j < 4; j++){
//		printf("%d ", grp[i][j]);
//	}//for-j
//	printf("\n");
//}//for-i
//
//for(int i = 0; i < vv.size(); i++){
//	printf("%d :: %d (%d, %d) dir: %d\n",
//		   i, vv[i].num, vv[i].x, vv[i].y, vv[i].dir);
//}//for-i







// 번호는 1보다 크거나 같고, 16보다 작거나 같은 자연수이며, 
// 두 물고기가 같은 번호를 갖는 경우는 없다. 
// 방향은 8가지 방향(상하좌우, 대각선) 중 하나이다.

//청소년 상어는 (0, 0)에 있는 물고기를 먹고, (0, 0)에 들어가게 된다. 
//상어의 방향은 (0, 0)에 있던 물고기의 방향과 같다. 

// (0, 0)에 있는 물고기를 먹고, (0, 0)에 들어가게 된다. 
// 상어의 방향은 (0, 0)에 있던 물고기의 방향과 같다.

// 물고기는 한 칸을 이동할 수 있고, 
// 이동할 수 있는 칸은 빈 칸과 다른 물고기가 있는 칸
// 이동할 수 없는 칸은 상어가 있거나, 공간의 경계를 넘는 칸이다.

// 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전
// 이동할 수없으면 이동하지 않는다.
// 물고기가 있는 칸으로 이동할 때는 서로의 위치를 바꾸는 방식으로 이동한다.

 // 상어 이동하기 한번에 여러개의 칸을 이동 할 수 있다. >> 오직 물고기 있는칸으로만 이동가능



// 물고기 입력 
//for(int i=0; i<4; i++){
//		for(int j=0; j<4; j++){
//			printf("%3d ", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
//
//	for(int i=0; i<vv.size(); i++){
//		printf("%d :: %d (%d, %d) dir: %d\n", 
//				i, vv[i].num, vv[i].x, vv[i].y, vv[i].dir);
//	}//for-i
//	printf("shark :: %d (%d, %d) dir: %d\n", 
//				sk.num, sk.x, sk.y, sk.dir);



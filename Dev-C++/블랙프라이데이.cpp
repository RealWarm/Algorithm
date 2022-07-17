초기화
>> 입력
>> 사람들이 어떤 매장에 갈건지 정한다(재귀 ch배열) 
>> 사람들과 정해진 매장사이의 거리를 구한다.
>> 걸어간다(시간이 1초 흐른다) >> for(time++)
>> 모든 사람에 대하여 체크한다 >> for(a= 0~v3.size())




#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
struct store {
	int pnum;	// 제한인원 :: p
	int ltime;	// 제한시간 :: s
	int x, y;	// 매장의 좌표
	int npnum;	// 현재 매장에 몇명이 있니?
};
struct pp {
	int x, y;		// 사람의 위치
	int dis = 0;	// 매장과의 거리
	int is = 0;		// 너 지금 매장에 있니?
	int stime = 0;	// 매장에서 얼마나 있었니?		
	int st = 0;		// 쇼핑을 모두 마쳤니?
};
int n, m, k;		// 세로, 가로, 매장수
vector<store>	v1;	// 매장정보 저장
vector<pp>	v2, v3;	// 사람의 정보를 저장하는 벡터
vector<string> grp;	// 그래프 저장
int ch[10]; // 백화점 고객들이 어느 매장으로 갈껀지 >> 재귀함수용
int r;		// 사람의 수
int mmin = 987987987;

// 문제가 있다면 여기일듯해요
int go() {
	// 모든 쇼핑을 만족하면 해당 사람의 st(flag역할)을 1로 만들지만 
	// 원본을 훼손 안하기 위해 벡터를 복사한다.
	v3 = v2;	
	int stnum = 0;	// 쇼핑을 끝마친 인원들의 수
	int time = 1;	// 흘러간 시간
	for (; ; ++time) {
		//시간을 1초씩 증가시킨다.		
		for (int a = 0; a < v3.size(); a++) {
			//사람을 정하고			
			if (v3[a].is == 1 && v3[a].st == 0) {
				//이미 매장에 있고 쇼핑을 마치지 않았다면.
				v3[a].stime++;//매장에서 있는 시간을 증가시킨다.
				if (v1[ch[a]].ltime <= v3[a].stime) {
					// 매장의 제한시간 <= 쇼핑한시간
					// 쇼핑시간을 다 채웠다면
					v1[ch[a]].npnum--;	// 매장의 총인원을 한명 줄인다		
					v3[a].st = 1;		// 그 사람은 쇼핑을 마췄다고 저장한다.
					stnum++;			// 쇼핑을 마친 인원의 수를 증가시킨다.
				}//if
			}else if (v3[a].is == 0 && v3[a].dis <= time) {
				//매장에 있지 않고 && 사람이 매장에 도착했다면				
				if (v1[ch[a]].pnum > v1[ch[a]].npnum) {
					//현재 매장에 사람이 들어 올 수 있다면.
					v3[a].is = 1;		// 해당 사람이 매장에 있다고 표시한다.
					v3[a].stime++;		// 해당 사람이 매장에서의 시간을 1증가 시킨다.
					v1[ch[a]].npnum++;	// 매장의 사람의 수를 1증가 시킨다.
				}//if-2
			}//if-1
		}//for-a

		if (stnum == r) break; //
	}//for-time

	return time+1; //!!!!!!!!!!여기를 왜 +1 해야하지...?
}//go

void get(int x) {
	//사람들이 어느 매장에 갈껀지 정한다.
	if (x >= r) {
		for (int i = 0; i < r; i++) {
			//사람들과 매장사이의 거리를 구한다.
			v2[i].dis = abs(v1[ch[i]].x - v2[i].x) + abs(v1[ch[i]].y - v2[i].y);
		}//for-i
		//for (int i = 0; i < r; i++) {
		//	printf("%d번째 사람의 지정된 store는 %d 이고 상점과의 거리는 %d 입니다.\n",
		//		i, ch[i], v2[i].dis);
		//}//for-i
		//printf("==================================================================================\n");
		int result = go();
		if (mmin > result) {
			mmin = result;
		}//if
	}else {
		//매장의 번호는 0번부터 k-1까지 이다.
		for (int i = 0; i < k; i++) {
			ch[x] = i;
			get(x + 1);
		}//for-i
	}//if
}//get


int main() {
	int ts; scanf("%d", &ts);
	for (int tt = 1; tt <= ts; tt++) {				
		v1.clear();
		v2.clear();
		grp.clear();
		mmin = 987987987;
		memset(ch, -1, sizeof(ch));
		///////////////////////////////////////////////////////////////////////
		scanf("%d %d %d", &n, &m, &k);
		v1.resize(k);//매장의 갯수 별로 배열 재조정
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &v1[i].pnum, &v1[i].ltime);
		}//for-i
		grp.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> grp[i];
		}//for-i
		///////////////////////////////////////////////////////////////////////
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grp[i][j] <= 'Z' && grp[i][j] >= 'A') {
					v1[grp[i][j] - 'A'].x = i; //세로
					v1[grp[i][j] - 'A'].y = j; //가로
				}else if (grp[i][j] == '1') {
					pp temp;
					temp.x = i;
					temp.y = j;
					v2.push_back(temp);
				}//if
			}//for-j
		}//for-i		
		r = v2.size(); // 사람의 수 만큼 r중 for문을 하겠다.
		if (r == 0) {
			//문제를 잘읽어보자!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			printf("#%d 0\n", tt);
			continue;
		}//if
		get(0);
		///////////////////////////////////////////////////////////////////////
		printf("#%d %d\n", tt, mmin);
	}//for-tt
	return 0;
}//main

//입력된 값들과 매장의 좌표, 제한인원, 제한시간 체크
//printf("\n\n");
//printf("%d %d %d\n", n, m, k);
//for (int i = 0; i < k; i++) {
//	printf("%c :: %d %d %d %d\n",
//		i + 'A', v1[i].pnum, v1[i].ltime, v1[i].x, v1[i].y);
//}//for-i
//for (int i = 0; i < n; i++) {
//	cout << grp[i] << endl;
//}//for-i

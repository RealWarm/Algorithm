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
int grp[10][10];	// ������ ��ȣ�� �����ϰڴ�. 
vector<fish> vv; 	// ������ ����
fish stk; 			// ����� ����  
int n = 4, mmax;	// �� ���� �� �ִ� ����� ��ȣ�� ���� �ִ�

int cmp(fish aa, fish bb) {
	if(aa.num < bb.num){
		return 1;
	} else{
		return 0;
	}//if
}//cmp

void get(int x, int sum, fish sk){
//	printf("x :: %d ||  sum :: %d\n", x, sum);
	// ����� �����̱�	
	for(int i = 0; i < vv.size(); i++){
		int nwx = vv[i].x;
		int nwy = vv[i].y;
		int nwd = vv[i].dir;
		for(int k = 0; k < 8; k++){
			int ntd = (nwd + k) % 8;
			int ntx = nwx + dx[ntd];
			int nty = nwy + dy[ntd];
			// ��踦 �Ѿ�� �ȵ� && ���� ���� �ȵ�
			if(ntx < 0 || nty < 0 || ntx >= n || nty >= n) continue;
			if(grp[ntx][nty] == 100) continue;
			// ������ ��ĭ�̶��
			if(grp[ntx][nty] == 0){ // ����ĭ�� ��ĭ�̶��
				int tnum = grp[ntx][nty]; // ������
				grp[ntx][nty] = grp[nwx][nwy];
				grp[nwx][nwy] = tnum;
				vv[i].dir = ntd;
				vv[i].x = ntx;
				vv[i].y = nty;
			} else{ // �������
				int tnum = grp[ntx][nty]; // ����ĭ ����� ��ȣ ���� 
				grp[ntx][nty] = grp[nwx][nwy];
				grp[nwx][nwy] = tnum;
				for(int q = 0; q < vv.size(); q++){
					if(tnum == vv[q].num){ // ����ĭ ����� ã�� 
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
//		printf("%d ��° ����� ==========================\n", i+1);
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
	memcpy(tmp, grp, sizeof(tmp)); // ���� 
	vector<fish> tvv = vv; 
	fish tsk=sk;
	// ��� �����̱� 	
	int flag = 0; // �� ����⸦ �������� �ѹ��̶� �ִٸ� 
	int stx = sk.x;
	int sty = sk.y;
	int swd = sk.dir;
	while(1){
		sk=tsk;// ��� !!!!!!!!!!!!!!!!! 
		stx += dx[swd];
		sty += dy[swd];
		if(stx < 0 || sty < 0 || stx >= n || sty >= n) break;
		if(grp[stx][sty] == 0) continue;
		// ����Ⱑ ������ �Դ´�. 
		if(grp[stx][sty] >= 1 && grp[stx][sty] <= 16){
			flag = 1;
			int sn = grp[stx][sty]; 	// ����� ��ȣ 
			grp[sk.x][sk.y] = 0; 		// ����� ������ġ 0 
			grp[stx][sty] = 100;		// �� ����� ��ġ�� �̵� 
			for(int i = 0; i < vv.size(); i++){ // �� ����� ã�� 
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
	int vinx = 0; // ����� ��ȣ
	vv.resize(16);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int a, b; scanf(" %d %d", &a, &b);
			grp[i][j] = a;
			vv[vinx].num = a;
			vv[vinx].x = i;
			vv[vinx].y = j;
			vv[vinx].dir = b - 1; // ������ 1���� �����Ѵ�. 
			vinx++;
		}//for-j
	}//for-i
	sort(vv.begin(), vv.end(), cmp);
	/////////////////////////////////////////////
	// ���ֱ� >> (0, 0)�� ����ȣ ã��
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

//printf("%d ��° ����� ==========================\n", i);
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







// ��ȣ�� 1���� ũ�ų� ����, 16���� �۰ų� ���� �ڿ����̸�, 
// �� ����Ⱑ ���� ��ȣ�� ���� ���� ����. 
// ������ 8���� ����(�����¿�, �밢��) �� �ϳ��̴�.

//û�ҳ� ���� (0, 0)�� �ִ� ����⸦ �԰�, (0, 0)�� ���� �ȴ�. 
//����� ������ (0, 0)�� �ִ� ������� ����� ����. 

// (0, 0)�� �ִ� ����⸦ �԰�, (0, 0)�� ���� �ȴ�. 
// ����� ������ (0, 0)�� �ִ� ������� ����� ����.

// ������ �� ĭ�� �̵��� �� �ְ�, 
// �̵��� �� �ִ� ĭ�� �� ĭ�� �ٸ� ����Ⱑ �ִ� ĭ
// �̵��� �� ���� ĭ�� �� �ְų�, ������ ��踦 �Ѵ� ĭ�̴�.

// �̵��� �� �ִ� ĭ�� ���� ������ ������ 45�� �ݽð� ȸ��
// �̵��� �������� �̵����� �ʴ´�.
// ����Ⱑ �ִ� ĭ���� �̵��� ���� ������ ��ġ�� �ٲٴ� ������� �̵��Ѵ�.

 // ��� �̵��ϱ� �ѹ��� �������� ĭ�� �̵� �� �� �ִ�. >> ���� ����� �ִ�ĭ���θ� �̵�����



// ����� �Է� 
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



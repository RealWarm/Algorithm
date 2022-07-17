#include<iostream>
#include<cstring>
using namespace std;
int dx[] = { -1, 0, 1, 0 }; //상,우,하,좌 
int dy[] = { 0, 1, 0,-1 };
int grp[10][10];
int tmp[10][10];
int rol[10]; // 회전수를 저장한 배열 
int n, m, k, mmax;

int dir[][4] = {
	{0,0,0,0},
	{1,0,0,0},
	{1,0,1,0},
	{1,1,0,0},
	{1,1,0,1},
	{1,1,1,1}
};

void fill(int x1, int y1, int num, int tr) {
	
	int darr[4];
	memcpy(darr, dir[num], sizeof(darr));
	
	for(int a=0; a<tr; a++){	
		int le=darr[3];
		for(int i=3; i>=1; i--){
			darr[i]=darr[i-1];
		}
		darr[0]=le;
	}//for-a
	
	for (int k = 0; k < 4; k++) {
		if (darr[k] == 1) {
			int ntx = x1;
			int nty = y1;
			while (1) {
				ntx += dx[k];
				nty += dy[k];
				if (ntx < 0 || nty < 0 || ntx >= n || nty >= m) break;
				if (grp[ntx][nty] == 6) break;
				if (grp[ntx][nty] == 0) {
					grp[ntx][nty] = 8;
				}//if
			}//while
		}//if
	}//for-k
		

}//fill


void get(int x){
	
	if(x==k){
		memcpy(grp, tmp, sizeof(tmp));
		int cnt=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmp[i][j] >= 1 && tmp[i][j] <= 5) {				
					fill(i, j, tmp[i][j], rol[cnt++]);
				}//if
			}//for-j
		}//for-i
		
		int cnt8=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(grp[i][j]==0) cnt8++;
			}//for-j		
		}//for-i
		
		if(mmax>cnt8){
			mmax=cnt8;
		}		
		
	}else{
		for(int i=0; i<4; i++){
			rol[x]=i;
			get(x+1);
		}//for-i
	}//if
	
}//get

int main() {
	
	int ts; 
	scanf("%d", &ts);
	
	for(int tt=1; tt<=ts; tt++){
		k=0; // 수도의 수
		mmax=987987;
		memset(grp, 0, sizeof(grp));
		memset(tmp, 0, sizeof(tmp));
		memset(rol, 0, sizeof(rol));
		scanf("%d %d", &n, &m);				
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &tmp[i][j]);
				if (tmp[i][j] >= 1 && tmp[i][j] <= 5) k++;				
			}//for-j
		}//for-i
		
		get(0);
				
		printf("#%d %d\n", tt, mmax);		
	}//for-tt	

	return 0;
}//main

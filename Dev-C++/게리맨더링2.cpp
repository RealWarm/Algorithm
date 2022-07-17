#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF = 987654321;
int N;
int map[21][21];

int diff(int x, int y, int d1, int d2) {
	vector<int> population(5, 0);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			//1번 선거구
			if (r < x + d1 && c <= y && 
					!(r >= x && c >= y - (r - x))) {
				population[0] += map[r][c];
			}
			//2번 선거구
			else if (r <= x + d2 && c > y && 
						!(r >= x && c <= y + (r - x))) {
				population[1] += map[r][c];
			}
			//3번 선거구
			else if (r >= x + d1 && c < y - d1 + d2 && 
						!(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
				population[2] += map[r][c];
			}
			//4번 선거구
			else if (r > x + d2 && c >= y - d1 + d2 
						&& !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
				population[3] += map[r][c];
			}
			//5번 선거구
			else {
				population[4] += map[r][c];
			}
		}//for-c
	}//for-r

	sort(population.begin(), population.end());

	return population[4] - population[0];
}

int minDiff() {
	int res = INF;

	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++) {
				for (int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++) {
					res = min(res, diff(x, y, d1, d2));
				}
			}
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> map[x][y];
		}
	}
	cout << minDiff() << endl;
	return 0;
}
























//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int grp[110][110];
//int ggg[110][110];
//int wei[110][110];
//int n;
//
//int main(){
//	scanf("%d", &n);
////	for(int i=0; i<n; i++){
////		for(int j=0; j<n; j++){
////			scanf(" %d", &grp[i][j]);
////		}//for-j
////	}//for-i
//	/////////////////////////////////////////
//	// 구역 나누기
//	//1. x y 좌표정하기
//	//2. d1, d2 정하기
//	//3. 길이대로 구역나누기. 
////	for(int a=1; a<(n-1)-2; a++){
////		for(int b=1; b<(n-1)-2; b++){
////			
////		}//for-b
////	}//for-a
//	int d1=3, d2=3;
//	int x=1, y=3;	
//	/////////////////////////////////////
//	//구역 1 채우기
//	int end1;
//	if(d1==d2) end1=x+d1;
//	else end1=x+d1-1;
//	for(int i=0; i<end1; i++){		
//		int end;
//		if(i<x) end=y;
//		else if(i>=x) end=y-(i-x)-1;
//		for(int j=0; j<=end; j++){
//			wei[i][j]=1;
//		}//for-j
//	}//for-i	
//	/////////////////////////////////////
//	//구역 2 채우기
//	int end2, end3;
//	if(y+d2==n-1) end2=x+d2-1;
//	else end2=x+d2;
//	
//	for(int i=0; i<=end2; i++){
//		int st;
//		if(i<x) st=y+1;
//		else st=y+(i-x)+1;
//		for(int j=st; j<n; j++){
//			wei[i][j]=2;
//		}//for-j
//	}//for-i
//	
//	
//	printf("\n\n\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%d ", wei[i][j]);			
//		}
//		printf("\n");
//	}
//	
//	return 0;
//}//main


//	printf("---------------------\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%d ", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i

// 구역을 다섯 개의 선거구로 나눠야 하고, 
// 각 구역은 다섯 선거구 중 하나에 포함되어야 한다. 
// 선거구는 구역을 적어도 하나 포함해야 하고, 
// 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 한다.









































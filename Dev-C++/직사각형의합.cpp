#include<iostream>
using namespace std;
int n, m, ts;
int grp[1010][1010];
int tb[1010][1010];

int main(){
	scanf("%d %d %d", &n, &m, &ts);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	///////////////////////////////////////////////////////////
	// 테이블 만들기
	tb[1][1]=grp[1][1];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			tb[i][j]=tb[i-1][j] + tb[i][j-1] + grp[i][j] -tb[i-1][j-1];
		}//for-j
	}//for-i
	///////////////////////////////////////////////////////////
	// 답출력하기
	for(int t=0; t<ts; t++){
		int x1, y1, x2, y2, sum=0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1++, x2++, y1++, y2++;
		sum=tb[x2][y2]-(tb[x1-1][y2] + tb[x2][y1-1]-tb[x1-1][y1-1]);
		printf("%d\n", sum);
	}//for-t
	 
	
	
	return 0;
}//main







//#include<iostream>
//using namespace std;
//int grp[1010][1010];
//int n, m, ts;
//
//int main(){
//	scanf("%d %d %d", &n, &m, &ts);
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			scanf("%d", &grp[i][j]);
//		}//for-j
//	}//for-i
//	
//	for(int tt=0; tt<ts; tt++){
//		int x1, y1, x2, y2, sum=0;
//		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
//		for(int a=x1; a<=x2; a++){
//			for(int b=y1; b<=y2; b++){
//				sum+=grp[a][b];
//			}//for-b
//		}//for-a
//		
//		printf("%d\n", sum);
//	}//for-a
//	
//	
//	return 0;
//}//main

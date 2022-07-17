#include<iostream>
#include<cstring>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int grp[60][60];
int wei[60][60];
int ct[20];//포자의 갯수를 세기위한 계수정렬 배열 
int n, m;

void spread() {
	// 다자란 버섯이라면 사방면으로 포자를 뿌려보겠다. 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {						
			if (grp[i][j] > 0 && wei[i][j] == grp[i][j]) { 						
				// 다자란!!!!!!!!!! 버섯이라면
				// grp[i][j]>0 && wei[i][j]>0 : 버섯
				// grp[i][j]>0 && wei[i][j]==0  : 포자 
				for (int k = 0; k < 4; k++) {
					int ntx = i + dx[k];
					int nty = j + dy[k];
					if (ntx < 0 || nty < 0 || ntx >= n || nty >= m) continue;
					if (grp[ntx][nty] == 0) {//빈 공간이면 
						//포자를 뿌리기 						
						grp[ntx][nty] = grp[i][j];
					}else if (grp[ntx][nty] != 0) {//빈공간이 아니라면						
						if (grp[ntx][nty] > 0 && wei[ntx][nty] > 0) {//버섯일 경우 지나간다. 
							continue;
						}else if (grp[ntx][nty] > 0 && wei[ntx][nty] == 0) {//포자일경우 
							if (grp[ntx][nty] >= grp[i][j]) {//나보다 크게될놈이면 넘어감 
								continue;
							}else if (grp[ntx][nty] < grp[i][j]) {//나보다 작을놈이면 나로! 
								grp[ntx][nty] = grp[i][j];
							}
						}//if-3 						
					}//if-2 					
				}//for-k
				
			}//if-1		
		}//for-j
	}//for-i

}//spread

void grow() {//다자라지 않은 버섯일 경우 "1"만큼 성장시킨다. 
//	printf("grow :: invoked!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grp[i][j] > 0 && grp[i][j] > wei[i][j]) {
				//덜 자란버섯의 키를 1만큼 키운다.
				wei[i][j]++;
			}//if 
		}//for-j
	}//for-i

}//grow

int growCheck() {//다 자라지 않은 버섯이 있을 경우 >> 1 반환 
				 //모두 자랐다면 >> 0 반환		
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grp[i][j] > 0 && grp[i][j] > wei[i][j]) {				
				flag = 1;
			}//if
		}//for-j
	}//for-i

	return flag;
} //growCheck


int main() {

	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		memset(grp, 0, sizeof(grp));
		memset(wei, 0, sizeof(wei));
		memset(ct, 0, sizeof(ct));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char cc;
				scanf(" %c", &cc);
				if (cc == '0') {
					grp[i][j] = 0;
				}
				else if (cc >= 65 && cc <= 74) {				
					grp[i][j] = cc - 'A' + 1;
					//버섯은 초기에 "1"의 키를 갖는다. 
					wei[i][j] = 1;//실수!!!!!!!!!!!!!!!!!!!! 
				}//if
			}//for-j
		}//for-i
	
	//	for (int i = 0; i < n; i++) {
	//		for (int j = 0; j < m; j++) {
	//			printf("%d", grp[i][j]);
	//		}//for-j
	//		printf("\n");
	//	}//for-i
	//	printf("\n");
	//	printf("\n");
	//	for (int i = 0; i < n; i++) {
	//		for (int j = 0; j < m; j++) {
	//			printf("%d", wei[i][j]);
	//		}//for-j
	//		printf("\n");
	//	}//for-i
				
		while (1) {
			
			// 실수 : 진행순서에서 문제가 있었다. 
			spread();
			if (growCheck() == 0) {//실수!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						ct[grp[i][j]]++;
					}//for-j
				}//for-i
	
				printf("#%d ", tt);
				for (int i = 1; i <= 10; i++) {
					printf("%d ", ct[i]);
				}				
				printf("\n");
//				for (int i = 0; i < n; i++) {
//					for (int j = 0; j < m; j++) {
//						printf("%d ", grp[i][j]);
//					}//for-j
//					printf("\n");
//				}//for-i
//				printf("\n");								
//				for (int i = 0; i < n; i++) {
//					for (int j = 0; j < m; j++) {
//						printf("%d ", wei[i][j]);
//					}//for-j
//					printf("\n");
//				}//for-i
				break;
			}//if-1
			grow();
//			printf("*************************\n");
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < m; j++) {
//					printf("%d ", grp[i][j]);
//				}//for-j
//				printf("\n");
//			}//for-i
//			printf("\n");
//							
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < m; j++) {
//					printf("%d ", wei[i][j]);
//				}//for-j
//				printf("\n");
//			}//for-i			
//			printf("*************************\n");
////			if (growCheck() == 0) {//실수!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
////				for (int i = 0; i < n; i++) {
////					for (int j = 0; j < m; j++) {
////						ct[grp[i][j]]++;
////					}//for-j
////				}//for-i
////	
////				printf("#%d ", tt);
////				for (int i = 1; i <= 10; i++) {
////					printf("%d ", ct[i]);
////				}
////				printf("\n");
////				printf("\n");
////				printf("\n");
////				for (int i = 0; i < n; i++) {
////					for (int j = 0; j < m; j++) {
////						printf("%d ", grp[i][j]);
////					}//for-j
////					printf("\n");
////				}//for-i
////				printf("\n");
////				printf("\n");				
////				for (int i = 0; i < n; i++) {
////					for (int j = 0; j < m; j++) {
////						printf("%d ", wei[i][j]);
////					}//for-j
////					printf("\n");
////				}//for-i
////				break;
////			}//if-1
	
		}//while
	}//for-tt

	return 0;
}//main

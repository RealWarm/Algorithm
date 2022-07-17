#include<iostream>
#include<cstring>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int grp[60][60];
int wei[60][60];
int ct[20];//������ ������ �������� ������� �迭 
int n, m;

void spread() {
	// ���ڶ� �����̶�� �������� ���ڸ� �ѷ����ڴ�. 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {						
			if (grp[i][j] > 0 && wei[i][j] == grp[i][j]) { 						
				// ���ڶ�!!!!!!!!!! �����̶��
				// grp[i][j]>0 && wei[i][j]>0 : ����
				// grp[i][j]>0 && wei[i][j]==0  : ���� 
				for (int k = 0; k < 4; k++) {
					int ntx = i + dx[k];
					int nty = j + dy[k];
					if (ntx < 0 || nty < 0 || ntx >= n || nty >= m) continue;
					if (grp[ntx][nty] == 0) {//�� �����̸� 
						//���ڸ� �Ѹ��� 						
						grp[ntx][nty] = grp[i][j];
					}else if (grp[ntx][nty] != 0) {//������� �ƴ϶��						
						if (grp[ntx][nty] > 0 && wei[ntx][nty] > 0) {//������ ��� ��������. 
							continue;
						}else if (grp[ntx][nty] > 0 && wei[ntx][nty] == 0) {//�����ϰ�� 
							if (grp[ntx][nty] >= grp[i][j]) {//������ ũ�Եɳ��̸� �Ѿ 
								continue;
							}else if (grp[ntx][nty] < grp[i][j]) {//������ �������̸� ����! 
								grp[ntx][nty] = grp[i][j];
							}
						}//if-3 						
					}//if-2 					
				}//for-k
				
			}//if-1		
		}//for-j
	}//for-i

}//spread

void grow() {//���ڶ��� ���� ������ ��� "1"��ŭ �����Ų��. 
//	printf("grow :: invoked!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grp[i][j] > 0 && grp[i][j] > wei[i][j]) {
				//�� �ڶ������� Ű�� 1��ŭ Ű���.
				wei[i][j]++;
			}//if 
		}//for-j
	}//for-i

}//grow

int growCheck() {//�� �ڶ��� ���� ������ ���� ��� >> 1 ��ȯ 
				 //��� �ڶ��ٸ� >> 0 ��ȯ		
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
					//������ �ʱ⿡ "1"�� Ű�� ���´�. 
					wei[i][j] = 1;//�Ǽ�!!!!!!!!!!!!!!!!!!!! 
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
			
			// �Ǽ� : ����������� ������ �־���. 
			spread();
			if (growCheck() == 0) {//�Ǽ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
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
////			if (growCheck() == 0) {//�Ǽ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
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

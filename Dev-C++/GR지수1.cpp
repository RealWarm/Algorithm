//Ư���� ������� �ʴ��� ������ �� �ִ� ��츦 ���Ծ��׿�
//�ٸ� �κ��� �� �Ѱ� ���ƿ�~
#include<iostream> 
#include<cstring>
using namespace std;
int grp[10][20];
int map[10][20];
int ch[10][2];	// �ٲ����ǹ�ȣ, �ٲܼ���. 
int p, n, k;	// ������, �����ڼ�, ����� ���ѹ����� 
int r, flag;		// ������ �ٲܰ��� 
//�������Ǽ�(n) == ����
//�����Ǽ�(p) 	== ���� 

void test(int ttt[10][20]){		
	for(int j=0; j<n; j++){
		//���(y��)�� ���ϰ�
		int gman=1; //�ڽ����� ��¼��� ����
		for(int i=0; i<p-1; i++){//���� ��ȣ >> ���� 
			if(ttt[i+1][j]>=ttt[i][j]){//����Ѵٸ�				
				++gman;
				if(gman==k){
					break;//�����ϴ� ��¼��� �ִ� �ٷ� ���� ����� üũ�Ѵ�. 
				}//if-2 
			}else{// ������� �ʴ´ٸ� 
				gman=1;
			}//if-1
		}//for-i
		if(gman<k){
			return;// �ѻ���̶� ���� ���ϸ� "1"��ȯ 
		}//if-1 
	}//for-j	 
	flag=1;// ��� �����ϸ� "0"��ȯ 
}//check

void get(int x){
	
	if(flag==1) return;
	
	if(x>=r){
		memcpy(map, grp, sizeof(map));
		for(int i=0; i<r; i++){
//			printf("%d������ %d�� �ٲ۴�.\n", ch[i][0], ch[i][1]);
			for(int j=0; j<n; j++){
				map[ch[i][0]][j]=ch[i][1];// �ش����� �ش簪���� �ٲ۴�. 
			}//for-j
		}//for-i
		
		test(map);
	}else{
		for(int i=0; i<p; i++){//���° ���� �ٲ��� ���Ѵ�.		
			if(x==0 || ch[x-1][0]<i){ //�ټ��ÿ��� �ߺ��� ���ְڴ�. 				
				ch[x][0]=i; //������� �ٲܰŰ� 
				for(int j=2; j<=6; j++){//������ �󸶷� �ٲܰ������Ѵ�.
					ch[x][1]=j; //�� ���� �ش簪���� �ٲٰڴ�.
					get(x+1);
				}//for-j			
			}//if			
		}//for-i
	}//if	
	
}//get

int main(){
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		flag=0;
		memset(grp, 0, sizeof(grp));
		scanf("%d %d %d", &p, &n, &k);
		for(int i=0; i<p; i++){
			for(int j=0; j<n; j++){
				char t; scanf(" %c", &t);
				int temp;
				if(t=='S'){
					temp=6;
				}else if(t=='A'){
					temp=5;
				}else if(t=='B'){
					temp=4;
				}else if(t=='C'){
					temp=3;
				}else if(t=='D'){
					temp=2;
				}else if(t=='F'){
					temp=1;
				}
				grp[i][j]=temp;
			}//for-j
		}//for-i
		test(grp);
//		if(flag==1){
//			printf("#%d 0\n");
//			return 0;
//		}
		int knum=-111111;
		for(int i=0; i<=p; i++){
			r=i; //�ٲ����� ���� 
			get(0);
			if(flag==1){
				knum=i;	
//				printf("\n\n");
//				for(int j=0; j<r; j++){
//					printf("R::%d %d %d������ %d�� �ٲ۴�.\n", r,j, ch[j][0], ch[j][1]);
//				}//for-i
//				printf("\n\n");
//				for(int a=0; a<p; a++){
//					for(int b=0; b<n; b++){
//						printf("%d ", grp[a][b]);
//					}
//					printf("\n");
//				}
//				printf("\n\n");
//				for(int a=0; a<p; a++){
//					for(int b=0; b<n; b++){
//						printf("%d ", map[a][b]);
//					}
//					printf("\n");
//				}
				break; 
			}//if
		}//for-i
	
		printf("#%d %d\n", tt, knum);
	}//for-tt
	
	return 0;
}//main

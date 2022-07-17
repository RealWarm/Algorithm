//특강이 진행되지 않더라도 만족할 수 있는 경우를 빼먹었네요
//다른 부분은 잘 한것 같아요~
#include<iostream> 
#include<cstring>
using namespace std;
int grp[10][20];
int map[10][20];
int ch[10][2];	// 바꿀줄의번호, 바꿀숫자. 
int p, n, k;	// 문제수, 수강자수, 기쁨을 위한문제수 
int r, flag;		// 몇줄을 바꿀건지 
//수상자의수(n) == 가로
//문제의수(p) 	== 세로 

void test(int ttt[10][20]){		
	for(int j=0; j<n; j++){
		//사람(y축)을 정하고
		int gman=1; //자신포함 상승선의 길이
		for(int i=0; i<p-1; i++){//문제 번호 >> 주의 
			if(ttt[i+1][j]>=ttt[i][j]){//상승한다면				
				++gman;
				if(gman==k){
					break;//만족하는 상승선이 있다 바로 다음 사람을 체크한다. 
				}//if-2 
			}else{// 상승하지 않는다면 
				gman=1;
			}//if-1
		}//for-i
		if(gman<k){
			return;// 한사람이라도 만족 못하면 "1"반환 
		}//if-1 
	}//for-j	 
	flag=1;// 모두 만족하면 "0"반환 
}//check

void get(int x){
	
	if(flag==1) return;
	
	if(x>=r){
		memcpy(map, grp, sizeof(map));
		for(int i=0; i<r; i++){
//			printf("%d번줄을 %d로 바꾼다.\n", ch[i][0], ch[i][1]);
			for(int j=0; j<n; j++){
				map[ch[i][0]][j]=ch[i][1];// 해당줄을 해당값으로 바꾼다. 
			}//for-j
		}//for-i
		
		test(map);
	}else{
		for(int i=0; i<p; i++){//몇번째 줄을 바꿀지 정한다.		
			if(x==0 || ch[x-1][0]<i){ //줄선택에서 중복을 없애겠다. 				
				ch[x][0]=i; //몇번줄을 바꿀거고 
				for(int j=2; j<=6; j++){//그줄을 얼마로 바꿀건지정한다.
					ch[x][1]=j; //그 줄을 해당값으로 바꾸겠다.
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
			r=i; //바꿀줄의 갯수 
			get(0);
			if(flag==1){
				knum=i;	
//				printf("\n\n");
//				for(int j=0; j<r; j++){
//					printf("R::%d %d %d번줄을 %d로 바꾼다.\n", r,j, ch[j][0], ch[j][1]);
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

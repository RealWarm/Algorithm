#include<iostream> 
#include<cstring>
using namespace std;
int grp[9][16];
int temp[9][16];
int bok[16];
int ans[10];//몇번째 문제를 풀었는지 체크하자. 
int n, m, k, r, ps;

int check(int ttt[9][16]){
	//모든 사람이 k개의 상승선이 있는지 확인하는 함수
	//사람 >> 수업 >> 사람 >> 수업 
	//사람이 정해지면 수업을 체크하면서 상승선을 체크한다.
	//상승하면 gman을 1씩 증가시킨다
	//만약 gman이 sf이면 다음 사람을 테스트 한다.
	//만약 해당 사람이 sf를 만족하지 못하면 return 1을 함으로 함수를 종료시킨다. 	
	for(int j=0; j<m; j++){//사람(y축)을 정하고
		int gman=1;//자신포함 상승선의 길이
		for(int i=0; i<n-1; i++){//문제 번호 >> 주의 
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
			return 1;// 한사람이라도 만족 못하면 "1"반환 
		}//if-1 
	}//for-j	 
	return 0;// 모두 만족하면 "0"반환 
}//check

void boku1(int ttt[9][16], int i){
	//i번째 줄을 6으로 바꾸기 전에 임시 저장한다. 
	for(int a=0; a<m; a++){
		bok[a]=ttt[i][a];
	}//for-a
}//boku1

void boku2(int ttt[9][16], int i){
	//6으로 바꿨던 i번째 줄을 다시 원상복구 시킨다. 
	for(int a=0; a<m; a++){
		ttt[i][a]=bok[a];
	}//for-a
}//boku2

void fill(int ttt[9][16], int i){
	//ttt 배열의 i번째 줄을 6(s)으로 가득 채우겠다. 
	for(int a=0; a<m; a++){
		ttt[i][a]=6;
	}//for-a
}//fill

void get(int ttt[9][16], int x, int nn){
	// r개의 줄중에서 x번째 줄을 변경하고
	// x+1째 줄변경 함수를 호출한다. 
	if(ps==1) return;
	
	if(x>=r){
		if(check(ttt)==0){
			ps=1;			
		}		
	}else{
		for(int i=nn; i<k; i++){//중복을 없애겠다. 
			if(ans[i]==0){
				ans[i]=1;
				boku1(ttt, i);
				fill(ttt, i);
				get(ttt, x+1, nn);//nn+1도 되지 않을까????????? 
				ans[i]=0;
				boku2(ttt, i);
			}//if-2
		}//for-i
	}//if-1
	
}//get


int main(){
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){		
		memset(grp, 0, sizeof(0));
		///////////////////////////////////////////////////////////////////////////////
		//입력 값 저장 >> 문자를 숫자로 바꿔서 저장함. 
		scanf("%d %d %d", &n, &m, &k);	
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
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
	///////////////////////////////////////////////////////////////////////////////
		for(int i=0; i<=n; i++){//i개의 특강를 넣어보겠다. 
			if(i==0){//특강을 하나도 안넣음 
				if(check(grp)==0){//첨부터 모든 사람이 모든 조건을 만족했다면
					printf("#%d 0\n", tt);
					break;
				}//if
			}else{
				r=i;//넣을 특강의 갯수 
				get(grp, 0, 0);
				if(ps==1){
					printf("#%d %d", tt, i);
					break;
				}//if 
			}//if-else
		}//for-i
		
	}//for-tt	
	
	return 0;
	
}//main

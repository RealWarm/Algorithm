#include<iostream> 
#include<vector>
#include<queue>
using namespace std;
int wei[500010]; 	// 채널 방문까지 걸린 시간 
int broken[10];
int n, m; 			// 이동하려는 채널, 고장난 버튼의 갯수 

int ch(int leng){
	// 해당숫자에 안되는 숫자가 없으면 숫자의 길이를 반환한다.
	// 안되는 숫자가 있다면 -1 을 반환한다.
	int slen=0;
	
	while(leng!=0){
		int nwx=leng%10;
		for(int i=0; i<v1.size(); i++){
			if(v1[i]==nwx){
				return -1;
			}//if
		}//for-i
		leng/=10;
		slen++;
	}//while
	
	return slen;
}//ch

int check(int n) {
	// 이동하려는 채널이 주어졌을 때 
	// 리모콘을 클릭하는 횟수를 반환한다. 
	if(n==0){
		if(broken[0]){
			return 0;
		}else{
			return 1;
		}//if-2
	}//if-1
	
	int len=0;
	while(n>0){
		if(broken[n%10])return 0;
		n = n/10;
		lne += 1;
	}//while
	return len;	
}//check


int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a; scanf("%d", &a);
		broken[a]=1;
	}//for-i
	/////////////////////////////////////////
	
		
	return 0;
}//main

// N (이동하려는 채널)
// M (고장난 버튼의 개수)
// 고장난 버튼 

// 이동 가능한곳 
// + - 
// 누를 수 있는 버튼중 >>  목표값에 최대한 가깝게 가보기
// 할 수 있는 방법 
// 1. 번호 누르기  
// 지금번호 중에서 안되는 번호가 있니?
// 없다면 해당자리의 길이 만큼으로 거리값 채우기
// 안된다면 -1 채우기 

// 2. 위 아래 버튼 눌러보기

// 5000000 까지에서 안되는 버튼이 들어있는 번호들을 거르기
// 아니라면

// 힌트 :: 이동하고 버튼으로 움직이기 



















 
















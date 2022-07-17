#include<iostream> 
using namespace std;
const int MAX=100005;
int data[MAX];
int n, s;

int check(int interval){
	// 구간의 길이가 interval일때, 합이 S 이상인 경우가 있는가?
	// 있으면 1, 없으면 0
	int sum=0;
	
	for(int i=0; i<interval; i++){
		sum+=data[i];
	}//for-i
	
	if(sum>=s) return 1;
	////////////////////////////////////////////
	for(int i=0; i<n-interval; i++){
		sum = sum -data[i]+data[i+interval];
		
		if(sum>=s) return 1;
	}//for-i
	
	return 0;
}//check

int main(){
	
	scanf("%d %d", &n, &s);
	for(int i=0; i<n; i++){
		scanf(" %d", &data[i]);
	}//for-i
	
	if(check(1)==1){
		printf("1개의 구간으로 된다\n");
		return 0;
	}
	if(check(n)==0){
		printf("만족하는 구간이 없습니다.\n");
		return 0;
	}	
	//////////////////////////////////////////
	int start=1; // start는 무조건 X를 가르킴 
	int end=n;	 //   end는 무조건 O을 가리킴 
	while(start+1 < end){
		int mid=(start+end)/2;
		
		if(check(mid)==1){
			// 구간이 만족한다면 
			end=mid;
		}else if(check(mid)==0){
			//구간이 만족하지 않다면
			start=mid;
		}//if
	}//while
	
	printf("%d\n", end);	
	
	return 0;
}//main



//9 16
//2 1 8 1 3 7 2 6 3






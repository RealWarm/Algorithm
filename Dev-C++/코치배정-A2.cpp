#include<iostream> 
#include<algorithm>
#include<cstring> 
#include<vector>
using namespace std;
int qnum[20];	// 질문의수 
int ch[20];		// 그룹배열 
int n, k ,t;	// 수강생의 수, 선택할 학생의수, 궁금한경우의수 
int ansum, sum;
int flag, cnt;


void get(int x){
	
	if(flag==1)return;
	
	if(x>=k){
		cnt++;		
		if(cnt==t){
			for(int i=0; i<k; i++){
				sum+=qnum[ch[i]];
			}
			flag=1;
		}//for
	
	}else{
		for(int i=0; i<n; i++){
			if(x==0 || ch[x-1]<i){
				ch[x]=i;
				get(x+1);
			}//if
		}//for-i
	}//if	
}//get

int main(){	
	scanf("%d %d %d", &n, &k, &t);
	for(int i=0; i<n; i++){
		scanf("%d", &qnum[i]);
	}
	get(0);
	printf("%d", sum);
	return 0;
}//main

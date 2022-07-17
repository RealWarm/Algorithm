#include <iostream>
#include <vector> 
using namespace std;
int wei[210][210];
int chk[210][210];
int seq[1010];
int flag; // 만족한 경우가 하나라도 있니? 
int n, m; // 도시의 수, 간선수

void dfs(int x, int s){ // 현재 방문한점, 순서를 만족한 길이 

	if(flag==1) return;
	if(s>=m){
		flag=1;
	}else{
		for(int i=1; i<=n; i++){
			if(wei[x][i]==1 && i==seq[x]){
				dfs(i, s+1);
			}else if(wei[x][i]==1){
				dfs(i, s);
			}//if
		}//for-i		
	}//if
	
}//dfs

int main(){
	scanf(" %d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			scanf(" %d", &wei[i][j]);
		}//for-j
	}//for-i
	///////////////////////////////////////////
	for(int i=0; i<m; i++){
		scanf(" %d", &seq[i]);
	}//for-i
	///////////////////////////////////////////
	dfs(seq[0], 1);
	///////////////////////////////////////////
	printf("%s\n", flag==0 ? "NO" : "YES");
	///////////////////////////////////////////
	return 0;
}//main







































#include<cstdio>
#include<vector>
using namespace std;
int n, m; // n : 정점의 개수   m : 간선의 개수 
vector<int> arr[1010];
int wei[1010];

void dfs(int x, int c){
	wei[x]=c;
	
	for(int i=0; i<arr[x].size(); i++){
		int ntx = arr[x][i];
		if(wei[ntx]==0){
			wei[ntx]=1;
			dfs(ntx, c*-1);
		}//if
	}//for-i
	
}//dfs

int main(){
		
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<m; i++){
		int a, b; scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}//for-i
	
	for(int i=1; i<=n; i++){
		if(wei[i]==0){
			dfs(i, 1);
		}
	}//for-i
	
	
	int flag=1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<arr[i].size(); j++){
			if(wei[i]==wei[arr[i][j]]){
				flag=0;
			}
		}
	}
	
	printf("%s", flag ? "Yes":"No");
	
	return 0;
}//main

// 그래프를 저장한다.
// 그래프의 모든 정점을 탐색한다.
// 어디서 부터 어디까지 이지? 

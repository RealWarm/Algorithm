#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int arr[1010][1010];
int wei[1010];
vector<int> grp[1010];
int n, m;//세로, 가로 

void dfs(int x){
	wei[x]=1;
	printf("%d", x);
	
	for(int i=0; i<m; i++){	
			
	}	
	
}//dfs

int main(){
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	
	dfs(0);
	printf("\n");
	bfs(0);
	
	return 0;
}

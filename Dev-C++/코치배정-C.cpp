#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<int> arr[30];
int ans[35];
int wei[30];
int n, m, e, cnt;

void dfs(int x, int c){
	wei[x]=1;
	cnt++;
	
	for(int i=0; i<arr[x].size(); i++){
		int ntx = arr[x][i];
		if(wei[ntx]==0 && ans[ntx]==c){			
			dfs(ntx, c);
		}//if
	}//for-i	
}//bfs

int main(){
	
	scanf("%d %d %d", &n, &m, &e);	
	if(n==m){
		printf("0\n");
		return 0;
	}
	for(int i=0; i<m; i++){
		char ch; scanf(" %c", &ch);
		ans[ch-'A']=1;		
	}//for-i
	
	for(int i=0; i<e; i++){
		char qq, ww; scanf(" %c %c", &qq, &ww);
		int a = qq -'A';
		int b = ww -'A';		
		arr[a].push_back(b);
		arr[b].push_back(a);
	}//for-i
	
	for(int i=0; i<n; i++){
		if(ans[i]==1){
			dfs(i, ans[i]);
			//왜 여기다? 
			if(cnt < m){
				printf("0\n");
				return 0;
			}//if-2	
			break;	
		}//if-1					
	}//for-i
	
	cnt=0;
	memset(wei, 0, sizeof(wei));
	for(int i=0; i<n; i++){
		if(ans[i]==0){
			dfs(i, ans[i]);
			//왜 여기다? 
			if(cnt < (n-m)){			
				printf("0\n");
				return 0;
			}//if-2	
			break;	
		}//if-1			
	}//for-i
	
	printf("1\n");
	
	return 0;
}//main

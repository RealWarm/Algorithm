#include<iostream>
#include<vector>
using namespace std;
vector<int> arr[30];
int ans[35];
int wei[30];
int n, m, e, cnt;

void dfs(int x){
	wei[x]=1; cnt++;	
	for(int i=0; i<arr[x].size(); i++){
		int ntx = arr[x][i];
		if(wei[ntx]==0 && ans[ntx]==1){		
			dfs(ntx);
		}//if
	}//for-i	
}//bfs

int main(){
	
	scanf("%d %d %d", &n, &m, &e);
	int as=0;
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
			dfs(i);
			//왜 여기다? 
			if(cnt == m){
				printf("1\n");
				return 0;
			}else{
				printf("0\n");
				return 0;
			}//if-2		
		}//if-1			
		
	}//for-i	
	
	return 0;
}//main



















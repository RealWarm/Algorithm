#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<int> arr[15];
int memo[15];
int ans[15];
int wei[15];
int n, m, cnt, mmin=99999999;

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
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int aa; scanf("%d %d", &memo[i], &aa);
		for(int q=0; q<aa; q++){
			char ch; scanf(" %c", &ch);
			arr[i].push_back(ch-'A');
			arr[ch-'A'].push_back(i);
		}//for-q
	}//for-i
	
	int qt; scanf("%d", &qt);		// 테스트 케이스 	
	int flag;						// 효율적인지 기록하는  	
	for(int qq=0; qq<qt; qq++){
		flag=0;
		cnt=0;
		memset(wei, 0, sizeof(wei));
		memset(ans, 0, sizeof(ans));
		scanf("%d", &m);		
		for(int i=0; i<m; i++){
			char ch; scanf(" %c", &ch);
			ans[ch-'A']=1;		
		}//for-i
		
		if(n==m){
			continue;
		}
		
		for(int i=0; i<n; i++){
			if(ans[i]==1){
				dfs(i, ans[i]);			
				if(cnt < m){
					flag=1;					
				}//if-2	
				break;	
			}//if-1					
		}//for-i
		if(flag==1) continue;
		
		cnt=0;
		memset(wei, 0, sizeof(wei));
		for(int i=0; i<n; i++){
			if(ans[i]==0){
				dfs(i, ans[i]);			
				if(cnt < (n-m)){			
					flag=1;
				}//if-2	
				break;	
			}//if-1			
		}//for-i
		
		if(flag==1) continue;
		else{			
			int at=0, st=0;
			for(int i=0; i<n; i++){
				if(wei[i]==0){
					at+=memo[i];
				}else{
					st+=memo[i];
				}//if
			}//for-i
			
			int result=abs(at-st);
			if(mmin>result){
				mmin=result;
			}//if
		}//if
		
	}//for-qq
	
	if(mmin==99999999) printf("-1\n");
	else printf("%d\n", mmin);
	
	return 0;
}//main

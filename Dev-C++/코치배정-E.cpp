#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<int> arr[15];
int ch[20];	//재귀 
int ans[15];
int wei[15];
int n, m, cnt, mmin=99999999, flag, total;

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

void get(int x){
	//pp[x]를 정한 뒤에 pp[x+1]을 정한다.
	//n명 중에서 m명을 선택한다.  	
	if(x==m){		
		flag=0;
		cnt=0;
		memset(wei, 0, sizeof(wei));
		memset(ans, 0, sizeof(ans));		
		for(int i=0; i<m; i++){			
			ans[ch[i]]=1;		
		}//for-i
		
		if(n==m){
			return;
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
		if(flag==1) return;
		
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
		
		if(flag==1) return;
		else{//		
			total++;
		}//if-2
				
	}else{
		for(int i=0; i<n; i++){
			if(x==0 || ch[x-1]<i){
				ch[x]=i;
				get(x+1);
			}//if-2
		}//for-i
	}//if-1
}//get

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int aa; scanf("%d", &aa);
		for(int q=0; q<aa; q++){
			char ch; scanf(" %c", &ch);
			arr[i].push_back(ch-'A');
			arr[ch-'A'].push_back(i);
		}//for-q
	}//for-i
	
	for(int i=1; i<n; i++){
		m=i;
		get(0);	
	}	
	
	printf("%d\n", total);
		
	return 0;
}//main

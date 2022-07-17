#include<iostream> 
#include<cstdio>
#include<vector> 
#include<queue>
using namespace std;
vector<int> grp[1010];
queue<int> q1;
int clr[1010];

int dfs(int x, int color){
	//Å½»öÀ» ÇÑ´Ù. 
	//»öÀ» ¹Ù²ã¼­ Ä¥ÇÑ´Ù. 
	clr[x]=color;
	if(color==1){
		color = 0;
	}else if(color==0){
		color = 1;
	}//if-1
	for(int i=0; i<grp[x].size(); i++){
		int nwx = grp[x][i];
		if(clr[nwx]==0){
			if(dfs(nwx, color)==1){
				return 1;				
			}else {
				return 0;
			}
		}else if(clr[nwx]!=color){			
			return 1;
		}
	}//for-i	
}//dfs

int main(){
	
	int n, m; scanf("%d %d", &n, &m); // n:Á¤Á¡ÀÇ °¹¼ö, m: °£¼±ÀÇ °¹¼ö
	
	while(m--){
		int a, b; scanf("%d %d", &a, &b);
		grp[a].push_back(b);
		grp[b].push_back(a);		
	}//while
	
	if(dfs(0,1)==0){
		printf("Yes");
	}else{
		printf("No");
	}	
	return 0;
}//main

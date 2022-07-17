#include <iostream>
#include <vector>
using namespace std;
vector<int> grp[1010];
int wei[1010];
int n, m; // Á¤Á¡ÀÇ °¹¼ö, °£¼±ÀÇ °¹¼ö 

void dfs(int x, int color){
	wei[x]=color;
	for(int i=0; i<grp[x].size(); i++){
		int ntx = grp[x][i];
		if(wei[ntx]==0){			
			dfs(ntx, color*-1);
		}	
	}//for-i	
}//dfs

int main(){
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a, b; scanf("%d %d", &a, &b);
		grp[a].push_back(b);
		grp[b].push_back(a);
	}//for-i
	////////////////////////////////////////
	for(int i=1; i<=n; i++){
		if(wei[i]==0){
			dfs(i, 1);
		}//if 
	}//for-i
	////////////////////////////////////////
	bool flag=true;
	for(int i=1; i<=n; i++){
		for(int j=0; j<grp[i].size(); j++){
			int ntx=grp[i][j];
			if(wei[i]==wei[ntx]){
				flag=false;
			}
		}
	}//for-i	
	printf("%s", flag ? "Yes":"No");	
	return 0;
}//main





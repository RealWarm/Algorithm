#include <iostream>
#include <vector> 

using namespace std;
vector<vector<int> > grp;
vector<int> wei;
int n, m; 

void dfs(int x, int c){
	wei[x]=c;
	for(int i=0; i<grp[x].size(); i++){
		int ntx=grp[x][i];
		if(wei[ntx]==0){
			dfs(ntx, 3-c);
		}//if
	}//for-i
}//dfs

int main(){
	scanf("%d %d", &n, &m);
	grp.resize(n);
	wei.resize(n);
	for(int i=0; i<m ;i++){
		int a, b; scanf("%d %d", &a, &b);
		a--, b--;
		grp[a].push_back(b);
		grp[b].push_back(a);
	}//for-i
	//////////////////////////////////////////
	for(int i=0; i<n; i++){
		if(wei[i]==0){
			dfs(i, 1);
		}//if
	}//for-i
	//////////////////////////////////////////
	int flag=0;
	for(int i=0; i<n; i++){
		if(flag==1) break;
		for(int j=0; j<grp[i].size(); j++){
			if(wei[i]==wei[grp[i][j]]){
				flag=1;
				break;
			}//if
		}//for-j
	}//for-i
	//////////////////////////////////////////
	printf("%s\n", flag==0 ? "Yes" : "No");
	
	return 0;
}//main


//	for(int i=0; i<n; i++){
//		printf("%d :: ", i);
//		for(int j=0; j<grp[i].size(); j++){
//			printf("%d ", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i

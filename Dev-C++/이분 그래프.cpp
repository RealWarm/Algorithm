#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
vector<int> grp[20010];
int wei[20010];
int flag;

void dfs(int x, int c){
	wei[x]=c;
	for(int i=0; i<grp[x].size(); i++){
		int ntx=grp[x][i];
		if(wei[ntx]==0){
			wei[ntx]=c;
			dfs(ntx, 3-c);
		}//if		
	}//for-i	
}//dfs

int main(){
	int k; scanf("%d", &k); // 테스트 케이스	
	for(int i=0; i<k; i++){
		for(int t=0; t<20010; t++){
			grp[t].clear();
		}//for-t
		memset(wei, 0, sizeof(wei));
				
		int v,e; scanf("%d %d", &v, &e); // 정점의 갯수, 간선의 갯수 		 
		for(int a=0; a<e; a++){
		 	//인접리스트 만들기 
		 	int aa, b; scanf("%d %d", &aa, &b);
		 	grp[aa].push_back(b);
		 	grp[b].push_back(aa);
		}//for-a
		//////////////////////////////////////////////		
		for(int a=1; a<=v; a++){
		 	if(wei[a]==0){
		 		dfs(a, 1);
			}//if
		}//for-a
		//////////////////////////////////////////////
		int flag=0;
		for(int a=1; a<=v; a++){
			if(flag==1) break;
			for(int b=0; b<grp[a].size(); b++){
				if(wei[a]==wei[grp[a][b]]){
					flag=1;
					break;
				}//if
			}//for-b
		}//for-a
		
		if(flag==1){
			printf("NO\n");
		}else{
			printf("YES\n");
		}//if
		
	}//for-i
	
	return 0;
}//main

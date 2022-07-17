#include<iostream>
#include<queue>
#include<vector> 
using namespace std;
int n, bg; //지점의 수, 배정받은 예산 
vector<int> grp[110]; // 간선 그래프
int wei[110];


//def dfs(n, table, visited, distances):
//	if len(table[n]) == 1 and n != 0:
//	    distances[n] = 1
//	    return 1
//	
//	visited[n] = True
//	temp = 0
//	for j in table[n]:
//	    if visited[j] == False:
//	        temp += dfs(j, table, visited, distances)
//	distances[n] = temp
//	return temp
	
int dfs(int x){
	
	int tmp=0;
	for(int i=0; i<grp[x].size(); i++){
		int ntx=grp[x][i];
		if(wei[ntx]==0){		
			wei[ntx]=1;
			tmp+=dfs(ntx);			
		}//if
	}//for-i
	wei[x]=tmp;
	
	if(tmp==0){
		wei[x]=1;
		return 1;		
	}else{
		return tmp;	
	}
	
}//dfs	

int main(){
	scanf("%d %d", &n, &bg);	
	for(int i=0; i<n-1; i++){
		int a, b; scanf("%d %d", &a, &b);
		grp[a].push_back(b);
		grp[b].push_back(a);
	}//for-i
	/////////////////////////////////////////////
	wei[1]=987987;
	wei[1]=dfs(1);
	/////////////////////////////////////////////
	int sum=0;
	for(int i=1; i<=n; i++){
//		printf("%d ", wei[i]);
		sum+=wei[i];
	}//for-i
//	printf("\n");
	/////////////////////////////////////////////
	if(bg%sum==0){
		printf("%d \n", bg/sum);
	}else{
		printf("-1 \n");
	}
	return 0;
}//main


//void dfs(int x){
//	for(int i=0; i<grp[x].size(); i++){
//		int ntx=grp[x][i];
//		if(wei[ntx]==0){
//			wei[ntx]=wei[x]+1;
//			if(mmax<wei[ntx]){
//				mmax=wei[ntx];
//			}
//			dfs(ntx);
//		}//if
//	}//for-i	
//}//dfs



//for(int i=0; i<n+1; i++){
//	cout << i << " ";
//	for(int j=0; j<grp[i].size(); j++){
//		cout << grp[i][j] << " ";
//	}//for-j
//	printf("\n");
//}//for-i


//void bfs(int x){
//	wei[x]=1;
//	q1.push(x);
//	
//	while(!q1.empty()){
//		int nwx=q1.front();
//		q1.pop();
//		for(int i=0; i<grp[nwx].size(); i++){
//			int ntx=grp[nwx][i];
//			if(wei[ntx]==0){
//				wei[ntx]=wei[nwx]+1;
//				q1.push(ntx);
//				if(mmax<wei[ntx]){
//					mmax=wei[ntx];
//				}//if
//			}//if
//		}//for-i		
//	}//while	
//}//bfs

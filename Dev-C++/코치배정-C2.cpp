#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n, m, e;//학생의수, 코치가 배정받을 학생수, 간선의수 
queue<int> q1;
vector<int> grp[20];
int ch[20];
int wei[20];

void bfs(int x, int c){
	wei[x]=c;
	q1.push(x);
	
	while(!q1.empty()){
		int nwx=q1.front();
		q1.pop();
		for(int i=0; i<grp[nwx].size(); i++){
			int ntx=grp[nwx][i];
			if(wei[ntx]==-1 && ch[ntx]==c){
				wei[ntx]=c;
				q1.push(ntx);
			}//if
		}//for-i
	}//while	
}//bfs

int main(){
	
	scanf("%d %d %d", &n, &m, &e);
	for(int i=0; i<m; i++){
		char tch; scanf(" %c", &tch);
		ch[tch-'A']=1;
	}//for-i	
	for(int i=0; i<e; i++){
		char st, ed; scanf(" %c %c", &st, &ed);
		st-='A'; ed-='A';
		grp[st].push_back(ed);
		grp[ed].push_back(st);
	}//for-i
	if(n==m){
		printf("0\n");
		return 0;
	}
	///////////////////////////////////////////////////////////////////
	memset(wei, -1, sizeof(wei));
	for(int i=0; i<n; i++){
		if(ch[i]==1){
			bfs(i, 1);
			break;
		}//if
	}//for-i
	////////////////////////////////////////////////////////////////
	for(int i=0; i<n; i++){
		if(ch[i]==0){
			bfs(i, 0);
			break;
		}//if
	}//for-i
	///////////////////////////////////////////////////////////////////
	int flag=0;
	for(int i=0; i<n; i++){ /// m이 아니라 n이 정답 
		if(ch[i]==1 && wei[i]==-1){			
			flag=1;
			break;
		}
		if(ch[i]==0 && wei[i]==-1){
			flag=1;
			break;
		}
	}//for-i
	
	if(flag==0) printf("1\n");
	else if(flag==1) printf("0\n");
			
	return 0;
}//main

















//	for(int i=0; i<n; i++){
//		printf("%2d ", ch[i]);
//	}//
//	printf("\n");
//	for(int i=0; i<n; i++){
//		printf("%2d ", wei[i]);
//	}//
//	printf("\n");


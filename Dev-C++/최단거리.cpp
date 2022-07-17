#include<iostream> 
#include<vector>
#include<queue>
using namespace std;
int n, m; // Á¤Á¡ÀÇ °¹¼ö, °£¼±ÀÇ °¹¼ö 
int start, eend;


int main(){
	scanf("%d %d", &n, &m);
	vector<int> grp[10010];
	vector<int> wei(n, -1);
	for(int i=0; i<m; i++){
		int a, b; scanf("%d %d", &a, &b);
		grp[a].push_back(b);
		grp[b].push_back(a);
	}//for-i
	scanf("%d %d", &start, &eend);
	
	wei[start]=0;
	queue<int> q1; q1.push(start);
	while(!q1.empty()){
		int nwx=q1.front();
		q1.pop();
		
		for(int i=0; i<grp[nwx].size(); i++){
			int ntx=grp[nwx][i];
			if(wei[ntx]==-1){
				wei[ntx]=wei[nwx]+1;
				q1.push(ntx);
			}//if
		}//for-i
		
	}//while
	
	printf("%d\n", wei[eend]);
	
	return 0;
}//main








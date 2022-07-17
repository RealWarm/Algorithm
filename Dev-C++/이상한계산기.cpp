#include<iostream> 
#include<cstring>
#include<queue>
using namespace std;
int wei[100100];
queue<int> q1;
int n;

void bfs(int x){
	wei[x]=0;
	q1.push(x);
	
	while(!q1.empty()){
		int nwx=q1.front();
		q1.pop();
		int ntx=nwx*2;
		if(ntx<=99999 && wei[ntx]==-1){
			wei[ntx]=wei[nwx]+1;
			q1.push(ntx);
		}
		
		ntx=nwx/3;
		if(ntx>=1 && wei[ntx]==-1){
			wei[ntx]=wei[nwx]+1;
			q1.push(ntx);
		}		
		
		if(wei[n]!=-1) break;
		
	}//while	
}//bfs

int main(){
	
	memset(wei, -1, sizeof(wei));
	scanf("%d", &n);
	bfs(1);
	printf("%d\n", wei[n]);
	
	return 0;
}//main

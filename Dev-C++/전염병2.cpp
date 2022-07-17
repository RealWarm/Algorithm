#include<iostream>
#include<queue> 
using namespace std;
queue<int> q1;
int wei[100110];
int n;

void bfs(int x){
	wei[x]=1;
	q1.push(x);
	
	while(!q1.empty()){
		int nwx = q1.front();
		q1.pop();
		if(nwx*2<=n && wei[nwx*2]==0){
			wei[nwx*2]=wei[nwx]+1;
			q1.push(nwx*2);
		}
		if(nwx/3>0&&wei[nwx/3]==0){
			wei[nwx/3]=wei[nwx]+1;
			q1.push(nwx/3);
		}		
	}//while
	
}//bfs

int main(){
		
	int k; scanf("%d %d", &n, &k);
	bfs(k);
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(wei[i]==0){
			cnt++;	
		}		
	}
	printf("%d", cnt);
	return 0;
}//main

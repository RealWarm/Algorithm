#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int wei[100010];
queue<int> q1;

void bfs(int x){
	wei[x]=0;
	q1.push(x);
	while(!q1.empty()){
		int nwx=q1.front();
		q1.pop();
		int temp = nwx/3;
		if(wei[temp]==-1){
			wei[temp]=wei[nwx]+1;
			q1.push(temp);
		}
		temp=nwx*2;
		if(temp<100000 && wei[temp]==-1){
			wei[temp]=wei[nwx]+1;
			q1.push(temp);
		}
	}//while
	
}//bfs

int main(){
	int n; scanf("%d", &n);
	memset(wei, -1, sizeof(wei));
	bfs(1);
//	for(int i=0; i<n+10; i++){
//		printf("%d ", wei[i]);
//	}
	printf("%d ", wei[n]);	
	return 0;
}//main

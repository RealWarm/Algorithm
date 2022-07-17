#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int grp[100010];
int wei[100010];
int n; //전체 마을위 개수 
queue<int> q1;

void bfs(int x){
	q1.push(x);
	wei[x]=1;
	while(!q1.empty()){
		int nwx = q1.front();
		q1.pop();
		if(wei[nwx*2]==0 && nwx*2 <= n){
			wei[nwx*2]+=wei[nwx]+1;
			q1.push(nwx*2);
		}
		if(nwx/3 > 0 && wei[nwx/3]==0){
			wei[nwx/3]=wei[nwx]+1;
			q1.push(nwx/3);
		}
	}//while 
	
}//bfs

int main(){
	int k;
	scanf("%d %d", &n, &k);
	wei[k]=1;
	bfs(k);
	
	int sum=0;
	for(int i=1; i<=n; i++){	
		if(wei[i]==0){
			sum++;
		}
	}//for-i	
	printf("%d",sum);
	return 0;
}//main


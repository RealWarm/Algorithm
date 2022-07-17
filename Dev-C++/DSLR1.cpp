#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
vector<string> st(10010);
int wei[10010];
int a, b;

void bfs(int ss){
	queue<int> q1;
	q1.push(ss);
	wei[ss]=0;
	
	while(!q1.empty()){
		int nwx=q1.front();
		q1.pop();
		int td=(nwx*2)%10000;
		if(wei[td]==-1){
			q1.push(td);
			wei[td]=wei[nwx]+1;
			st[td]=st[nwx]+'D';
		}//if
		
		int ts=nwx-1;
		if(ts==-1) ts=9999;
		if(wei[ts]==-1){
			q1.push(ts);
			wei[ts]=wei[nwx]+1;
			st[ts]=st[nwx]+'S';
		}//if
		
		int tl=(nwx%1000)*10+nwx/1000;
		if(wei[tl]==-1){
			q1.push(tl);
			wei[tl]=wei[nwx]+1;
			st[tl]=st[nwx]+'L';
		}//if
		
		int tr=(nwx%10)*1000+(nwx/10);
		if(wei[tr]==-1){
			q1.push(tr);
			wei[tr]=wei[nwx]+1;
			st[tr]=st[nwx]+'R';
		}//if
			
	}//while	
		
	printf("%s\n", st[b].c_str());
	
}//bfs

int main(){	
	int ts; scanf("%d", &ts);
	for(int tt=0; tt<ts; tt++){
		st.clear();
		st.resize(10010);
		memset(wei, -1, sizeof(wei));
		scanf("%d %d", &a, &b);
		bfs(a);	
	}//for-tt	
	return 0;
}//main



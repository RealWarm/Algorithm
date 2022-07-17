#include<iostream>
#include<queue> 
using namespace std;
queue<pair<int, int> > q1;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[30][30];
int wei[30][30];
int n, m, ttx, tty;

int fact(int a){
	if(a==1)
		return 1;
	else
		return a*fact(a-1);
}//fact

void bfs(int x, int y){
	wei[x][y]=1;
	q1.push(make_pair(x, y));
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx= nwx+dx[k];
			int nty= nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) continue;
			if(wei[ntx][nty]==0){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}
		}//for-k			
	}//while	
}//bfs

int main(){
	
	scanf("%d %d", &n, &m);
	scanf("%d %d", &ttx, &tty);
	
	//폭탄이 (0,0)에 있거나 범위를 벗어나면, fail 
	if(ttx==0 && tty==0){
		 printf("fail\n");
		 return 0;
	}	
	if(ttx>=n || tty>=m){
		printf("fail\n");
		 return 0;
	}
	
	bfs(0,0);
	printf("%d\n", wei[ttx][tty]-1);
	int result=fact(ttx+tty)/(fact(ttx)*fact(tty)); // 순열식을 그대로사용함 
	printf("%d\n", result);
	
	return 0;
}//main

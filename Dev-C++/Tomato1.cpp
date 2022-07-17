#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int dy[]={ 0,  0, 1, 0, 0, -1};
int dx[]={ 0, -1, 0, 0, 1,  0}; // 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dz[]={-1,  0, 0, 1, 0,  0};
int grp[110][110][110];
int wei[110][110][110];
int n, m, h; // 세로 가로 높이 
struct tinx{
	int x; //세로 
	int y; //가로 
	int z; //높이 
};
queue<tinx> q1;

tinx make_p(int x, int y, int z){
	tinx tt;
	tt.x=x;
	tt.y=y;
	tt.z=z;
	return tt;
}//make_p


int main(){
	int ex=0;
	memset(wei, -1, sizeof(wei));
	scanf("%d %d %d", &m, &n, &h);
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int t=0; t<m; t++){
				scanf(" %d", &grp[i][j][t]);				
				if(grp[i][j][t]==1){
					q1.push(make_p(j, t, i));
					wei[h][j][t]=0;
				}//if
				if(grp[i][j][t]==0){
					ex=1;
				}//if
			}//for-t
		}//for-j
	}//for-i
	if(ex==0){
		//예외처리!! 
		printf("0\n");
		ex=1;
		return 0;
	}//if
	////////////////////////////////////////////////////
	while(!q1.empty()){
		int nwx=q1.front().x;		
		int nwy=q1.front().y;
		int nwz=q1.front().z;
		q1.pop();
		for(int k=0; k<6; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			int ntz=nwz+dz[k];
			if(ntx<0 || nty<0 || ntz<0 || ntx>=n || nty>=m || ntz>=h) continue;
			if(wei[ntz][ntx][nty]==-1 && grp[ntz][ntx][nty]==0){
				wei[ntz][ntx][nty]=wei[nwz][nwx][nwy]+1;
				q1.push(make_p(ntx, nty, ntz));
			}//if
		}//for-k		
	}//while
	////////////////////////////////////////////////////
	int mmax=-1; //  
	int flag=0;
	for(int i=0; i<h; i++){
		if(flag==1) break;
		for(int j=0; j<n; j++){
			if(flag==1) break;
			for(int t=0; t<m; t++){
				if(grp[i][j][t]==0 && wei[i][j][t]==-1){
					flag=1;
					break;
				}//if
				if(grp[i][j][t]==0 && wei[i][j][t]!=-1){
					if(wei[i][j][t]>mmax){
						mmax=wei[i][j][t];
					}//if
				}//if
			}//for-t
		}//for-j
	}//for-i
	
	if(flag==0){
		printf("%d\n", mmax+1);
	}else{
		printf("-1\n");
	}
	
	return 0;
}//main

// m : 상자의 가로 칸의 수 
// n : 상자의 세로 칸의 수 
// h : 쌓아 올려지는 상자의 수 



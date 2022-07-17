#include<iostream>
#include<cstring>
using namespace std;
int dx[]={-1,0,1,0};//상 우 하 좌 
int dy[]={0,1,0,-1};
int grp[6][6];
int temp[6][6];
int result[6];
int n, m;
int mmax, mnum;

void fill(int x, int y, int num, int turn){
	
	int iturn = turn%4;
	
	if(num==1){		
		//위로채운다. 
		int ntx=x;
		int nty=y;
		while(1){			
			ntx+=dx[iturn];
			nty+=dy[iturn];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
	}else if(num==2){
		int temp=0;
		int ntx=x;
		int nty=y;		
		while(1){
			ntx+=dx[iturn];
			nty+=dy[iturn];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		ntx=x;
		nty=y;
		
		if(iturn+2>3){
			temp=(iturn+2)%4;
		}else{
			temp=iturn+2;
		}
		while(1){
			ntx+=dx[temp];
			nty+=dy[temp];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
	}else if(num==3){
		int temp=0;
		int ntx=x;
		int nty=y;		
		while(1){
			ntx+=dx[iturn];
			nty+=dy[iturn];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		ntx=x;
		nty=y;
		if(iturn+1>3){
			temp=(iturn+1)%4;
		}else{
			temp=iturn+1;
		}
		while(1){
			ntx+=dx[temp];
			nty+=dy[temp];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
	}else if(num==4){	
		int temp=0;
		int ntx=x;
		int nty=y;	
		while(1){
			ntx+=dx[iturn];
			nty+=dy[iturn];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		ntx=x;
		nty=y;
		if(iturn+1>3){
			temp=(iturn+1)%4;
		}else{
			temp=iturn+1;
		}
		while(1){
			ntx+=dx[temp];
			nty+=dy[temp];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		ntx=x;
		nty=y;
		if(iturn+3>3){
			temp=(iturn+3)%4;
		}else{
			temp=iturn+3;
		}
		while(1){
			ntx+=dx[temp];
			nty+=dy[temp];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
	}else if(num==5){
		
		int ntx=x;
		int nty=y;		
		while(1){
			ntx+=dx[0];
			nty+=dy[0];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
		ntx=x;
		nty=y;		
		while(1){
			ntx+=dx[1];
			nty+=dy[1];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
		ntx=x;
		nty=y;
		while(1){
			ntx+=dx[2];
			nty+=dy[2];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
		ntx=x;
		nty=y;
		while(1){
			ntx+=dx[3];
			nty+=dy[3];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}			
		}//while
		
	}//if-else
	
}//fill

void show(int x){
	// x+1 번째가 정해지면 x번째가 정해지는 함수
			
	if(x>=mnum){
		int cnt=0;
		memcpy(grp, temp, sizeof(grp));	
		for(int i=0; i<n; i++){		
			for(int j=0; j<m; j++){
				if(temp[i][j]>=1 && temp[i][j]<=5){			
					fill(i, j, temp[i][j], result[cnt++]);							
				}//if		
			}//for-j
		}//for-i			
		
		int total=0;
		for(int q=0; q<n; q++){
			for(int w=0; w<m; w++){
				if(grp[q][w]==0) total++;
			}//for-w
		}//for-q
		if(total<mmax) mmax=total;
	}else{
		for(int i=0; i<4; i++){
			result[x]=i;
			show(x+1);
		}//for-i
	}//if-else
	
}//show

int main(){
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		memset(grp, 0, sizeof(grp));
		memset(temp, 0, sizeof(temp));
		memset(result, 0, sizeof(result));
		mmax=9999999999;
		mnum=0;
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++){	
			for(int j=0; j<m; j++){		
				scanf("%d", &temp[i][j]);
				if(temp[i][j]>=1 && temp[i][j]<=5){
					mnum++;
				}//if
			}//for-j
		}//for-i
		
		show(0);	
			
		printf("#%d %d\n", tt, mmax);		
	}//for-tt
	

	return 0;
}//main 

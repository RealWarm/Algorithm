#include<iostream>
using namespace std;
int dx[]={-1,0,1,0};//상 우 하 좌 
int dy[]={0,1,0,-1};
int grp[6][6];
int ta[10];
int n, m, k, t;

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


int main(){
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){	
		for(int j=0; j<m; j++){		
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	
	for(int i=0; i<4; i++){
		scanf("%d", &ta[i]);
	}

	
	int cnt=0;
	for(int i=0; i<n; i++){		
		for(int j=0; j<m; j++){
			if(grp[i][j]>=1 && grp[i][j]<=5){			
				fill(i, j, grp[i][j], ta[cnt]);
				cnt++;
			}//if		
		}//for-j
	}//for-i
	
//	printf("\n");printf("\n");printf("\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", grp[i][j]);
//		}
//		printf("\n");
//	}
	
	int total=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grp[i][j]==8) total++;
		}		
	}
	printf("%d", total);
	return 0;
}//main

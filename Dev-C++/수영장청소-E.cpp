#include<iostream>
#include<cstring>
using namespace std;
int dx[]={-1,0,1,0};//�� �� �� �� 
int dy[]={0,1,0,-1};
int grp[6][6];
int temp[6][6];
int n, m, k, t;

void fill(int x, int y, int num, int turn){
	
	int iturn = turn%4;
	
	if(num==1){		
		//����ä���. 
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
	
	int mnum=0; 
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){	
		for(int j=0; j<m; j++){		
			scanf("%d", &temp[i][j]);
			if(temp[i][j]>=1 && temp[i][j]<=5){
				mnum++;
			}//if
		}//for-j
	}//for-i
			
	int max=0;
	for(int i=0; i<n; i++){		
		for(int j=0; j<m; j++){
			if(temp[i][j]>=1 && temp[i][j]<=5){			
				for(int a=0; a<4; a++){
					memcpy(grp, temp, sizeof(grp));	
					fill(i, j, temp[i][j], a);
					int total=0;
					for(int q=0; q<n; q++){
						for(int w=0; w<m; w++){
							if(grp[q][w]==0) total++;
						}		
					}
					if(total>max) max=total;
				}//for-a
			}//if		
		}//for-j
	}//for-i
		
	printf("%d", max);
	return 0;
}//main 

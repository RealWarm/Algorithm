#include<iostream>
using namespace std;
int dx[]={0, 0,1,-1};
int dy[]={1,-1,0, 0};
int grp[6][6];
int n, m;

void fill(int x, int y, int num){
		
	if(num==1){		
		//위로채운다. 
		int ntx=x;
		int nty=y;
		while(1){			
			ntx+=dx[3];
			nty+=dy[3];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
	}else if(num==2){
		
		int ntx=x;
		int nty=y;		
		while(1){
			ntx+=dx[3];
			nty+=dy[3];
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
		
		
	}else if(num==3){
	
		int ntx=x;
		int nty=y;		
		while(1){
			ntx+=dx[3];
			nty+=dy[3];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		ntx=x;
		nty=y;
		while(1){
			ntx+=dx[0];
			nty+=dy[0];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
	}else if(num==4){	
	
		int ntx=x;
		int nty=y;	
		while(1){
			ntx+=dx[3];
			nty+=dy[3];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		ntx=x;
		nty=y;
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
		
		
	}else if(num==5){
		
		int ntx=x;
		int nty=y;		
		while(1){
			ntx+=dx[3];
			nty+=dy[3];
			if(ntx<0 || nty<0 || ntx>=n || nty>=m) break;
			if(grp[ntx][nty]==6) break;
			if(grp[ntx][nty]==0){
				grp[ntx][nty]=8;
			}
		}//while
		
		
		ntx=x;
		nty=y;
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
		
	}//if-else
	
}//fill


int main(){
	
	scanf("%d %d", &n, &m);	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &grp[i][j]);
		
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grp[i][j]!=0 && grp[i][j]!=6 && grp[i][j]!=8){
				fill(i, j, grp[i][j]);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ", grp[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}//main

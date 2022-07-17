#include<iostream>
using namespace std;
int grp[10][10];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n=8, m=8;

int main(){
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			scanf("%d", &grp[i][j]);
		}
	}
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(grp[i][j]==1){
				for(int k=0; k<4; k++){
					int ntx=i;
					int nty=j;
					while(1){
						ntx+=dx[k];
						nty+=dy[k];
						if(ntx<0 || ntx>=n || nty<0 || nty>=m) break;
						if(grp[ntx][nty]==3) break;
						if(grp[ntx][nty]==2){
							printf("1");
							return 0;
						}//if-2
					}//while
				}//for-k
			}//if
		}//for-j
	}//for-i
	
	printf("0");
	
	return 0;
}//main

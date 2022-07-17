#include<iostream>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[5][5];

int main(){
	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			scanf("%d", &grp[i][j]);
		}//for-j		
	}//for-i
	
		
	for(int i=0; i<5; i++){//세로 
		for(int j=0; j<5; j++){//가로 
			int flag=0;
			for(int k=0; k<4; k++){ 
				int ntx=i+dx[k];
				int nty=j+dy[k];
				if(ntx>=0 && nty>=0 && ntx<<5 && nty<5){
					if(grp[ntx][nty]<=grp[i][j]){
						flag=1;
					}
					if(flag==1){
						printf("%d ", grp[i][j]);
						break;
					}else if(k==3){					
						printf("* ");
						break;
					}//if-2
				}else if(k==3){
					printf("* ");					
				}//if-1				
			}//for-k
		}//for-j
		printf("\n");
	}//for-i	

	return 0;	
}

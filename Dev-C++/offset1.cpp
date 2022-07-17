#include<iostream> 
#include<cstring>
using namespace std;
int grp[7][7];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(){
		
	memset(grp, 10, sizeof(grp));
	for(int i=1; i<=5; i++){
		for(int j=1; j<=5; j++){
			scanf("%d", &grp[i][j]);
		}
	}
	
	for(int i=1; i<=5; i++){
		for(int j=1; j<=5; j++){
			for(int k=0; k<4; k++){
				int ntx=i+dx[k];
				int nty=j+dy[k];
				if(grp[i][j]>=grp[ntx][nty]){
					printf("%d ", grp[i][j]);
					break;
				}				
				if(k==3){
					printf("* ");
					break;
				}				
			}//for-k
		}//for-j
		printf("\n");
	}//for-i
		
	return 0;
}//main

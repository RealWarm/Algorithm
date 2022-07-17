#include<iostream>
#include<cmath>
using namespace std;
int grp[30][30];
int dis[30][30];
int n, tx, ty;

int main(){

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &grp[i][j]);		
			if(grp[i][j]==9){
				tx=i;
				ty=j;
				dis[i][j]=-1;
			}
		}//for-j
	}//for-i
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==tx && j==ty){
				printf("* ");
			}else if(grp[i][j]>0){
				int ddis=abs(tx-i)+ abs(ty-j);
				printf("%d ",ddis);
			}else{
				printf("0 ");
			}		
		}//for-j
		printf("\n");
	}//for-i
	
	
		
	return 0;
}//main

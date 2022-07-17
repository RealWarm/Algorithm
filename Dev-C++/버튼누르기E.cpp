#include<iostream>
using namespace std;
int grp[20][3];
int n, mmax;

void get(int sum, int x, int inx){
	if(x>=n){
		if(sum>mmax){
			mmax=sum;
		}//if-2
	}else{
		for(int i=0; i<3; i++){
			if(i==inx){
				continue;
			}else{
				sum+=grp[x][i];
				get(sum, x+1, i);
				sum-=grp[x][i];
			}
		}//for-i	
	}//if-1	
}//get

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &grp[i][j]);
		}
	}
	get(0, 0, -1);
	printf("%d", mmax);
	return 0;
}//main

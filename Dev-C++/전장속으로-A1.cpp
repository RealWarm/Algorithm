#include<iostream>
#include<cmath>
using namespace std;
int grp[30][30];
int n, mmin=987987987, minx, miny;

int main(){

	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &grp[i][j]);
			if(grp[i][j]<mmin && grp[i][j]>0){
				mmin=grp[i][j];
				minx=i;
				miny=j;
			}
		}//for-j
	}//for-i
	
	printf("%d %d", minx+1, miny+1);
		
	return 0;
}//main

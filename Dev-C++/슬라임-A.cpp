#include<iostream>
using namespace std;
int grp[60][60];
int n, m, mmin, mmax;

int main(){
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i
	scanf("%d %d", &mmin, &mmax);
		
	int total=0, cnt=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grp[i][j]>=mmin && grp[i][j]<=mmax){
				total+=grp[i][j];
				cnt++;
			}//if
		}//for-j
	}//for-i
	
	if(cnt==0){
		printf("-1\n");
	}else{
		printf("%d\n", total/cnt);	
	}
	
	return 0;
}//main

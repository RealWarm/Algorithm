#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	int grp[101][101]={0};
	int n; scanf("%d", &n);
	int x, y, r; scanf("%d %d %d", &x, &y, &r);
	x-=1;
	y-=1;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int dis= abs(x-i) + abs(y-j);
			if(dis<=r){
				grp[i][j]=dis;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i==x && j==y){
				printf("x ");
				continue;
			}
			printf("%d ", grp[i][j]);
		}
		printf("\n");
	}
	
	return 0;	
}//main

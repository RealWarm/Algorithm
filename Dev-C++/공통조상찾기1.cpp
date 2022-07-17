#include<iostream> 
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int grp[1010];
int wei[1010];
int n, x, y; 

int main(){
	scanf("%d %d %d", &n, &x, &y);
	for(int i=0; i<n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		grp[b]=a;
	}//for-i
	
	while(1){
		wei[x]=1;
		x=grp[x];
		if(x==0)break;	
	}//while
	
	while(1){
		if(wei[y]==1 || y==0){
			printf("%d\n", y);
			break;
		}
		y=grp[y];		
	}
	
	
	return 0;
}//main

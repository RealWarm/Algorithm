#include<iostream> 
using namespace std;
int grp[25]={0, 5, 10, 15, 20,
			 50, 30, 35, 40, 45, 
			 100, 55, 60, 65, 70, 
			 75, 80, 85, 90, 95, 
			 500, 1000
			 };
int n, cur;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n;i++){
		int m;
		scanf("%d", &m);
		cur+=m;
		if(cur>=21)cur=21;
		printf("%d ", grp[cur]);
		if(cur==21)break;
	}//for-i
	return 0;
}//main

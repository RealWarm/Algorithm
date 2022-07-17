#include<iostream> 
using namespace std;
int pa[1010], ba[1010];
int t, n;

int main(){
	int sum=0;
	scanf(" %d %d", &t, &n);
	for(int i=1; i<=n; i++){
		int tmp; scanf(" %d", &tmp);
		sum+=tmp;
		pa[i]=sum;
	}//for-i
	sum=0;
	int m; scanf(" %d", &m);
	for(int i=1; i<=m; i++){
		int tmp; scanf(" %d", &tmp);
		sum+=tmp;
		ba[i]=sum;
	}//for-i	
	////////////////////////////////////////////////
	
	
	return 0;
}//main



//	printf("===========================\n");
//	for(int i=0; i<=n; i++){
//		printf("%d ", ba[i]);
//	}//for-i
//	printf("\n");
//	printf("===========================\n");
//
//
//	printf("===========================\n");
//	for(int i=0; i<=n; i++){
//		printf("%d ", pa[i]);
//	}//for-i
//	printf("\n");
//	printf("===========================\n");

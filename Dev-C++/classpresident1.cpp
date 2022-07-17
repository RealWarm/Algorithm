#include<iostream>
using namespace std;
int grp[1010][5];

int main(){
	
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<5; j++){
			scanf("%d", &grp[i][j]);
		}
	}
	
	int sa=0; int max=0; 
	for(int i=0; i<n; i++){//기준사람 
		int smax=0;
		for(int j=0; j<5; j++){//학년 
			for(int k=0; k<n; k++){//사람 
				if(i==k) continue;
				if(grp[i][j]==grp[k][j]) smax++;
			}
		}
		if(smax>max){
			max=smax;
			sa=i;
		}//if
	}//for-i
	
	printf("%d",sa+1);
	
	return 0;
}//main

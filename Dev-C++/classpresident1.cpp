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
	for(int i=0; i<n; i++){//���ػ�� 
		int smax=0;
		for(int j=0; j<5; j++){//�г� 
			for(int k=0; k<n; k++){//��� 
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

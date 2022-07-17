#include<iostream>
#include<cmath>
using namespace std;
int desk[20010];
int n, mmax, minx;

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf(" %d", &desk[i]);
	}
	
	for(int i=0; i<n; i++){		
		if(desk[i]==0){
			//
			for(int a=i+1; a<n; a++){				
				if(desk[a]==1){					
					int tmp=abs(i-a);
					if(mmax<tmp){
						mmax=tmp;
						minx=i;
					}
//					printf("%d %d 비교중 mmax ::  %d\n", i, a, mmax);
					break;
				}//if				
			}//for-a
			
			for(int a=i-1; a>=0; a--){				
				if(desk[a]==1){					
					int tmp=abs(i-a);
					if(mmax<tmp){
						mmax=tmp;
						minx=i;
					}			
//					printf("%d %d 비교중 mmax ::  %d\n", i, a, mmax);		
					break;
				}//if				
			}//for-a
			
		}//if
	}//for-i
//	printf("%d \n", minx);
	
	
	int mmin=987987987;
	int rinx=0;
	for(int a=minx+1; a<n; a++){				
		if(desk[a]==1){					
			int tmp=abs(minx-a);
			if(mmin>tmp){
				mmin=tmp;
				rinx=a;
			}		
//			printf("%d 과 %d 비교중 거리는 %d\n", minx, a, tmp);
			break;
		}//if				
	}//for-a
	
	for(int a=minx-1; a>=0; a--){				
		if(desk[a]==1){					
			int tmp=abs(minx-a);
			if(mmin>tmp){
				mmin=tmp;
				rinx=a;
			}						
//			printf("%d 과 %d 비교중 거리는 %d\n", minx, a, tmp);
			break;
		}//if				
	}//for-a
	
	printf("%d\n", rinx);
	
}//main

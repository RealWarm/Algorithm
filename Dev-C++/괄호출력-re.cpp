#include<iostream>
using namespace std;
int arr1[20];
int n, total; //°ıÈ£ÀÇ ÃÑ±æÀÌ, °ıÈ£³»ÀÇ ÃÑ°ª 

void get(int x){
		
	if(x==n){
				
			for(int i=0; i<n; i++){
				if(arr1[i]==1){
					printf("(");
				}else if(arr1[i]==-1){
					printf(")");
				}//if-3
			}//for-i
			printf("\n");
		
		
	}else{	
	
		if(total==1){
			arr1[x]=1; // "("
			total++;
			get(x+1);
			total--;
			
			arr1[x]=-1;
			total--;
			get(x+1);
			total++;
		}else if(total==0){			
			arr1[x]=1;
			get(x+1);
			total+=1;
		}		
						
	}//if-1
	
}//get

int main(){
	scanf("%d", &n);	
	get(0);
	return 0;
}//main

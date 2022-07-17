#include<iostream>
using namespace std;
int result[15];
char arr[15];
bool checkMax[10], checkMin[10];
bool printMax = false, printMin=false;
int n;

void getMax(int x){
	
	if(printMax == true) return;
	
	if(x>n){
		for(int i=0; i<n+1; i++) printf("%d", result[i]);
		printf("\n");  		
		printMax = true;
	}else{
		for(int i=9; i>=0; i--){
			result[x]=i;
			if(checkMax[i]==false){
				bool flag=false;
				
				if(x==0){
					flag=true;
				}else{
					if(arr[x-1]== '>'){
						if(result[x-1]>result[x])
							flag = true;
					}else{
						if(result[x-1]<result[x])
						flag =true;
					}//if-2
				}//if-1
				
				if(flag==true){
					checkMax[i]=true;
					getMax(x+1);
					checkMax[i]=false;
				}//if-1
			}//if
		}//for-i
	}//if-else
	
}//getMax

void getMin(int x){
	
	if(printMin == true) return;
	
	if(x>n){
		for(int i=0; i<n+1; i++) printf("%d", result[i]);
		printf("\n");
		
		printMin = true;
	}else{
		for(int i=0; i<=9; i++){
			result[x]=i;
			if(checkMin[i]==false){
				bool flag=false;
				
				if(x==0)flag=true;
				else{
					if(arr[x-1]== '>'){
						if(result[x-1]>result[x])
							flag = true;
					}else{
						if(result[x-1]<result[x])
						flag =true;
					}//if-else					
				}				
				
				if(flag==true){
					checkMin[i]=true;
					getMin(x+1);
					checkMin[i]=false;
				}//if
			}//if
		}//for-i
	}//if-else	
}//getMax

int main(){	
	scanf("%d", &n);	
	for(int i=0; i<n; i++){
		scanf(" %c", &arr[i]);
	}	
	getMax(0);
	getMin(0);	
	return 0;
}//main


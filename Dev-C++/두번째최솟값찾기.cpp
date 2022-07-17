#include<iostream>
using namespace std;
const int MAX = 9;
int arr[MAX];

int main(){
	
	int fmax=10000001, smax=10000001;
	int finx=0, sinx=0;
	
	for(int i=0; i<MAX; i++){
		scanf("%d", &arr[i]);
	}//for-i
	
	for(int i=0; i<MAX; i++){
		if(arr[i]<fmax){
			smax=fmax;
			fmax=arr[i];
			sinx=finx;
			finx=i;
		}else if(arr[i]<smax){
			smax=arr[i];
			sinx=i;			
		}//if-else
	}//for-i
	
	printf("%d\n%d", smax, sinx+1);
	
	return 0;
}//main

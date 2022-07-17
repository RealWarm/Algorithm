#include<iostream>
using namespace std;
int arr[100000];

int main(){
		
	for(int i=0; i<9; i++)
		scanf("%d", &arr[i]);
	
	int maxVal=0, maxInx=0;
	for(int i=0; i<9; i++){
		if(arr[i]>maxVal){
			maxVal=arr[i];
			maxInx=i;
		}//if
	}//for-i	
	printf("%d\n%d", maxVal, maxInx+1);
	
	return 0;
}//main

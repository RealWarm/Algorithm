#include<iostream>
using namespace std;
int result[50];
int n, k;

void printBinary(int index, int k) {

	if(k==0){
		for(int i=0; i<n; i++){
			printf("%d", result[i]);
		}
		printf("\n");
		return;
	}
	
	if (index == n) return;
		
	result[index] = 1;
	printBinary(index+1, k-1);
		
	result[index] = 0;
	printBinary(index+1, k);
	
}//printBinary

int main(){
	scanf("%d %d", &n, &k);
	printBinary(0, k);
	return 0;
}//main

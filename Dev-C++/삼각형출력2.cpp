#include<iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int space = n-1;
	
	for(int i=1; i<=n; i++){
		for(int k=0; k<space; k++){		
			printf(" ");
		}//while
		for(int j=0; j<i; j++){
			printf("*");
		}
		space--;
		printf("\n");
	}//for-i 
	
	return 0;
}//main

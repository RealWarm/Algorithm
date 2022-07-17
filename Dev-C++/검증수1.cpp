#include<iostream>
using namespace std;
int arr[10];
int main(){
	
	for(int i=0; i<6; i++){
		cin >> arr[i];
	}
	int sum=0;
	for(int i=0; i<6; i++){		
		sum += arr[i]*arr[i];
	}//for-i
	
	printf("%d", sum%10);
	
	return 0;
}

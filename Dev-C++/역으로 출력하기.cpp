#include<iostream> 
using namespace std;
int arr[1010];

int main(){
	int num; cin >> num;	
	for(int i=num-1; i>=0; i--){	
		cin >> arr[i];
	}//while		
			
	for(int i=0; i<num; i++){
		printf("%d ", arr[i]);
	}//for-i		
		
	return 0;
}//main

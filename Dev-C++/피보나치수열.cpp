#include<iostream>
using namespace std;
int arr[50];

int main(){
	int n; scanf("%d", &n);
	arr[0]=1;
	arr[1]=1;
	for(int i=2; i<=n-1; i++){
		arr[i]=arr[i-1]+arr[i-2];
	}//for-i
	
	printf("%d\n", arr[n-1]);
	
	return 0;
}//main

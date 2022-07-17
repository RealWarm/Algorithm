#include<iostream>
using namespace std;
int arr[110][110];

int main(){
	int n; cin >> n;
	int cnt=1;
	for(int i=1; i<=n; i++){
		for(int j=0; j<i; j++){
			arr[j][i-j]=cnt++;		
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<=n-i; j++){
			if(arr[i][j]!=0){
				printf("%d ", arr[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}//main

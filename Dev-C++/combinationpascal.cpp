#include<iostream>
using namespace std;

int main(){
	
	int arr[33][33]={0};
	int n, r; cin >> n >> r;
	n++; r++;
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			if(i==0 || j==0){
				arr[i][j]=1;
//				cout << arr[i][j] << " ";
			}else{
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
//				cout << arr[i][j] << " ";
			}//if-else
		}//for-j
//		cout << endl;
	}//for-i
	cout << arr[n-1][r-1];
	return 0;
}

/*
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int K;
	cin >> N >> K;
	N++;
	int *arr = new int[N];
	int *tmp = new int[N];
	tmp[1] = 1;
	arr[1] = 1;
	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i) arr[j] = 1;
			else arr[j] = tmp[j - 1] + tmp[j];
		}
		for (int k = 1; k <= i; k++)  tmp[k] = arr[k];
	}
	cout << arr[K];
}//main
*/

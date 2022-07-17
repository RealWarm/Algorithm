#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	
	int n, k; cin >> n >> k;
	vector<int> arr;
	
	for(int i=0; i<k; i++){
		arr.push_back(1);
	}//for-i
		
	for(int i=0; i<n-k;i++){
		arr.push_back(0);
	}	
	
	do{
		for(int i=0; i<n; i++){
			cout<< arr[i];
		}
		cout << '\n';
	}while(prev_permutation(arr.begin(), arr.end()));
	
	return 0;
}//main


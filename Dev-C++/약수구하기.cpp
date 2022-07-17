#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	int n, k; cin >> n >> k;	
	vector<int> arr;
	
	for(int i=1; i<=n; i++){
		if(n%i==0){
			arr.push_back(i);
		}		
	}//for-i
	
	if(arr.size()>=k){
		cout << arr[k-1];
	}else{
		cout << 0;
	}
	
	return 0;
}

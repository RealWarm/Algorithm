#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int num; cin>>num;
	vector<string> strArr(num);
	
	for(int i=0; i<num; i++){
		cin >> strArr[i];
	}
	sort(strArr.begin(), strArr.end());
	
	for(int i=0; i< num; i++){
		cout << strArr[i] << "\n";
	}
	
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
vector<string> grp(5);

int main(){
	int len=0;
	for(int i=0; i<5; i++){
		cin >> grp[i];
		len=max(len, (int)grp[i].size());
	}//for-i
//	printf("len :: %d\n", len);
	///////////////////////////////////
	string ans;

	for(int j=0; j<len; j++){
		for(int i=0; i<5; i++){
			if(j>=grp[i].size()) continue;
			ans+=grp[i][j];
		}		
	}//for-i
	
	cout<< ans;
		
	return 0;	
}//main

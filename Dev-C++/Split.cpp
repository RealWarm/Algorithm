#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

vector<string> split(string str, char delimiter){
	
	vector<string> internal;
	stringstream ss(str);
	string temp;
	
	while(getline(ss, temp, delimiter)){
		internal.push_back(temp);
	}//while
	
	return internal;
	
}//Split

int main(){
	
	vector<string> ans;
	string str; getline(cin, str);
	ans=split(str, ' ');
	printf("%d :: ", ans.size());
	for(int i=0; i<ans.size(); i++){
		printf("%s ", ans[i].c_str());
	}//for-i
	
	return 0;
}//main

#include <bits/stdc++.h>
using namespace std;

int main(){
		
	string cover = "abcdefghijklm";
	string str = "";	
	set<string> s;
	int n, r; cin >> n >> r;
	
	for(int i=0; i<n; i++){
		str+=cover[i];
	}//for-i
	
	do{
		string temp="";
		for(int i=0; i<r; i++){
			temp += str[i];
		}
		s.insert(temp);		
	}while(next_permutation(str.begin(), str.end()));
	
	set<string>::iterator iter;
	for(iter=s.begin(); iter!=s.end(); iter++){
		cout << *iter << endl;
	}
		
	return 0;
}//main

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	
	string s; cin >> s;
	int n;	cin >> n;
	vector<string> v1(n);
	int result=0;
	
	
	for(int i=0; i<n; i++){
		cin >> v1[i];
		bool ring = false;
		for(int j=0; j<v1[i].size(); j++){
			if(v1[i][j]==s[0]){
				bool flag=true;
				for(int k=0; k<s.size(); k++){
					if(v1[i][(j+k)%v1[i].size()]!=s[k]){
						flag=false;
						break;
					}//if
				}//for-k
				if(flag){
					ring=true;
					break;
				}//if
			}//if
			if(ring){
				result++;
			}//if
		}//for-j
	}//for-i
	cout << result << "\n";
	
	return 0;
}//main






#include <bits/stdc++.h>
using namespace std;
vector<int> v1;
int wei[100000];

int main(){
	string str, tstr; getline(cin, str);
	for(int i=0; i<str.size(); i++){
		if(str[i]>='1' && str[i]<='9'){
			tstr+=str[i];
		}else{
			int inx = stoi(tstr);
			v1.push_back(inx);
			tstr.clear();
			if(wei[inx]==0){
				wei[inx]=1;
			}//if
		}//if
	}//for-i
	int inx = stoi(tstr);
	v1.push_back(inx);
	
	for(int i=0; i<v1.size(); i++){
		printf("%d ", wei[v1[i]]);
	}
	
	return 0;
}//main


//1 1 3 4 3 6 3


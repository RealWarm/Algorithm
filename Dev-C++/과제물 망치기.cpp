#include<string>
#include<iostream>
using namespace std;

int main(){
	
	string str1, str2; getline(cin, str1);
	
	for(int i=0; i<str1.size(); i++){
		if(str1[i]!=' '){
			str2+=str1[i];
		}
	}
	
	cout << str2;
	return 0;
}

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main(){
	string str="-1 -2 -3 -4";
	int tmp=stoi(str);
	for(int i=0; i<str.size(); i++){
		cout << str[i]<< ".." << endl;
	}

//	cout << tmp << endl;
	
	return 0;
}

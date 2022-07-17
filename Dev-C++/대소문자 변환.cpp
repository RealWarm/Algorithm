#include<cstdio> 
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int main(){
	
	string str; getline(cin, str);
	
	for(int i=0; i<str.size(); i++){
		if(str[i]>=65 && str[i]<=90){
			str[i]+=32;
		}else if(str[i]>=97 && str[i]<=122){
			str[i]-=32;
		}else{
			continue;
		}		
	}//for-i
	
	cout << str;
	
	return 0;
}

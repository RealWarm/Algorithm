#include<iostream>
#include<string>
using namespace std;

int main(){
	string str; getline(cin, str);
	int cnt=1;
	int flag=0;
	for(int i=0; i<str.length(); i++){
		if(str[i]!=' ') flag=1;
		if(str)
		if(flag==1 && str[i]==' ') cnt++;
		
	}//for-i
	printf("%d", cnt);
	return 0;
}//main

#include<iostream>  // for IO
#include<cstring>   // for string
#include<algorithm> // for reverse
using namespace std;

int main(){	
	string s;
	int input; cin>>input;

	while(input>1){
		if(input%2 == 1){
			s+='1';
		}else{
			s+='0'; 
		}//if-else
		input/=2;
	}//while
	s+='1';
	reverse(s.begin(),s.end()); 
	cout<<s<<endl;	
}//main

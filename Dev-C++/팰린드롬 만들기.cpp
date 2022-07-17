#include<iostream> 
#include<algorithm>
#include<string> 
#include<cstring>
using namespace std;

int main(){
	
	int flag=0;
	string str1; cin >> str1;
	
	for(int i=0; i<str1.size(); i++){		
		string str2 = str1;		
		reverse(str2.begin(), str2.end());
		if(str1==str2){			
			flag=1;
			printf("%s", str1.c_str());
			break;
		}
		char tmp = str1[0];
		str1.erase(0, 1);
		str1+=tmp;
//		cout<<str1<<endl;		
	}//for-i
	
	if(flag==0){
		printf("I'm Sorry Hansoo\n");
	}//if
	
	return 0;
}//main

// 입력된 문자열의 순서를 적절히 바꿔서 팰린드롬으로 만들어라 

// 설계 
// 팰린드롬이니? >> 순서를 바꾼다 >> 문자의 길이만큼 반복 

























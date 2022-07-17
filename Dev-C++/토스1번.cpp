#include<iostream>
using namespace std;

int main(){
	int flag=0;
	string str; cin >> str;
	for(int i=0; i<str.size()-1; i++){
		if(str[i]=='1' && str[i+1]!='2'){
			flag=1;
			break;
		}//if
	}//for-i
	
	if(flag==1){
		printf("false\n");
	}else{
		printf("true\n");
	}
	
	return 0;
}//main

//1과 2로 구성된 문자열의 유효성을 판별해주십시오.

//규칙
//
//문자열은 1 과 2 로만 구성된다.
//
//1의 뒤는 항상 2 가 존재해야만 한다.
//
//2의 뒤는 1 혹은 2 가 존재할 수 있다.
//
// 위의 규칙을 모두 준수하는 문자열이면 true 
// 그렇지 않으면 false를 출력하는 코드를 구현해주십시오.

//11 f
//
//12 t
//
//121 f >> t로나옴 
//122 t


#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){
	set<string> seet;
	string str; getline(cin, str);
	string ts;
	int day=0;
	for(int i=0; i<str.size(); i++){		
		if(str[i]!=32){
			ts+=str[i];
		}else if(str[i]==32){
			seet.insert(ts);
			ts.clear();
			day++;
		}//if
//		if(day%5==0){
//			seet.erase(seet.begin());
//		}		
		printf("\n");
	}//for-i
	set<string>::iterator iter;
	for(iter=seet.begin(); iter!=seet.end(); iter++){
		cout << *iter << " ";
	}
	
	return 0;
}//main


// 사용자의 편의를 위해서 최근 사용한 결제수단 순으로 화면에 표시하려고 합니다. 
// 이를 위해 최근 사용한 순서대로 결제수단을 나열해주십시오.
//
//규칙
//
//
// 1) 내가 기억할 수 있는 결제수단은 최근 5개의 결제수단이다.
//
// 2) 주어진 input은 내가 사용한 순서대로 나열한 것이다. (나열된 값 중 가장 마지막 값이 사용자가 가장 최근에 사용한 결제수단이다)
//
// 3) 주어진 input을 기준으로 매 결제수단 사용시 최근 5개 결제수단을 output 하시오.
//
// 입력 :: 우리 우리 우리 하나 우리 국민 삼성 농협 농협 농협 국민 저축

// 출력
 
//우리
//우리
//우리
//하나 우리
//우리 하나
//국민 우리 하나
//삼성 국민 우리 하나
//농협 삼성 국민 우리 하나
//농협 삼성 국민 우리 하나
//농협 삼성 국민 우리 하나
//국민 농협 삼성 우리 하나
//저축 국민 농협 삼성 우리

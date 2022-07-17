#include <bits/stdc++.h>
using namespace std;
vector<int> v1, v2;

int main(){
	string str1,str2; 
	string tstr;
	getline(cin, str1);
	getline(cin, str2);
	for(int i=0; i<str1.size(); i++){
		if(str1[i]>='0' && str1[i]<='9'){
			tstr+=str1[i];
		}else{
			if(tstr.size()==0)continue;
			int inx = stoi(tstr);
			v1.push_back(inx);
			tstr.clear();
		}//if
	}//for-i
	if(tstr.size()!=0){
		int inx = stoi(tstr);
		v1.push_back(inx);	
		tstr.clear();
	}
	//////////////////////////////////////////
	for(int i=0; i<str2.size(); i++){
		if(str2[i]>='0' && str2[i]<='9'){
			tstr+=str2[i];
		}else{
			if(tstr.size()==0)continue;
			int inx = stoi(tstr);
			v1.push_back(inx);
			tstr.clear();
		}//if
	}//for-i
	if(tstr.size()!=0){
		int inx = stoi(tstr);
		v2.push_back(inx);	
		tstr.clear();
	}
	printf("------------------------\n")
	for(int i=0; i<(int)v1.size(); i++){
		printf("%3d ", v1[i]);
	}
	for(int i=0; i<(int)v2.size(); i++){
		printf("%3d ", v2[i]);
	}
	
	// for(int i=0; i<(int)v1.size(); i++){
	// 	printf("%d ", abs(v1[i]-v2[i]));
	// }
	
	return 0; 
}//main



//김토스와 이토스 두 사람이 있습니다.
//
//
//
//규칙
//
//
//김토스는 이토스에게 매일 특정 금액을 줘야한다
//
//이토스는 김토스에게 매일 특정 금액을 줘야한다
//
//두 명이 서로 주는게 귀찮아서, 항상 김토스가 이토스에게 받을 금액을 감안해서 이토스에게 돈을 준다
//
//
//
//김토스가 당일 이토스에게 줘야 할 금액을 출력하는 코드를 작성해주십시오.


//예시 1
//입력
//100 300 10 0 40 0 0 70 65
//40 300 20 10 10 20 100 100
//출력
//60 0 0 0 10 0 0 0 5














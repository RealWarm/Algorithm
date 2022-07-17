#include<iostream>
#include<cstdio>
using namespace std;

int getDigitSum(int x) {
	//x의 각 자릿수의 합을 반환하는 함수
	if(0<=x && x<=9) {//x가 한자릿수 일 경우 
		return x;
	}else{
		return getDigitSum(x/10) + (x%10);
	}
}//getDigitSum

int main(){
	
	int x; cin >> x;
	
	printf("%d\n", getDigitSum(x));
	
	return 0;
}

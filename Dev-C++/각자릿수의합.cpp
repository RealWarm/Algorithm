#include<iostream>
#include<cstdio>
using namespace std;

int getDigitSum(int x) {
	//x�� �� �ڸ����� ���� ��ȯ�ϴ� �Լ�
	if(0<=x && x<=9) {//x�� ���ڸ��� �� ��� 
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

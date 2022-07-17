#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool isPalindrome(char myString[], int start, int end){
	//myString�� start ~ end�� �Ӹ�����̸� true,
	//�ƴϸ� false�� ��ȯ �ϴ� �Լ�	 
	if(start == end) return true;
	else if(start+1 ==end){
		if(myString[start]==myString[end])
			return true;
		else
			return false;
	}else {
		if(myString[start] == myString[end]){
			return isPalindrome(myString, start+1, end-1);
		}else{
			return false;
		}//if-else
	}//else
}//isPalindrome

int main(){
	
	char myString[100];
	
	cin >> myString;
	
	int len = strlen(myString);
	if(isPalindrome(myString, 0, len-1))
		printf("Yes\n");
	else
		printf("No\n");
	
	
	return 0;
}//main

#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char arrA[1010], arrB[1010];

bool ccheck() {
	//����B�� ����A�� �����ִ�? 
	if (strlen(arrB) > strlen(arrA)) return false;
	
	for (int i=0; i<strlen(arrA)-strlen(arrB)+1; i++){
		bool is = arrA[i] == arrB[0];
		for (int j=0; j<strlen(arrB); j++){
		    is &=  (arrA[j+i] == arrB[j]);
		}//for-j 
		if (is) return true;
	}//for-i
	return false;
}//ccheck

int main(){
	
	int flag=0;
	scanf(" %s %s", arrA, arrB);
	// ���ڿ�B�� ���ڿ�A�� ���ԵǾ� �ִ�? 
	if(ccheck()==true){
		printf("YES\n");		
	}else{
		printf("NO\n");
	}//if
	
	return 0;
}//main	

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

//1�� 2�� ������ ���ڿ��� ��ȿ���� �Ǻ����ֽʽÿ�.

//��Ģ
//
//���ڿ��� 1 �� 2 �θ� �����ȴ�.
//
//1�� �ڴ� �׻� 2 �� �����ؾ߸� �Ѵ�.
//
//2�� �ڴ� 1 Ȥ�� 2 �� ������ �� �ִ�.
//
// ���� ��Ģ�� ��� �ؼ��ϴ� ���ڿ��̸� true 
// �׷��� ������ false�� ����ϴ� �ڵ带 �������ֽʽÿ�.

//11 f
//
//12 t
//
//121 f >> t�γ��� 
//122 t


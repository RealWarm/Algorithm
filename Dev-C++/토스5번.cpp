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



//���佺�� ���佺 �� ����� �ֽ��ϴ�.
//
//
//
//��Ģ
//
//
//���佺�� ���佺���� ���� Ư�� �ݾ��� ����Ѵ�
//
//���佺�� ���佺���� ���� Ư�� �ݾ��� ����Ѵ�
//
//�� ���� ���� �ִ°� �����Ƽ�, �׻� ���佺�� ���佺���� ���� �ݾ��� �����ؼ� ���佺���� ���� �ش�
//
//
//
//���佺�� ���� ���佺���� ��� �� �ݾ��� ����ϴ� �ڵ带 �ۼ����ֽʽÿ�.


//���� 1
//�Է�
//100 300 10 0 40 0 0 70 65
//40 300 20 10 10 20 100 100
//���
//60 0 0 0 10 0 0 0 5














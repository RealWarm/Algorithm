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


// ������� ���Ǹ� ���ؼ� �ֱ� ����� �������� ������ ȭ�鿡 ǥ���Ϸ��� �մϴ�. 
// �̸� ���� �ֱ� ����� ������� ���������� �������ֽʽÿ�.
//
//��Ģ
//
//
// 1) ���� ����� �� �ִ� ���������� �ֱ� 5���� ���������̴�.
//
// 2) �־��� input�� ���� ����� ������� ������ ���̴�. (������ �� �� ���� ������ ���� ����ڰ� ���� �ֱٿ� ����� ���������̴�)
//
// 3) �־��� input�� �������� �� �������� ���� �ֱ� 5�� ���������� output �Ͻÿ�.
//
// �Է� :: �츮 �츮 �츮 �ϳ� �츮 ���� �Ｚ ���� ���� ���� ���� ����

// ���
 
//�츮
//�츮
//�츮
//�ϳ� �츮
//�츮 �ϳ�
//���� �츮 �ϳ�
//�Ｚ ���� �츮 �ϳ�
//���� �Ｚ ���� �츮 �ϳ�
//���� �Ｚ ���� �츮 �ϳ�
//���� �Ｚ ���� �츮 �ϳ�
//���� ���� �Ｚ �츮 �ϳ�
//���� ���� ���� �Ｚ �츮

#include<iostream> 
using namespace std;
int n, m;

void is(int x){
	//�Ҽ��� �Ǻ��ϴ� �Լ�
	//�Ҽ��� 1�� �ڽ��� ������ ���� �������� �ʴ� ���� ���Ѵ�. 
	if(x==1) return;
	if(x==2){
		printf("2 ");
		return;
	}//if
	for(int i=2; i<x; i++){
		if(x%i==0){
			return;
		}//if
	}//for-i
	printf("%d ", x);
}//is

int main(){	
	int n, m; cin >> n >> m;	
	for(int i=n; i<=m; i++){
		is(i);
	}//for-i	
	return 0;
}//main


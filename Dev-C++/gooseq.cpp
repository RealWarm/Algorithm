#include<iostream>
#include<cstdio>
using namespace std;
int result[100];
int n, ended;

int check(int x, int length){
	//result[x]�� �����ʳ��̰�, ���� length�� �ߺ��� �ִ��� �Ǻ�
	//�ߺ��� ���ٸ� true, �ƴϸ� false	
	for(int i=0; i<length; i++) {
		if(result[x-i] != result[x-i-length]){
			return 1;
		}//if
	}//for-i
	return 0;
}//isPossible

void getResult(int x){
	//result[x]�� ������ ��, result[x+1]���� �� ������ ������ �Լ�.
	//result[x] ~ result[n-1]���� �����ϴ� �Լ�.
	
	//(1) x��° ���ڸ� �����Ѵ�.
	//(2) x+1��° ���ڸ� �����Ϸ� ����.  	
	if(ended==1) return;
	
	if(x>=n){
		for(int i=0; i<n; i++){
			cout<<result[i];
		}
		cout<<endl;
		ended=1;
		return;
	}//if
	
	for(int i=1; i<=3; i++){
		result[x]=i;
		int flag=0;
		for(int j=1; j<=(x+1)/2; j++){
			if(!check(x,j)){
				flag=1;
				break;
			}		
		}//for-j				
		
		if(flag == 0){
			getResult(x+1);
		}//if
	}//for-i	
}//getResult

int main(){	
	cin>>n;
	getResult(0);	
	return 0;
}//main

#include<iostream>
#include<cstring>
using namespace std;
double memo[100];

double fibo_recursion(int n){	
	if(n==0){
		return 0;
	}else if(n==1){
		return 1;
	}else{		
		return fibo_recursion(n-1) + fibo_recursion(n-2);
	}//if-else
}//fibo_recursion

double fibo_dynamic(int n){
	// memo�� memoization�� ���� �������� ������ �迭, ���� �ʱ�ȭ �ʿ�
	// ��ȯ���� double�� �� ������ 50 �̻��� ���������� int�� ���� �ʰ� 
	if(memo[n] != -1){
		return memo[n];
	}
	memo[n] = fibo_dynamic(n-1) + fibo_dynamic(n-2);
	return memo[n];
}//fibo_dynamic

double fibo_while(int n){
	// memo�� memoization�� ���� �������� ������ �迭, ���� �ʱ�ȭ �ʿ�
	// ��ȯ���� double�� �� ������ 50 �̻��� ���������� int�� ���� �ʰ� 
	for(int i=2; i<n; i++){
		memo[i]=memo[i-1]+memo[i-2];
	}
	return memo[n-1]+memo[n-2];
}//fibo_while

int main(){
	
	int x; cin >> x;	
	memset(memo, -1, sizeof(double));
	memo[0]=0;
	memo[1]=1;
	memo[2]=2;
	cout << fibo_dynamic(x-1);
//	for(int i=0; i<50; i++){
//		cout << memo[i] << " ";
//	}
	return 0;
}

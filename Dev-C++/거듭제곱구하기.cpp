#include<iostream> 
#include<cstdio>
using namespace std;
typedef long long ll;

int getResult(int n, ll m) {
	// n^m�� 10007 �� ���� �������� ��ȯ�ϴ� �Լ� 
	
	//�������� 
	if(m==0){
		return 1; 
	}else if(m%2==0){
		// n^m = (n^(m/2))^2
		int temp = getResult(n, m/2);
		return (temp*temp)%10007;
	}else{
		//n^m=(n^(m-1))*n
		int temp = getResult(n, m-1);
		return (temp*n)%10007;
	}//if-else
	
}//getResult

int main(){
	
	int n; 
	ll m; 
	cin >> n;
	cin >> m;
	
	cout << getResult(n, m);
		
	return 0;
}//main 

#include<iostream>
using namespace std;
typedef long long ll;
ll t[100010];

int main(){	
	int n, m=3; 
	scanf("%d", &n);
	
	t[1]=1;
	int sum=0;
	for(int i=2; i<=m; i++){
		sum+=t[i-1];
		t[i]=sum+1;
	}//for-i
	
	for(int i=m+1; i<=n; i++){
		for(int a=i-m; a<i; a++){
			t[i]+=(t[a]%1000007);
		}//for
	}//for-i
	printf("%d", t[n]%1000007);
	
	return 0;
}//main


// 숫자 1, 2, 3을 이용하여 숫자 N을 만드는 경우의 수를 출력하는 프로그램을 작성하시오
// 예를 들어, N이 4일 경우에는 다음의 7가지 경우가 존재한다. 
// 단, 경우의 수가 매우 많을 수 있으므로, 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.



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


// ���� 1, 2, 3�� �̿��Ͽ� ���� N�� ����� ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�
// ���� ���, N�� 4�� ��쿡�� ������ 7���� ��찡 �����Ѵ�. 
// ��, ����� ���� �ſ� ���� �� �����Ƿ�, ����� ���� 1,000,007 �� ���� �������� ����Ѵ�.



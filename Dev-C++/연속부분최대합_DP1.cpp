#include<iostream> 
#include<cmath>
using namespace std;
// T(i)�� i�� ������ �������� �ִ밪
// tb[i]= max(T[i]+tb[i-1], T[i]) 
int tb1[1000000];
int tb2[1000000];
int n; // ���ڵ��� ���� 

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &tb1[i]);
	}//for-i
	
	int mmax=0;
	tb2[0]=tb1[0];
	for(int i=1; i<n; i++){
		tb2[i]=max(tb1[i]+tb2[i-1], tb1[i]);
		if(tb2[i]>mmax){
			mmax=tb2[i];
		}
	}//for-i
	printf("%d", mmax);
	
	return 0;
}//main

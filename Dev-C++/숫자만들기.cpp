#include<iostream>
using namespace std;
int f[100010];
int n, m=3;

int main(){
		
	scanf("%d", &n);
	/// 기저조건 
	f[1]=1;
	int sum=0;
	for(int i=2; i<=m; i++){
		sum+=f[i-1];
		f[i]=sum+1;
	}//for-i
	/////////////////////////////////////////////////////////////
	for(int i=m+1; i<=n; i++){
		for(int j=i-m; j<=i-1; j++){
			f[i]+=f[j];
		}
	}//for-i
	
	printf("%d\n", f[n]%1000007);
	
	return 0;
}//main  

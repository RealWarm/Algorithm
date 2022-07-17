#include<iostream> 
using namespace std;
typedef long long li;

int getResult(int n, li m){	
	if(m==0){
		return 1;
	}else{
		if(m%2==0){
			int temp = getResult(n,m/2);
			return (temp*temp)%10007;
		}else{
			int temp = getResult(n, m-1);
			return (temp*n)%10007;
		}
	}	
}//getResult

int main(){	
	int n;
	li m; 
	cin >> n >> m;		
	printf("%d", getResult(n,m));	
	return 0;
}//main

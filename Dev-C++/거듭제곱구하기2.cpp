#include<iostream> 
using namespace std;
typedef long long ll; 

int get(int n, ll m){	
	if(m==0){
		return 1;
	}else{
		if(m%2==0){
			int temp=get(n, m/2);
			return (temp*temp)%10007;
		}else{
			int temp=get(n, m-1);
			return (temp*n)%10007;
		}//if-2		
	}//if-1	
}//get

int main(){	
	int n;
	ll m;
	scanf("%d %lld", &n, &m);	
	printf("%d", get(n,m));
	return 0;
}//main

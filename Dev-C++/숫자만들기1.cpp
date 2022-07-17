#include<iostream>
using namespace std;
typedef long long ll;
ll n;
ll d[1000010];

int main(){
	scanf("%lld", &n);
	d[1]=1;
	ll sum=0;
	for(int i=2; i<=3; i++){
		sum+=d[i-1];
		d[i]=sum+1;
	}//for-i
	
	for(ll i=4; i<=n; i++){
		for(ll j=i-3; j<=i-1; j++){
			d[i]+=d[j]%1000007;
		}//for-j
	}//for-i
	
	printf("%lld", d[n]%1000007);
	
	return 0;
}//main

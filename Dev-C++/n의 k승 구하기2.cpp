#include<iostream>
using namespace std;
typedef long long ll;
//ll arr[] ;
ll n, m;

ll get(ll a, ll b){
	
	if(b==0){
		return 1;
	}else if(b%2==0){
		return (get(a, b/2)*get(a, b/2))%1000000007;
	}else{
		return (get(a, b-1)*a)%1000000007;
	}//if
	
}//get

int main(){
	scanf("%lld %lld", &n, &m);
	printf("%lld\n", get(n, m));		
	return 0;
}//main

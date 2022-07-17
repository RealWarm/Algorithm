#include<iostream> 
using namespace std;
typedef long long ll;
int n;
ll k; 

ll getOrder(ll x) {	
	ll result = 0;
	for(int i=1; i<=n; i++){
		if((ll)i*n < x){
			result+=n;
		}else{
			if(x%i==0)  result += (x/i)-1; 
			else result += x/i; 	
		}			
	}	
	return result+1;
}//getOrder

int main(){		
	scanf("%d %lld", &n, &k);
	ll start =1, end = n*n+1; 							  
	while(start+1 < end) {			
		ll mid = (start+end)/2;
		ll myOrder = getOrder(mid);
		
		if(myOrder <= k) start = mid;
		else end = mid;		
	}//while
	printf("%lld\n", start);	
	return 0;
}//main

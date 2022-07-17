#include<iostream> 
using namespace std;
typedef long long ll;
int n;
ll k; 
/*
	1 2 3 4
	2 4 6 8
	3 6 9 12
	4 8 12 16   12가 몇번째 숫자니? >> 12보다 작은 갯수를 세면 된다
									>> 13개>> 14번째 

	1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16
	k가 8일때 start는 1~4까지만 가르킬 것이다. (정답이하의 숫자를 가르킨다.) 	
*/

ll getOrder(ll x) {
	//x가 몇번째인지 반환하는 함수. 
	ll result = 0;
	for(int i=1; i<=n; i++){
		if((ll)i*n < x){
			result+=n;// x가 전부보다 클때 	
		}else{
			if(x%i==0)  result += (x/i)-1; // 0으로 나누어떨어지는 경우 -1 
			else result += x/i; 	
		}//if		
	}//for-i	
	return result+1;
}//getOrder

//k번째 숫자가 무엇이냐 >> 특정숫자 p가 몇번째 인가? 
//1부터 n*n 까지중에서
//숫자 p가 몇번째 인가? 
int main(){
		
	cin >> n >> k; // N: 단  k: 번째로 작은수 
	ll start =1, end = n*n+1; // mid는 절대 end가 될수없다 
							  // >> n*n을 탐색하기위해 end+1을한다. 
	while(start+1 < end) {//start와 end가 붙어있다.
	
		//start : 항상 정답이 되는 숫자보다 작거나 같은 숫자 
		//end 	: 항상 정답이 되는 숫자보다 큰 숫자. 
		ll mid = (start+end)/2;
		ll myOrder = getOrder(mid);
		
		// if(myOrder == k) return mid // 없는 숫자가 걸릴수 있으니깐 
		
		if(myOrder <= k) start = mid;
		else end = mid;		
	}//while
	printf("%lld\n", start);
	
	return 0;
}//main

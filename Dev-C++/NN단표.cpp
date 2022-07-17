#include<iostream> 
using namespace std;
typedef long long ll;
int n;
ll k; 
/*
	1 2 3 4
	2 4 6 8
	3 6 9 12
	4 8 12 16   12�� ���° ���ڴ�? >> 12���� ���� ������ ���� �ȴ�
									>> 13��>> 14��° 

	1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16
	k�� 8�϶� start�� 1~4������ ����ų ���̴�. (���������� ���ڸ� ����Ų��.) 	
*/

ll getOrder(ll x) {
	//x�� ���°���� ��ȯ�ϴ� �Լ�. 
	ll result = 0;
	for(int i=1; i<=n; i++){
		if((ll)i*n < x){
			result+=n;// x�� ���κ��� Ŭ�� 	
		}else{
			if(x%i==0)  result += (x/i)-1; // 0���� ����������� ��� -1 
			else result += x/i; 	
		}//if		
	}//for-i	
	return result+1;
}//getOrder

//k��° ���ڰ� �����̳� >> Ư������ p�� ���° �ΰ�? 
//1���� n*n �����߿���
//���� p�� ���° �ΰ�? 
int main(){
		
	cin >> n >> k; // N: ��  k: ��°�� ������ 
	ll start =1, end = n*n+1; // mid�� ���� end�� �ɼ����� 
							  // >> n*n�� Ž���ϱ����� end+1���Ѵ�. 
	while(start+1 < end) {//start�� end�� �پ��ִ�.
	
		//start : �׻� ������ �Ǵ� ���ں��� �۰ų� ���� ���� 
		//end 	: �׻� ������ �Ǵ� ���ں��� ū ����. 
		ll mid = (start+end)/2;
		ll myOrder = getOrder(mid);
		
		// if(myOrder == k) return mid // ���� ���ڰ� �ɸ��� �����ϱ� 
		
		if(myOrder <= k) start = mid;
		else end = mid;		
	}//while
	printf("%lld\n", start);
	
	return 0;
}//main

#include<iostream>
using namespace std;

int gcd(int a, int b){	
	return b ? gcd(b, a%b) : a;
}//gcd

int gcd2(int a, int b){
	while(b>0){
		int tmp=a;
		a=b;
		b=tmp%b;
	}
	return a;
}//gcd2

int main(){
	
	int n; cin >> n;
	int tree[100005];
	for(int i=0; i<n; i++) scanf("%d", &tree[i]);
		
	int GCD=0;
	
	for(int i=0; i<n-1; i++){
		int distance = tree[i+1] - tree[i];
		if(i==0) GCD =distance;
		else GCD = gcd(GCD, distance);
	}
	
	int total = ((tree[n-1]-tree[0])/GCD)-n+1;
	
	printf("%d\n", total);	
	
	return 0;
}
















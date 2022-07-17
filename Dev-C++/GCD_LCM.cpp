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

int lcm(int a, int b){
	return a*b/gcd(a,b);
}
int main(){
	
	int a, b; cin >> a >> b;
	
	cout << gcd(a,b)<<"\n"<<lcm(a,b);
	return 0;
}//main

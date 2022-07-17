#include<iostream>
using namespace std;
int gcd(int a, int b){
	return 	b ? gcd(b, a%b) : a ;
}//gcd

int main(){
	int arr[100010]={0};
	int n,GCD; cin >> n;	
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}//for-i	
//	int GCD = 0;
	for(int i=0; i<n-1; i++){
		int dis = arr[i+1] - arr[i];
		if(i==0) GCD=dis;
		else GCD=gcd(GCD, dis);
	}//for-i
	
	cout << ((arr[n-1]-arr[0])/GCD)-n+1;
	
	return 0;
}//main

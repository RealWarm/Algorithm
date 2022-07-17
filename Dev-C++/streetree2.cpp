#include<iostream>
using namespace std;
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}//gcd

int main(){
	int arr[100010];
	int n, gd; cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}//for-i		
	for(int i=0; i<n-1; i++){
		int dis = arr[n+1]-arr[n];
		if(i==0) gd = dis;
		else gd = gcd(gd, dis);
	}//for-i	
	cout<< ((arr[n-1]-arr[0])/gd)-n+1;	
	return 0;
}//main

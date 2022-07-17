#include<iostream>
using namespace std;

int gcd(int a, int b){
	
	return b ? gcd(b, a%b) : a;
}//gcd

int lcm(int a, int b){
	return a*b/gcd(a,b);
}

int main(){
	
	int arr[2][2];
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cin >> arr[i][j];
		}
	}	
	int com = lcm(arr[0][1], arr[1][1]);//분모를 통일한다. >> 분모의 최소공배수를 배운다. 
	int sumSon = arr[0][0]*(com/arr[0][1]) + arr[1][0]*(com/arr[1][1]);
	
	int div = gcd(com, sumSon);
	
	cout << sumSon/div << " " << com/div;
	
	return 0;
}

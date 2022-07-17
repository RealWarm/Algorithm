#include<iostream>
using namespace std;
int arr[100110];

int gcd(int a, int b){
	return b ? b : gcd(a, b%a);
}//gcd

int main(){
	
	int n; scanf("%d", &n);	
	int gd;	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		if(i==0){
			gd=arr[i];
		}else{
			int dis=arr[i]-arr[i-1];
			gd=gcd(gd,dis);
		}		
	}//for-i
	
	int sum=0;
	for(int i=0; i<n-1; i++){
		int dis=arr[i+1]-arr[i];
		sum+=(dis/gd);
	}//for-i
	
	printf("%d", sum);
	return 0;
}//main

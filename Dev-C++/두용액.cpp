#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	
	int arr[100001]={0};
	int num; cin>>num;
	
	for(int i=0; i<num; i++){
		scanf("%d", &arr[i]);
	}
	
	int min = arr[0]+arr[1];
	int num1=arr[0], num2=arr[1];
	
	for(int i=0;i<num; i++){
		for(int j=i+1; j<num; j++){
			if(min<abs(arr[i]+arr[j])){
				num1=arr[i];
				num2=arr[j];
			}
		}//for-j
	}//for-i
	
	cout << num1 << " " << num2;
	
	
	return 0;
}

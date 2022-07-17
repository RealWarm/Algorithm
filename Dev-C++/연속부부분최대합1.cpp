#include<iostream>
#include<cstdio>
using namespace std;
int n;
int arr[100010];

int getResult(int start, int end){
	//arr의 start ~ end 까지 고려했을 때의 연속부분 최대합 
	
	if(start == end) return arr[start];
	
	int mid = (start+end)/2;
	int lmax = getResult(start, mid);
	int rmax = getResult(mid+1, end);
	
	int srmax = arr[mid];
	int slmax = arr[mid+1];
	
	int lssum = arr[mid];
	int rssum = arr[mid+1];
	
	for(int i=mid+2; i<=end; i++){
		rssum+=arr[i];
		if(srmax<rssum){
			srmax=rssum;
		}
	}
	
	for(int i=mid-1; i>=start; i--){
		lssum+=arr[i];
		if(slmax<lssum){
			slmax=lssum;
		}
	}
	
	int midmax = srmax + slmax;
	
	if(lmax>=rmax && lmax>=midmax) return lmax;
	else if(rmax>=lmax && rmax>=midmax) return rmax;
	else if(midmax>=lmax && midmax>= rmax)return midmax;
	
}//getResult

int main(){
	
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> arr[i];		
	}
	
	cout << getResult(0, n-1);
	
	return 0;
}

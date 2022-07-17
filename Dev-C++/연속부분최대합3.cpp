#include<iostream>
#include<cstdio>
using namespace std;
int data[100010];

int getResult(int start, int end){
	//start부터 end까지 연속된 숫자의 최대합을 반환하는 함수 
	if(start>=end) return data[0];
	int mid=(start+end)/2;
	
	int lmax = getResult(start, mid);
	int rmax = getResult(mid+1, end);
	
	int lssum=0, lsmax=-99999999;
	for(int i=mid; i>=start; i--){
		lssum+=data[i];
		if(lssum>lsmax){
			lsmax=lssum;
		}//if
	}//for-i
	
	int rssum=0, rsmax=-9999999;
	for(int i=mid+1; i<=end; i++){
		rssum+=data[i];
		if(rssum>rsmax){
			rsmax=rssum;
		}//if
	}//for-i
	
	int midmax=lsmax+rsmax;
	
	if(lmax>=rmax && lmax>=midmax) return lmax;
	else if(rmax>=lmax && rmax>=midmax) return rmax;
	else return midmax;
	
}//getResult
int main(){	
	int n; cin >> n;
	for(int i=0; i<n; i++)
		scanf("%d", &data[i]);		
	printf("%d", getResult(0, n-1));	
	return 0;
}//main

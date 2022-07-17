#include<iostream> 
using namespace std;
int arr[100010];
int getResult(int start, int end){
	
	if(start == end) return arr[start];
	int mid = (start+end)/2;
	
	int lmax=getResult(start, mid);
	int rmax=getResult(mid+1, end);
	
	int lsmax = arr[mid];
	int rsmax = arr[mid+1];
	
	int lss = arr[mid];
	int rss = arr[mid+1];
	
	for(int i=mid+2; i<=end; i++){
		rss+=arr[i];
		if(rsmax<rss){
			rsmax=rss;
		}//if
	}//for-i
	
	for(int i=mid-1; i>=start; i--){
		lss+=arr[i];
		if(lsmax<lss){
			lsmax=lss;
		}
	}//for-i
	
	int midmax = rsmax + lsmax;
	
	if(lmax>=rmax && lmax>=midmax) return lmax;
	else if(rmax>=lmax && rmax>=midmax) return rmax;
	else return midmax;
}//getResult

int main(){	
	int n; cin >> n;
	for(int i=0; i<n; i++)
		cin>>arr[i];	
	cout << getResult(0, n-1);	
	return 0;
}//main

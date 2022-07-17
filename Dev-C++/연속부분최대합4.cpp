#include<cstdio>
using namespace std;
int result[100010];

int get(int start, int end){
	//arr의 start ~ end 까지 고려했을 때의 연속부분 최대합 
	if(start>=end) return result[start];	
	int mid = (start+end)/2;
	
	int lmax = get(start, mid);
	int rmax = get(mid+1, end);
	
	int lssum=0, lsmax=-9999999;
	for(int i=mid; i>=start; i--){
		lssum+=result[i];
		if(lssum>lsmax){
			lsmax=lssum;
		}//if
	}//for-i
	
	int rssum=0, rsmax=-9999999;
	for(int i=mid+1; i<=end; i++){
		rssum+=result[i];
		if(rssum>rsmax){
			rsmax=rssum;
		}//if
	}//for-i
	
	int midmax=lsmax+rsmax;	
	if(lmax>=rmax && lmax>=midmax) return lmax;
	else if(rmax>=lmax && rmax>=midmax) return rmax;
	else return midmax;	
}//get

int main(){	
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &result[i]);	
	printf("%d", get(0,n-1));	
	return 0;
}//main

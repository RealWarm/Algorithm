#include<iostream> 
#include<algorithm>
using namespace std;
int arr[15], n, k;

int main(){
	
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		int a, b=987987987, inx;
		scanf("%d", &a);
		for(int j=0; j<k; j++){
			if(arr[j]<b){
				b=arr[j];
				inx=j;
			}//if
		}//for-j
		arr[inx]+=a;
	}//for-i
	
	sort(arr, arr+k, greater<int>());
	printf("%d", arr[0]);
	
	return 0;
}//main

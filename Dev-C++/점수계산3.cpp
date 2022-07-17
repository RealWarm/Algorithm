#include<iostream>
using namespace std;
int arr[110];

int main(){
	
	int n; cin>> n;
	
	int cnt=1, sum=0;
	for(int i=0; i<n; i++){
		int a; cin>>a;
		if(a==1){
			sum+=cnt;
			cnt++;
		}else if(a==0){
			cnt=1;
		}
	}//for-i
	printf("%d", sum);
	return 0;
}//main

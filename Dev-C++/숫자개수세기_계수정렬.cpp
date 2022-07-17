#include<iostream> 
#include<cstdio>
using namespace std;

int main(){
	
	int arr[100001]={0};
	int n, q; cin >> n >> q;
	
	for(int i=0; i<n; i++){
		int num; scanf("%d", &num);
		arr[num]++;		
	}//for-i	
	
	while(q--){
		int num; scanf("%d", &num);
		printf("%d\n", arr[num]);		
	}//while	
	
	return 0;
}//main

#include<iostream> 
using namespace std;

int main(){
	
	int arr[1001]={0};
	int num; cin>>num;
	
	for(int i=0; i<num; i++){
		int inx; cin >> inx;
		if(arr[inx]<2){
			arr[inx]++;
		}//if
	}//for-i
	
	int sum=0;
	for(int i=0; i<1002; i++){
		sum+=arr[i];
	}
	
	if(sum>=6){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	
	return 0;
}

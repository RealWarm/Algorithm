#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	int num; cin>>num;
	int arr[10][10]={0};
	
	for(int i=0; i<num; i++){
		for(int j=0; j<10; j++){
			if(arr[i][j]==0){
				arr[i][j]=1;
			}else if(arr[i][j]==1){
				arr[i][j]=0;
			}
		}//for-j
	}//for-i
	
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			cout<< arr[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}

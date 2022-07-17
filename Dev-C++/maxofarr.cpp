#include<iostream>
#include<algorithm>
using namespace std;
int arr[9][9];

int main(){	
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin >> arr[i][j];
		}
	}
	
	int maxv=arr[0][0];
	int rei=0;
	int rej=0;
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(arr[i][j]>maxv){
				maxv=arr[i][j];
				rei=i;
				rej=j;
			}//if
		}//for-j
	}//for-i
	
	
	cout << maxv << "\n" << rei+1 << " " << rej+1;
	
	return 0;
}

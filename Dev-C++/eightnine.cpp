#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	int row, col; cin >> row >> col;
	vector<vector<int> > arr(row, vector<int>(col));
	
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cin>> arr[i][j];			
		}//for-j		
	}//for-i
	
	for(int i=0; i<row; i++){
		for(int j=col-1; j>=0; j--){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	
	return 0;
}

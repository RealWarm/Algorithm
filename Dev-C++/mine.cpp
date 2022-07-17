#include<iostream>
#include<vector>
using namespace std;
int dx[] ={0,0,1,-1,1,1,-1,-1};
int dy[] ={1,-1,0,0,1,-1,1,-1};

int main(){
	
	int row, col; cin >> row >> col;
	int x, y; cin >> x >> y;
	x-=1;
	y-=1;
		
	vector<vector<int> > arr(row, vector<int>(col));
	
	for(int i=0; i<arr.size(); i++){
		for(int j=0; j<arr[0].size(); j++){
			cin >> arr[i][j];			
		}//for-j		
	}//for-i
	
	if(arr[x][y]==1){
		cout << "game over";
		return 0;
	}
	
	int minenum=0;
	for(int k=0; k<8; k++){
		int ntx = x+dx[k];
		int nty = y+dy[k];
		if(ntx>=0 && ntx<row && nty>=0 && nty<col){
			if(arr[ntx][nty]==1){
				minenum++;
			}
		}		
	}//for-k	
	
	cout << minenum;
	
	return 0;
}//main

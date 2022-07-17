#include<iostream>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*
0 0 0 0 0 0 0 1
0 0 0 0 2 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0
*/
int main(){
	
	int arr[8][8];
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin >> arr[i][j];
		}//for-j		
	}//for-i
	
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(arr[i][j]==2){
				for(int k=0; k<4; k++){
					int ntx=i, nty=j;
					while(!(ntx<0 || ntx>=8 || nty<0 || nty>=8)){
						ntx+=dx[k];
						nty+=dy[k];
						if(arr[ntx][nty]==1){
							cout << 1;
							return 0;
						}else if(arr[ntx][nty]==0){
							continue;
						}else if(arr[ntx][nty]==3 || arr[ntx][nty]==2){
							break;
						}//if-else
					}//while
				}//for-k				
			}//if
		}//for-j		
	}//for-i
	
	cout<<0;
		
	return 0;
}

#include<iostream>
using namespace std;

int main(){
	
	int n; cin >> n; //색종이의 장수 
	int arr[110][110]={0};
	int ans[110]={0};
	
	for(int i=1; i<=n; i++){
		int x, y, width, height; 
		scanf("%d %d %d %d", &x, &y, &width, &height);
		
		for(int a=0; a<width; a++){
			for(int b=0; b<height; b++){
				arr[x+a][y+b]=i;
			}//for-b
		}//for-i
		
	}//for-i	
	
	for(int t=1; t<=n; t++){
		for(int i=0; i<110; i++){
			for(int j=0; j<110; j++){
				if(arr[i][j]==t){
					ans[t]++;
				}
			}//for-j
		}//for-i
	}//for-t
	
	for(int i=1; i<=n; i++){
		cout << ans[i] << endl;		
	}
	
	return 0;
}


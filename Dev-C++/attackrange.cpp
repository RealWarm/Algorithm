#include<iostream> //BFS말고 좌표간의 차이로 구한다. 
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
	
	int n; cin >> n; // 가로 세로 
	int x, y, r; cin >> x >> y >> r; // 좌표 x, y && 사거리
	x-=1; y-=1;
	
	vector<vector<int> > arr(n, vector<int>(n));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int sum = abs(x-i) +abs(y-j);			
			if(sum<=r && i==x && j==y){
//				cout<< sum << " ";
				cout << "x" << " ";
			}else if(sum<=r){
//				cout << "x" << " ";
				cout<< sum << " ";
			}else{
				cout << 0 << " ";
			}
		}		
		cout << endl;
	}
	
	return 0;
}





/*
//0103_2

#include<iostream> 
#include<cmath>
using namespace std;

int main(){
	int n; cin >> n;
	int x, y, r; cin >> x >> y >> r;
		
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			int dist = abs(x-i) + abs(y-j);
			if(dist == 0){
				cout << "x ";
			}else if(dist <= r){
				cout << dist << " ";
			}else if(dist > r){
				cout << "0 ";
			}
		}//for-j
		cout<<endl;
	}//for-i
	
	return 0;
}//main

*/

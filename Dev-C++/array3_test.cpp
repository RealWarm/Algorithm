#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	int n; cin >> n; // n : layer 

	//방법 4>> 격자를 만들고 위치를 조정하면서 값을 대입한다.
	vector<vector<int> > arr(n, vector<int>(n));
	
	int cnt =1;
	for(int i=0; i<n; i++){
		int nwx = 0;
		int nwy = i;
		arr[nwx][nwy]=cnt++;
		for(int j=1; j<=i; j++){
			nwx +=1;
			nwy -=1;
			arr[nwx][nwy]=cnt++;
		}
	}//for-i
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(arr[i][j]==0){
				continue;
			}else{
				cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}//main

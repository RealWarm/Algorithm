#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	int n; cin >> n; // n : layer 
	
//	//방법 1 
//	int snum=1;
//	for(int i=0; i<n; i++){
//		for(int j=1; j<=n-snum; j++){
//			cout << snum << " ";
//			snum+=j;
//		}//for-j		
//	}//for-i
//	
//	//방법 2 
//	int frontNum=1;
//	for(int i=2; i<=n+1; i++){
//		
//		int layerNum=frontNum;
//		for(int j=1; j<=n+2-i; j++){
//			cout << layerNum;
//			layerNum+=
//		}
//		
//		frontNum+=i;
//	}//for-i
	
//	//방법 3 >> 먼저 배열에 숫자를 저장한후에 좌표를 조정해보자. 
//	int totalcnt=((n+1)*n)/2;
//	vector<int> arr(totalcnt);
//	for(int i=0; i<totalcnt; i++){
//		arr[i]=i+1;		
//	}//for-i
//	
//	int t=0;
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n-i; j++){
//			cout << arr[t++] << " ";
//		}
//		cout<< endl;
//	}//for-i
	
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

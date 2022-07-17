#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr;
    int key, i, j;
    
    for(int i=0; i<n; i++){
    	int num; cin>>num;
    	arr.push_back(num);
	}
    
    for( i=1; i<n; i++){
    	key =arr[i];
    	for( j=i-1; j>=0; j--){
    		
    		if(arr[j]>key){
    			arr[j+1]=arr[j];    			
//    			for(int t=0; t<arr.size();t++){
//    				cout << arr[t] << " ";
//				}//for-t
//				cout<< endl;
			}else{
				break;
			}//if-else		
		}//for-j
		arr[j+1]= key;
		for(int t=0; t<arr.size();t++){
    		cout << arr[t] << " ";
		}
		if(i != n-1){
			cout << endl;
		}
		
		
	}//for-i
//	cout << endl;
//    for(int t=0; t<arr.size();t++){
//    		cout << arr[t] << " ";
//	}
    
    return 0;
}

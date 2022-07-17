#include<iostream> 
using namespace std;

int main(){
		
	int n; cin >> n;
	
	int cnt=0;
	int sum=0; 
	for(int i=0; i<n; i++){
		int sc; cin >>sc;
		if(sc==0){
			cnt=0;
		}else{
			cnt++;
		}
		sum += cnt;			
	}//for-i
	
	cout << sum;
	
	return 0;	
}//main

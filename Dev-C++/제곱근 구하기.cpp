#include<iostream> 
using namespace std;

int main(){
	
	int num; cin >> num;
	
	int ans=0;
	int cnt=1;
	while(1){
		if(num<=cnt*cnt){
			ans = cnt;		
			break; 
		} 
		cnt++;
	}//while
	
	cout << ans;
	
	return 0;
}

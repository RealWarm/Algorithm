#include<iostream>
using namespace std;



int main(){
	
	int n, m; cin >> n >> m;
		
	for(int i=n, cnt=1; i<=m; i++, cnt++){
		cout << i << " ";
		if(cnt%8==0){
			cout<<endl;
		}
	}//for-i
	
	
	return 0;
}

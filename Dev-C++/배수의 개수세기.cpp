#include<iostream>
using namespace std;

int main(){
	
	int a, b, c; cin >> a >> b >> c;
	int start, end;
	
	if(a<=b){
		start = a;
		end = b;		
	}else{
		start = b;
		end = a;
	}
	
	int cnt=0;	
	for(int i=start; i<=end; i++){
		if(i%c==0)cnt++;
	}
	
	cout << cnt;
	
	return 0;
}//main

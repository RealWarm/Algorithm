#include<iostream>
using namespace std;

int fact(int n){
	
	if(n==1){
		return 1;
	}else{
		return n*fact(n-1);
	}//if-else
	
}//fact

int main(){
	
	int num; cin>>num;
	cout<<fact(num);
	return 0;
}//main

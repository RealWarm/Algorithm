#include<iostream>
using namespace std;

int main(){
	
	int arrA[11]={0}, arrB[11]={0};
	int scoreA=0, scoreB=0;
	
	for(int i=0; i<10; i++){
		cin>>arrA[i];
	}
	for(int i=0; i<10; i++){
		cin>>arrB[i];
	}
	
	for(int i=0; i<10; i++){
		if(arrA[i]>arrB[i]){
			scoreA++;
//			cout<<"A";
		}else if(arrA[i]<arrB[i]){
			scoreB++;
//			cout<<"B";
		}else{
//			cout<<"D";
		}//if-else
	}//for-i
	
	if(scoreA>scoreB){
		cout<<"A";
	}else if(scoreA<scoreB){
		cout<<"B";
	}else{
		cout<<"D";
	}
	
	return 0;
}

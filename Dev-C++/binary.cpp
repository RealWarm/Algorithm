#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;

void makebin(int n){
	//n을 이진수로 만들어반환한다. 
	if(n==0){
		return;
	}else{
		arr.push_back(n%2);
		makebin(n/2);
	}//if-else	
}//makebin

int main(){
	
	int num; cin >> num;
	makebin(num);
	
	for(int i=arr.size()-1; i>=0; i--){
		cout << arr[i];
	}	
	
	return 0;
}//main


//#include<iostream>
//using namespace std;
//int n;
//
//void make(int n, int kk){
//	if(n==0){
//		return;
//	}else{
//		int tmp=n%kk;
//		make(n/kk, kk);
//		printf("%d", n%kk);		
//	}//if
//}//make
//
//int main(){
//	scanf("%d", &n);
//	make(n, 2);
//	return 0;
//}//main

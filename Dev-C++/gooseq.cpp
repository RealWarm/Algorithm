#include<iostream>
#include<cstdio>
using namespace std;
int result[100];
int n, ended;

int check(int x, int length){
	//result[x]가 오른쪽끝이고, 길이 length의 중복이 있는지 판별
	//중복이 없다면 true, 아니면 false	
	for(int i=0; i<length; i++) {
		if(result[x-i] != result[x-i-length]){
			return 1;
		}//if
	}//for-i
	return 0;
}//isPossible

void getResult(int x){
	//result[x]를 결정한 후, result[x+1]부터 쭉 결정해 나가는 함수.
	//result[x] ~ result[n-1]까지 결정하는 함수.
	
	//(1) x번째 숫자를 결정한다.
	//(2) x+1번째 숫자를 결정하러 간다.  	
	if(ended==1) return;
	
	if(x>=n){
		for(int i=0; i<n; i++){
			cout<<result[i];
		}
		cout<<endl;
		ended=1;
		return;
	}//if
	
	for(int i=1; i<=3; i++){
		result[x]=i;
		int flag=0;
		for(int j=1; j<=(x+1)/2; j++){
			if(!check(x,j)){
				flag=1;
				break;
			}		
		}//for-j				
		
		if(flag == 0){
			getResult(x+1);
		}//if
	}//for-i	
}//getResult

int main(){	
	cin>>n;
	getResult(0);	
	return 0;
}//main

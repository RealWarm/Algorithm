#include<iostream>
#include<cstdio>
using namespace std;
int n, r;
int result[20];

void getResult(int x){

	if(x>=r){
		bool flag =false;
		for(int i=0; i<r; i++){
			for(int j=0; j<r; j++){
				if(i!=j && result[i]==result[j]){
					flag=true;
				}//if
			}//for-j
		}//for-i
					
		if(flag==false){
			for(int i=0; i<r; i++){
				printf("%c", result[i]+'a');
			}
			cout << '\n';
		}//if
		
	}else if(x < r){
		for(int i=0; i<n; i++){
			result[x]=i;
			getResult(x+1);
		}//for-i		
	}//if-else
	
}//getResult

int main(){	
	cin >> n >> r; // n���� �ҹ����߿��� r����							 
	getResult(0);	
	return 0;
}//main

//void myFor(int x, int r){
//	//�� r���� for���� ��ø�ž� �Ѵ�.
//	//���� x��° for�� �̴�.
//	if(x>r)  return;
//	else{
//		for(int i=1 i<n; i++){
//			result[x]=i;
//			myFor(x+1, r);
//		}//for-i
//	}//if-else
//	
//}//myFor

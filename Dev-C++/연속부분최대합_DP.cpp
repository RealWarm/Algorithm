#include<iostream>
using namespace std;
int T[100];
int Data[100];
int n;

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &Data[i]);
	}
	
	T[0]=Data[0]; // 점화식으로 못만드니깐 직접채워준다. 
	
	for(int i=1; i<n; i++){//테이블을 채운다.
		if(T[i-1]+Data[i]>Data[i]){
			T[i]=T[i-1]+Data[i];
		}else{
			T[i]=Data[i];	
		}//if
	}//for-i
	
	int mmax=-987987987;
	for(int i=0; i<n; i++){
		if(T[i]>mmax){
			mmax=T[i];
		}//if
	}//for-i
	
	printf("%d\n", mmax);
	
	return 0;
}//main

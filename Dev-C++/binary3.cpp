#include<iostream>
#include<algorithm>
using namespace std;
int bin[20];

//void makeBin(int n){
//	
//	int i=0;
//	for(; ; i++){	
//		if(n==0) break;
//		bin[i]=n%2;
//		n/=2;
//	}//while
//	reverse(bin, bin+i);
//	for(int j=0; j<i; j++){
//		printf("%d", bin[j]);
//	}
//		
//}//makeBin

void makeBin(int n){
	if(n==0) return;
	else{		
		makeBin(n/2);
		printf("%d", n%2);
	}//if
}//makeBin

int main(){	
	int num; scanf("%d", &num);
	if(num==0){
		printf("0\n");
	}else{
		makeBin(num);			
	}	
	return 0;
}//main

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	
	char str1[110]={0}, str2[110]={0};
	int num1[110]={0}, num2[110]={0};
	int big[110]={0}, small[110]={0}, result[110]={0};
	scanf("%s %s", str1, str2);
		
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	for(int i=0; i<len1; i++){
		num1[110-len1+i] = str1[i]-'0';
	}//for-i
	for(int i=0; i<len2; i++){
		num2[110-len2+i] = str2[i]-'0';
	}//for-i
	
	int flag=0;
	for(int i=0; i<110; i++){
		if(num1[i]<num2[i]){
			flag=1;
			break;
		}else if(num1[i]>num2[i]){
			flag=0;
			break;
		}else if(num1[i]==num2[i] && i==109){
			cout<< 0;
			return 0;
		}else if(num1[i]==num2[i]){
			continue;
		}
				
		if(i==109){
			cout<<0;
			return 0;
		}
	}//for-i
	/////////////////////////////////////////////////////
	//비교 
	if(flag==0){//str1>str2 이면 
		for(int i=0; i<110; i++) {
			big[i]=num1[i];
			small[i]=num2[i];
		}
	}else{
		for(int i=0; i<110; i++){
			big[i]=num2[i];
			small[i]=num1[i];
		}		
	}
	
	
	
//	for(int i=0; i<110; i++){
//		if(big[i]!=0){
//			cout <<big[i];
//		}
//	}
//	cout << endl;
//	for(int i=0; i<110; i++){
//		if(small[i]!=0){
//			cout <<small[i];
//		}
//	}
//	cout << endl;
	
	////////////////////////////////////////////////
	for(int i=109; i>=0; i--){
		if(small[i]>big[i]){
			big[i]+=10;
			big[i-1]-=1;
		}
		result[i]= big[i]-small[i];
	}
	
	
	if(flag==1) cout<<"-";
	for(int i=0; i<110; i++){
		if(result[i]!=0){
			for(int j=i; j<110; j++){
				printf("%d", result[j]);
			}//for-j
			break;
		}//if
	}//for-i
	
}// main

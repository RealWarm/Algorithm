#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
	int n; scanf("%d", &n);
	string wild; cin >> wild;
	for(int i=0; i<n; i++){
		string tmp; cin >> tmp;
		if(wild.size()-1>tmp.size()){
//			printf("1111111111111111\n");
			printf("NE\n");
			continue;
		}//if
		//////////////////////////////////////////
		if(tmp[0] != wild[0] || 		    
		    tmp[tmp.size()-1] != 
			wild[wild.size()-1]){
//		    printf("2222222222222222\n");
			printf("NE\n");
			continue;
		}//if	
		//////////////////////////////////////////
		int inx=0;
		int flag=0;
		for(int a=0; a<tmp.size(); a++){
			if(wild[inx]=='*' && wild[inx+1]==tmp[a]){
				inx+=2;
			}if(wild[inx]=='*'){
				continue;
			}else if(wild[inx]==tmp[a]){
				inx++;
			}
			
			if(inx>=wild.size() &&
				a<tmp.size()-1){
//				printf("33333333333333333333333\n");
				printf("NE\n");
				flag=1;
				break;
			}
			
		}//for-a
		
		if(flag==1) continue;
		if(inx==wild.size()){
//			printf("44444444444444444444444\n");
			printf("DA\n");
		}else if(inx<wild.size()){
//			printf("5555555555555555555555555\n");
			printf("NE\n");
		}		
		
	}//for-i
	return 0;
}//main


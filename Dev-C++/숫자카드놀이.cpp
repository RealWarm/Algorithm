#include<iostream>
#include<algorithm>
using namespace std;
int ch[4];
int ins[4];
int ans[4];
int target, cnt;

void get(int x){
	
	if(x==3){
		cnt++;
		
		if(cnt==target){			
			for(int i=0; i<3; i++){
				printf("%d ", ins[i]);
			}//for-i
		}//if
	}else{
		for(int i=0; i<3; i++){
			if(ch[i]==0){			
				ins[x]=ans[i];
				ch[i]=1;
				get(x+1);
				ch[i]=0;
			}//if
		}//for-i
	}//if
	
}//get

int main(){
	
	for(int i=0; i<3; i++){
		scanf(" %d", &ans[i]);		
	}
	scanf(" %d", &target);		
	
	sort(ans, ans+3);	
	get(0);
		
	return 0;
}//main

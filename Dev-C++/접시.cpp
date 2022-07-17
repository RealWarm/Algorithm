#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int main(){
	int result[60], resultlen=0;
	int flag =0;
	char data[30];
	int len;
	char st[30];
	int top=0;
	int cs=0;
	int alp ='a';
	
	scanf("%s", data);
	len =strlen(data);
	
	while(1){
		char topval;
		if(top==0) topval=0;
		else topval=st[top-1];
		
		char curval=data[cs];
		
		if(topval ==curval){
			st[top-1]=0;
			top--;
			result[resultlen]=0;
			resultlen++;
			cs++;
			if(cs>=len){
				flag=1;
				break;
			}
		}else{
			if(alp>='a'+len){
				flag=0;
				break;
			}			
			st[top]=alp;
			top++;
			result[resultlen++]=1;			
			alp++;
		}		
	}//while
	if(flag==1){
		for(int i=0; i<resultlen; i++){
			if(result[i]==0)printf("pop\n");
			else printf("push\n");
		}
	}else{
		printf("impossible\n");
	}//if-else
	
	return 0;
}//main

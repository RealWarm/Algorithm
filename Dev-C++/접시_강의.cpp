#include<cstdio>
#include<cstring>

int main(){
	
	char data[30];
	int len;
	char myStack[30];
	int myTop=0;
	int cursor=0; 
	
	scanf("%s", data);
	len = strlen(data);
	/*
		(1) 스택의 가장 윗부분이 내가 지금 뽑아야하는 알파벳이라면, POP
		(2) 그게 아니라면 PUSH 
	*/
	
	while(1){
		char topElement;
		
		if(myTop==0){
			topElement=0;
		}else{
			topElement=myStack[myTop-1];
		}
		
		char currentElement = data[cursor];
		if(topElement == currentElement){
			myStack[myTop-1] = 0;
			myTop--;
		}//if
		
	}//while
	
	return 0;
}//main

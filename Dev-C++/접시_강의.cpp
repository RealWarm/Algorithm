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
		(1) ������ ���� ���κ��� ���� ���� �̾ƾ��ϴ� ���ĺ��̶��, POP
		(2) �װ� �ƴ϶�� PUSH 
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

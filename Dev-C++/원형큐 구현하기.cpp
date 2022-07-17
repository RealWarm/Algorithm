#include<iostream> 
using namespace std;

int main(){
	
	int myQueue[101]={0};
	int front=0, rear=0, num=0;
	int n, m; //크기, 연산의 갯수
	scanf("%d %d", &n, &m);
	 
	for(int i=0; i<m; i++){
	 	int a; 
		scanf("%d", &a);
	 	
	 	if(a==1){
	 		int val; scanf("%d", &val);
			
	 		if(num>=n){
	 			printf("Overflow\n");
			 }else{			 	
			 	myQueue[rear]=val;
			 	if(rear==n-1){
			 		rear=0;
				 }else{
				 	rear++;				 	
				 }//if-else
				 num++;
			 }//if-else
		}else if(a==2){
		 	if(num<=0){
		 		printf("Underflow\n");
			 }else{
			 	myQueue[front]=0;			 	
			 	if(front==n-1) front=0;
			 	else front++;			 	
			 	num--;
			 }//if-else
		}else{
		 	if(num<=0){
		 		printf("NULL\n");
			 }else{
			 	printf("%d\n", myQueue[front]);
			 }
		}
	 }//for-i
		
	return 0;
}//main

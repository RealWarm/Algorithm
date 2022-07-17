#include<iostream> 
using namespace std;
int qq[110];
//1 : push
//2 : pop
//3 : front

int main(){
	int n, m; scanf("%d %d", &n, &m); // n: 큐의 크기, m: 연산의 개수
	int cnt=0, rear=0, front=0;	
	while(m--){
		int a; scanf("%d", &a);
		if(a==1){//push
			int b; scanf("%d", &b);
			if(cnt>=n){
				printf("Overflow\n");				
			}else{
				qq[rear++]=b;
				cnt++;
				if(rear>=n){
					rear=0;
				}
			}//if-2			
		}else if(a==2){//pop
			if(cnt<=0){
				printf("Underflow\n");
			}else{
				qq[front++]=0;				
				cnt--;
				if(front>=n){
					front=0;
				}
			}
		}else if(a==3){//front
			if(cnt<=0){
				printf("NULL\n");
			}else{
				printf("%d\n", qq[front]);
			}
		}//if
		
	}//while
		
	return 0;
}//main

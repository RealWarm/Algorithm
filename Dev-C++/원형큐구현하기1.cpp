#include<cstdio> 
using namespace std;

int main(){
	int arr[101], front=0, rear=0, cnt=0;
	int n, m; scanf("%d %d", &n, &m);
	
	while(m--){
		int a; scanf("%d", &a);
		
		if(a==1){//push
			int num; scanf("%d", &num);
			if(cnt>=n){
				printf("Overflow\n");
				continue;
			}else{
				arr[rear]=num;
				if(rear==n-1){
					rear=0;
				}else{
					rear++;
				}
				cnt++;
			}
			
		}else if(a==2){//pop
			if(cnt<=0){
				printf("Underflow\n");
				continue;
			}else{
				arr[front]=0;
				if(front==n-1){
					front=0;
				}else{
					front++;
				}
				cnt--;
			}//if-1		
			
		}else if(a==3){
			if(cnt==0){
				printf("NULL\n");
			}else{
				printf("%d\n", arr[front]);
			}//if-2
		}//if-1
	}//while
	
	return 0;
}//main

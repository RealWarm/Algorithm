#include<iostream> 
using namespace std;

int arr[]={0, 5, 10, 15, 20, 
		   50, 30, 35, 40, 45, 
		   100, 55, 60, 65, 70, 
		   75, 80, 85, 90, 95, 
		   500, 1000, 275, 250, 300, 
		   150, 175, 150, 125, 350, 
		   400};
		   
int temp[][5]={
	{ 5, 22, 23, 24, 25},
	{22, 23, 24, 25, 26},
	{23, 24, 25, 26, 15},
	{24, 29, 30, 20, 21},
	{25, 26, 15, 16, 17},
	{26, 15, 16, 17, 18},
	{27, 28, 24, 29, 30},
	{29, 30, 21, 21, 21},
	{30, 20, 21, 21, 21}
};

int main(){
	int n, cnt=0, flag=0; 
	scanf("%d", &n);
	while(n--){
		int a; scanf("%d", &a);
		if(cnt>=22 && cnt<=30){
			cnt=temp[cnt][a];
		}else{
			cnt+=a;
		}		
		printf("%d ", arr[cnt]);
		if(arr[cnt]==21) break;
	}//while
	return 0;
}//main


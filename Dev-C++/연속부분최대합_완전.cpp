#include<iostream> 
using namespace std;
const int MAX = 100;
int arr[MAX];
int sum[MAX]; // 첫번째 숫자부터 x번째 숫자까지의 합 

int main(){
	
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int a; scanf("%d", &arr[i]);
	}	
	
	sum[0]= arr[0];
	for(int i=1; i<n; i++){
		sum[i] = sum[i-1]+arr[i];
	}
	
	int max = -99999999;
	for(int i=0; i<n; i++){		
		for(int j=i; j<n; j++){
			//start ~ end 까지의 합
			//(1~end까지의 합) - (1~(start-1)까지의 합)
			//sum[end] - sum[start-1]
			// start-1이 음수가 되면 안되니까 예외처리를 해줘야한다. 
			int ssum=0;
			if(i==0){
				ssum=sum[j];
			}else{
				ssum=sum[j]-sum[i-1];	
			}			
//			for(int k=i; k<=j; k++){				
//				ssum+=arr[k];
//			}//for-k
			
			if(ssum>max){
				max=ssum;
			}//if			
		}//for-j		
	}//for-i
	
	printf("%d", max);
	
	return 0;
}//main

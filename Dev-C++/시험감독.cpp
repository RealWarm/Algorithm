#include<iostream>
#include<vector> 
using namespace std;

int main(){
	int n; scanf("%d", &n);//시험장의 개수
	vector<int> arr(n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}//for-i
	
	//정수의 범위는 20억 정도다!!!!!!!!!! 
	long long cnt=0;
	long long b, c; scanf("%d %d", &b, &c); // 총감독관, 부감독관 
	for(int i=0; i<n; i++){
		arr[i]-=b;
		cnt++;
		if(arr[i]>0){//주의!!!!!!!!!!!!!!!!!!!!!!!! 
			if(arr[i]%c==0){
				cnt+=(arr[i]/c);
			}else{
				cnt+=(arr[i]/c)+1;				
			}//if
		}//if
	}//for-i
	
	printf("%lld\n", cnt);
	
	return 0;
}//main

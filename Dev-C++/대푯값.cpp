#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	// 평균, 최빈값 ( 둘이상일 경우 최솟값을 출력한다.)	
	//1. 10으로 나누고 계차수열
	//2. 그냥 계차수열
	//3. 정렬후 카운팅 
	vector<int> arr(10);
	int sum=0;
	for(int i=0; i<10; i++){
		cin >> arr[i];
		sum+=arr[i];		
	}//for-i
	
	sort(arr.begin(), arr.end());
	
	int nwcnt=1;
	int maxcnt=0;
	int binval=arr[0];
	//똑같은것 세기 >> 다르면 max랑 비교해서 저장 >> 다시 세기 >> 같으면 저장 x
	for(int i=0; i<10; i++) {
		if(arr[i]==arr[i+1]){
			nwcnt++;
		}else if( arr[i]!=arr[i+1] && (maxcnt<nwcnt)){
			maxcnt=nwcnt;
			nwcnt=1;
			binval=arr[i];
		}else if( arr[i]!=arr[i+1] && (maxcnt>=nwcnt)){
			nwcnt=1;
		}//if
				
	}//for-i

	
	cout << sum/10 << "\n" <<  binval;	
	
	return 0;	
}

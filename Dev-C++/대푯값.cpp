#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	// ���, �ֺ� ( ���̻��� ��� �ּڰ��� ����Ѵ�.)	
	//1. 10���� ������ ��������
	//2. �׳� ��������
	//3. ������ ī���� 
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
	//�Ȱ����� ���� >> �ٸ��� max�� ���ؼ� ���� >> �ٽ� ���� >> ������ ���� x
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

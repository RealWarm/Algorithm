#include<iostream>
using namespace std;
int arr[30];
int n, cnt;

void get(int sum, int inx){
	//������� ���� ���� sum�̴�.
	//�׸��� ���� inx��° ���ڸ� ������ ����. ��, result[inx] 
	if(sum==n){
		cout << arr[0];
		for(int i=1; i<inx; i++){
			printf("+%d", arr[i]);
		}//for-i
		printf("\n");
		cnt++;
	}else{
		int num;
		if(inx==0) num =n-1;
		else num = n-sum;		
		for(int i=num; i>=1; i--){
			arr[inx] =i;
			if(inx>0 && arr[inx-1]<arr[inx]) continue;				
			get(sum+i, inx+1);			
		}//for-i
	}//if-else
}//getResult

int main(){
	cin >> n;
	get(0,0);	
	cout<<cnt;
	return 0;
}

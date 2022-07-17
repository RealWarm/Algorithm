#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int binarySearch(int arr[], int start, int end, int value){
	//arr�� s��° ������ e��°�� �� value�� ã�� �Լ� 
	//ã���� �ε����� ��ȯ, ��ã���� -1�� ��ȯ. 
	//�׷��� �ʴٸ� -1�� ��ȯ�ϴ� �Լ�
	
	if(start>end) {//���ڰ� �ƿ� �������� ���� ��� >> value�� �������� �ʴ´�. 
		return -1; 
	}else if(start == end){//���ڰ� �ϳ��ΰ�� 
		if(arr[start]==value) return start;
		else return -1;
	}else{//���ڰ� ������ �ִ� ��� 
		int mid= (start+end) /2;//�߰���ġ�� �ε��� 
		if(arr[mid]==value){
			return mid;		
		}else if(arr[mid] > value){
			return binarySearch(arr, start, mid-1, value);
		}else{
			return binarySearch(arr, mid+1, end, value);
		} 
	}//if-else
	
}//binarySearch

int main(){
	
	int arr[300010]={0};
	int n; cin >> n;		
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	int m; cin >> m;
	
	while(m--){		
		int num; cin >> num;
		int result = binarySearch(arr, 0, n-1, num);
		
		if(result==-1){
			printf("0\n");
		}else{
			printf("1\n");
		}		
	}//while
	
	return 0;
}

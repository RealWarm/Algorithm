#include<iostream>
#include<cstdio>
using namespace std;

int binarySearch(int arr[], int start, int end, int value){
	//arr�� s��° ������ e��°�� �� value�� ã�� �Լ� 
	//ã���� �ε����� ��ȯ, ��ã���� -1�� ��ȯ. 	
	
	if(start>end) {
		//���ڰ� �ƿ� �������� ���� ��� >> value�� �������� �ʴ´�. 
		return -1; 
	}else if(start == end){//���ڰ� �ϳ��ΰ�� 
		if(arr[start]==value) return start;
		else return -1;
	}else{//���ڰ� ������ �ִ� ��� 
		int mid= (start+end) /2;//�߰���ġ�� �ε��� 
		if(arr[mid]==value){
			return mid;		
		}else if(arr[mid] > value) return binarySearch(arr, start, mid-1, value);
		else return binarySearch(arr, mid+1, end, value);
	}//if-else
	
}//binarySearch

int main(){
	
	int arr[100];
	int n, m; cin >> n;
	
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
		
	scanf("%d", &m);
	
	int inx = binarySearch(arr, 0, n-1, m);
	
	if(inx == -1){
		printf("���� �����ϴ�. \n");
	}else{
		printf("%d ��°�� ���ڰ� �ֽ��ϴ�. \n", inx);
	}
	
	return 0;
}

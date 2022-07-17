#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int binarySearch(int arr[], int myStart, int myEnd, int value) {
	//arr�� start ���� end���� �߿���
	//value�� ã�� �� ��ġ�� ��ȯ�ϴ� �Լ�.
	//����, ���ٸ� -1�� ��ȯ�Ѵ�. 
	int start, end, mid;
	
	//start : value���� �׻� ���� ���� ����Ŵ
	//end : value���� �׻� ū���� ����Ŵ. 
	if(arr[myStart]>value) return -1;
	else if(arr[myStart]==value) return myStart;
		
	if(arr[myEnd]< value) return -1;
	else if(arr[myEnd]==value) return myEnd;
	
	start = myStart;
	end = myEnd;
	while(start + 1 < end) {
//		printf("start : %d       end : %d\n", start, end);
		
		mid =(start+end)/2;
		if(arr[mid] == value) return mid;
		else if(arr[mid]>value) end = mid;
		else if(arr[mid]<value) start = mid;
	}//while	
	
//	printf("start : %d       end : %d\n", start, end);
	
	return  -1; // start�� end�� ���� �پ��ִ�. 
	
}//binarySearch

int main(){
		 
	int n, q; cin >> n >> q;//n:������ ����, q: ������ ���� 
	int arr[100010]={0};
	
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);		
	}
//	sort(arr, arr+n);
	
	while(q--){
		int num; scanf("%d", &num);
		
		if(binarySearch(arr, 0, n-1, num) == -1){
			printf("NO\n");
		}else if(binarySearch(arr, 0, n-1, num)!=-1){
			printf("YES\n");
		}
	}//while	
	
	return 0;
}//main

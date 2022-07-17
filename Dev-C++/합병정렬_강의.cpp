#include<iostream>
#include<cstdio> 
using namespace std;

void merging(int arr[], int s1, int e1, int s2, int e2){
	//arr�� s1~e1�� �������� , s2~e2�� ������ �����϶�,
	// �� ���� ���ļ� arr�� s1~e2�� ���ĵ� ����� ����� �Լ�
	 
	int p, q;//p�� q�� ���� �ּڰ��� ����Ű�� ������ 
 	int temp[100]; // ������ ����� �����ϴ� �ӽú��� 
 	int temp_inx =0; 
 	p = s1;
 	q = s2;
 	
 	//1 2 4 8   1 2 3 3
 	//  p		q
 	//1 2 2 2 3 3 4 8 	
 	while(p<=e1 && q<=e2){
 		if(arr[p]<= arr[q]){
 			temp[temp_inx++] = arr[p];
			p++; 			
		 }else{
		 	temp[temp_inx++]=arr[q];
		 	q++;
		 }//if-else 		
	 }//while
	
	if(p > e1){ // p�� ������ ������. 
		for(int i=q; i<=e2; i++)
			temp[temp_inx++] = arr[i];
	}else{
		for(int i=p; i<=e1; i++)
			temp[temp_inx++] = arr[i];
	}//if-else
	
	//temp�� �ϼ��� �Ǿ�����
	//arr[s1~e2]������ temp�� ���� ���� 
	for(int i=s1; i<=e2; i++){
		arr[i] = temp[i-s1];
	}
	
}//merging

//arr�� s��° ������ e��° ������ �պ������ϴ� �Լ� 
void mergeSort(int arr[], int start, int end){
	
	if(start>=end){
		return;
	}else{
		//1. ���� ������ �պ�����
		//2. ������ ������ �պ�����
		//3. �� ���� ��ģ��. 
		int mid = (start + end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);		
		// start~mid, mid+1 ~ end ���� �̹� ���� �Ǿ�����
				
		merging(arr, start, mid, mid+1, end);		
	}//if-else 	
}//mergeSort



int main(){
	
	int n; scanf("%d", &n);
	int numbers[100];
	
	for(int i=0; i<n; i++)
		scanf("%d", &numbers[i]);
	
	mergeSort(numbers, 0, n-1);
	
	for(int i=0; i<n; i++)
		printf("%d ", numbers[i]);
	
	return 0;
}//main

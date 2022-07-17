#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> data, int start, int end){ 
	if(start >= end){ // ���Ұ� 1���� ���
	 	return; 
	 } 
	 int pivot = start; 
	 int i = pivot + 1; // ���� ��� ���� 
	 int j = end; // ������ ��� ���� 
	 int temp; 
	while(i <= j){ // �����Ͱ� ������������ �ݺ� 
	 	while(data[i] <= data[pivot]){ i++; }
		while(j > start && data[j] >= data[pivot]){ j--; } 
	  	if(i > j){ // ������ 
		  temp = data[j]; 
		  data[j] = data[pivot]; 
		  data[pivot] = temp; 
		}else{ // i��°�� j��°�� ���� 
			temp = data[i]; 
			data[i] = data[j]; 
			data[j] = temp; 
		} 
	} // ���� ��� 
//	quickSort(data, start, j - 1); 
//	quickSort(data, j + 1, end); 
	for(int i=0; i<data.size(); i++){
		cout << data[i] << " ";
	}
}//quickSort

int main(){
	
	int num; cin >> num;
	vector<int> data(num);
	for(int i=0; i<num; i++){
		cin >> data[i];
	}
	quickSort(data, 0, num-1);
	
	return 0;
}//main

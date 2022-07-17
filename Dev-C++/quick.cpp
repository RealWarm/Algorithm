#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> data, int start, int end){ 
	if(start >= end){ // 원소가 1개인 경우
	 	return; 
	 } 
	 int pivot = start; 
	 int i = pivot + 1; // 왼쪽 출발 지점 
	 int j = end; // 오른쪽 출발 지점 
	 int temp; 
	while(i <= j){ // 포인터가 엇갈릴때까지 반복 
	 	while(data[i] <= data[pivot]){ i++; }
		while(j > start && data[j] >= data[pivot]){ j--; } 
	  	if(i > j){ // 엇갈림 
		  temp = data[j]; 
		  data[j] = data[pivot]; 
		  data[pivot] = temp; 
		}else{ // i번째와 j번째를 스왑 
			temp = data[i]; 
			data[i] = data[j]; 
			data[j] = temp; 
		} 
	} // 분할 계산 
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

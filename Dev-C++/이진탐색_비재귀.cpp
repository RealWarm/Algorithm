#include<iostream>
/*
5 0
-1 0 1 8 9
*/
using namespace std;

int binarySearch(int arr[], int s, int e, int v){
	// arr �迭�� s���� e�������� v�� ã�� �ε����� ��ȯ�Ѵ�.
	// ���� ���ٸ� -1 ��ȯ
	// s :: mid���� ���� ���� ����Ų�� || e :: mid���� ū ���� ����Ų��.
	if(arr[s]>v) return -1;
	else if(arr[s]==v) return s;

	if(arr[e]<v) return -1;
	else if(arr[e]==v) return e;
	printf("while!!!!!!!\n");
	while(s+1<e){ 
		printf("start : %d       end : %d\n", s, e);
		// �� �� ���ڰ� �ִٸ�
		int mid=(s+e)/2;
		if(arr[mid]==v) return mid;
		else if(arr[mid]>v) e=mid;
		else if(arr[mid]<v)	s=mid;
		printf("start : %d       end : %d\n", s, e);
	}//while

	return -1;

}//bin

//int binarySearch(int arr[], int myStart, int myEnd, int value) {
//	//arr�� start ���� end���� �߿���
//	//value�� ã�� �� ��ġ�� ��ȯ�ϴ� �Լ�.
//	//����, ���ٸ� -1�� ��ȯ�Ѵ�. 
//	int start, end, mid;
//	
//	//start : value���� �׻� ���� ���� ����Ŵ
//	//end : value���� �׻� ū���� ����Ŵ. 
//	// value : -3
//	// 1 4 7 10 19 22 24 27 39
//	// S                    E
//	// start�� ���� �� �� ���� ��� 
//	if(arr[myStart]>value) return -1;
//	else if(arr[myStart]==value) return myStart;
//		
//	// value : 50
//	// 1 4 7 10 19 22 24 27 39
//	// S                    E
//	// end�� ���� �� �� ���� ��� 
//	if(arr[myEnd]<value) return -1;
//	else if(arr[myEnd]==value) return myEnd;
//	///////////////////////////////////////////////
//	start = myStart;
//	end = myEnd;
//	while(start + 1 < end) {	// (���� ���ڰ� �ִٸ�)
//		printf("start : %d       end : %d\n", start, end);
//		
//		mid =(start+end)/2;
//		if(arr[mid] == value) return mid;
//		else if(arr[mid]>value) end = mid;
//		else if(arr[mid]<value) start = mid;
//	}//while	
//	
//	printf("start : %d       end : %d\n", start, end);
//	
//				// start + 1 = end 
//	return  -1; // start�� end�� ���� �پ��ִ� >> ã���� �ϴ� ���� ������ 
//	
//}//binarySearch


int main(){
	
	int arr[100];
	int n, m; scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++)
		scanf(" %d", &arr[i]);	
	
	int inx = binarySearch(arr, 0, n-1, m);
	
	if(inx == -1){
		printf("���� �����ϴ�. \n");
	}else{
		printf("%d ��°�� ���ڰ� �ֽ��ϴ�. \n", inx);
	}
	
	return 0;
}


//int binarySearch(int arr[], int mystart, int myend, int val){
//	// arr �迭�� start���� end��������
//	// val ���� ã�� �� ��ġ�� ��ȯ�ϴ� �Լ� 
//	// start : ã�� ������ �׻� ���� ���� ����Ų��.
//	// end : ã�� ������ �׻� ū���� ������Ű��. 
//	
//	if(arr[mystart]==val) return mystart;
//	else if(arr[mystart]>val) return -1;
//	
//	if(arr[myend] == val) return myend;
//	else if(arr[myend]<val) return -1;
//	
//	int s=mystart;
//	int e=myend;
//	int mid;
//	while(s+1<e){ // (���� ���ڰ� �ִ�?) 
//		mid=(s+e)/2;
//		
//		if(arr[mid]==val) return mid;
//		else if(arr[mid]>val) e=mid;
//		else if(arr[mid]<val) s=mid;
//		
//	}//while
//	
//	return -1;
//}//bins









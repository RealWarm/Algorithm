#include<iostream> 
using namespace std;
const int MAX=100005;
int data[MAX];
int n, s;

int check(int interval){
	// ������ ���̰� interval�϶�, ���� S �̻��� ��찡 �ִ°�?
	// ������ 1, ������ 0
	int sum=0;
	
	for(int i=0; i<interval; i++){
		sum+=data[i];
	}//for-i
	
	if(sum>=s) return 1;
	////////////////////////////////////////////
	for(int i=0; i<n-interval; i++){
		sum = sum -data[i]+data[i+interval];
		
		if(sum>=s) return 1;
	}//for-i
	
	return 0;
}//check

int main(){
	
	scanf("%d %d", &n, &s);
	for(int i=0; i<n; i++){
		scanf(" %d", &data[i]);
	}//for-i
	
	if(check(1)==1){
		printf("1���� �������� �ȴ�\n");
		return 0;
	}
	if(check(n)==0){
		printf("�����ϴ� ������ �����ϴ�.\n");
		return 0;
	}	
	//////////////////////////////////////////
	int start=1; // start�� ������ X�� ����Ŵ 
	int end=n;	 //   end�� ������ O�� ����Ŵ 
	while(start+1 < end){
		int mid=(start+end)/2;
		
		if(check(mid)==1){
			// ������ �����Ѵٸ� 
			end=mid;
		}else if(check(mid)==0){
			//������ �������� �ʴٸ�
			start=mid;
		}//if
	}//while
	
	printf("%d\n", end);	
	
	return 0;
}//main



//9 16
//2 1 8 1 3 7 2 6 3






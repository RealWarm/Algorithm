#include<iostream> 
using namespace std;
int arr[1000010];
int inx[1000010];
int n, m, k;//�迭�� ����, ����Ƚ��, ���� ���� ���ϴ� Ƚ�� 

int main(){
	
	int sum=0;
	scanf(" %d %d %d", &n, &m, &k);
	for(int i=1; i<=n; i++){
		int tmp; scanf(" %d", &tmp);
		inx[i]=tmp;
		sum+=tmp;
		arr[i]=sum;
	}//for-i
	
	for(int i=0; i<m+k; i++){
		// a�� 1�̸� b��° �ε����� c�� �ٲ۴�.
		// a�� 2�̸� b��° ������ c��° �������� ���� ���Ͽ� ����Ѵ�. 
		int a, b, c; scanf(" %d %d %d", &a, &b, &c);
		if(a==1){
			arr[b]=arr[b]-inx[b]+c;
		}else if(a==2){
			printf("%d\n", arr[c]-arr[b-1]);
		}//if
		
	}//for-i	 
	
	return 0;
}//main

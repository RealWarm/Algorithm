#include<iostream> 
using namespace std;
int arr[15];
int n, r=10;
int cnt; //���� ���� ���° �й��̳�? 
int flag;

void get(int x){
	// ���� n�� for���� x��° for���̴�.
	// ���� arr[x]�� ���� �����ؾ��� ���ʴ�. 
	if(flag==1) return 0;	
	if(x>=r){
		cnt++;
		if(n==cnt){
			for(int i=0; i<10; i++){
				printf("%d ", arr[i]);
			}//for-i
			printf("\n");
			flag=1;
		}//if
	}else{
		//arr[x]�� ���� ä�� 
		for(int i=1; i<=4; i++){
			arr[x]=i;
			get(x+1);
		}//for-i
	}//if
}//get

int main(){
	scanf("%d", &n);
	get(0);
	return 0;
}//main

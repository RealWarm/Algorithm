#include<iostream>
#include<vector> 
using namespace std;

int main(){
	int n; scanf("%d", &n);//�������� ����
	vector<int> arr(n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}//for-i
	
	//������ ������ 20�� ������!!!!!!!!!! 
	long long cnt=0;
	long long b, c; scanf("%d %d", &b, &c); // �Ѱ�����, �ΰ����� 
	for(int i=0; i<n; i++){
		arr[i]-=b;
		cnt++;
		if(arr[i]>0){//����!!!!!!!!!!!!!!!!!!!!!!!! 
			if(arr[i]%c==0){
				cnt+=(arr[i]/c);
			}else{
				cnt+=(arr[i]/c)+1;				
			}//if
		}//if
	}//for-i
	
	printf("%lld\n", cnt);
	
	return 0;
}//main

#include<iostream>
using namespace std;
int cam[110][110];
int n, s; //������ġ, ���� �ð� 

int main(){
	
	scanf("%d %d", &n, &s);
	for(int i=0; i<n; i++){
		scanf("%d %d", &cam[i][0], &cam[i][1]);
	}//for-i
	
//	for(int i=0; i<n; i++){
//		printf("%d %d\n", cam[i][0], cam[i][1]);
//	}//for-i
		
	int cnt=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int d=(cam[j][0]-cam[i][0])/(cam[j][1]-cam[i][1]);
			printf(" %d ~ %d :: %d \n", i, j, d);
			if(d>s){
				cnt++;
			}
		}
	}//for-i
	printf("%d", cnt);
	
	return 0;
}//main





//	for(int i=0; i<n; i++){
//		printf("%d %d\n", cam[i][0], cam[i][1]);
//	}//for-i


// n(ī�޶��� ��), s(���Ѽӵ�)
// x ī�޶��� ��ġ, t �ش�ī�޶� ������ �ð� 


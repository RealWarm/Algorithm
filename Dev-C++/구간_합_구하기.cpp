#include<iostream> 
using namespace std;
int arr[1000010];
int inx[1000010];
int n, m, k;//배열의 길이, 변경횟수, 구간 합을 구하는 횟수 

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
		// a가 1이면 b번째 인덱스를 c로 바꾼다.
		// a가 2이면 b번째 수부터 c번째 수까지의 합을 구하여 출력한다. 
		int a, b, c; scanf(" %d %d %d", &a, &b, &c);
		if(a==1){
			arr[b]=arr[b]-inx[b]+c;
		}else if(a==2){
			printf("%d\n", arr[c]-arr[b-1]);
		}//if
		
	}//for-i	 
	
	return 0;
}//main

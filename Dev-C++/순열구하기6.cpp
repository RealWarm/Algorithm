#include<iostream> 
using namespace std;
char result[15];
int check[15];
int n, r;

void getResult(int x){
	//���� x��° for���̰�, r�� for���� �ʿ��ϴ�.	 
	if(x>=r){
		printf("%s\n", result);		
	}else{
		for(int k=0; k<n; k++){
			if(check[k]==0){
				check[k]=1;
				char ch=k+'a';
				result[x]=ch;
				getResult(x+1);
				check[k]=0;
				result[x]=0;
			}
		}
	}
}//getResult

int main(){
	scanf("%d %d", &n, &r);
	getResult(0);
	return 0;
}//main

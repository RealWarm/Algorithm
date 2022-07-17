#include<iostream> 
using namespace std;
int pp[20];
int ch[20];
int n, k, t;
int flag, cnt, sum;

void get(int x){
	//pp[x]를 정한 뒤에 pp[x+1]을 정한다. 
	if(flag==1) return;

	if(x==k){
		cnt++;
		if(cnt==t){
			for(int i=0; i<k; i++){				
				sum+=pp[ch[i]];
			}//for-i
			printf("%d\n", sum);
			flag=1;		
		}//if-2
	}else{
		for(int i=0; i<n; i++){
			if(x==0 || ch[x-1]<i){
				ch[x]=i;
				get(x+1);
			}//if-2
		}//for-i
	}//if-1
}//get

int main(){
	scanf("%d %d %d", &n, &k, &t);
	for(int i=0; i<n; i++){
		scanf("%d", &pp[i]);
	}//for-i
	get(0);
	return 0;
}//main

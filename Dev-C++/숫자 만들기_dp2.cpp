#include<iostream> 
#include<cstring>
using namespace std;
typedef long long ll;
ll mem[100010];
int n, m=3; 

int main(){
	
	int t; scanf("%d", &t);	

	for(int i=0; i<t; i++){
		memset(mem, 0, sizeof(mem));
		scanf("%d", &n);
		mem[1]=1;
		int sum=0;
		for(int i=2; i<=m; i++){
			sum+=mem[i-1];
			mem[i]=sum+1;
		}//for-i
		
		for(int i=m+1; i<=n; i++){
			for(int a=i-m; a<=i-1; a++){
				mem[i]+=mem[a]%1000007;
			}//for-a
		}//for-i
		printf("%d \n", mem[n]);
	}
	
	return 0;
}//main

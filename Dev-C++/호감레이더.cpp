#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,k;
int grp[21][21];
int range[21];

void rcount(int x, int y){	
	// x, y를 기준으로 범위내의 사람수를 세서 range 배열에 저장한다. 
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){			
			if(grp[i][j]==1){
				int dis= abs(x-i) + abs(y-j);
				range[dis]++;
			}//if		
		}//for-j
	}//for-i	
}//rcount

int main(){
	
	int ts; scanf("%d", &ts);	
	for(int tt=1; tt<=ts; tt++){
		scanf("%d %d %d", &n, &m, &k);
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				scanf("%d", &grp[i][j]);
		
		int max=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(grp[i][j]!=1){
					memset(range, 0, sizeof(range));
					rcount(i, j);
					for(int a=1; a<=(m+n-2); a++){
						int sum=0;
						for(int b=1; b<=a; b++){
							sum+=range[a+1-b]*b;
						}//for-b
						if(sum<=k){
							int temp=0;
							for(int c=1; c<=a; c++){
								temp+=range[c];
							}//for-c
							if(temp>=max){
								max=temp;
							}//if-2					
						}//if-1
					}//for-a
				}//if-0							
			}//for-j
		}//for-i
		printf("#%d %d\n", tt, max);
	}//for-tt	
	
	return 0;
}//main

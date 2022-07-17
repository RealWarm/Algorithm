#include<iostream>
#include<cstring>
using namespace std;
int grp[30][30];//원본 
int tmp[30][30];//
int n, m, mmax;//세로, 가로 

int main(){
	
	scanf("%d %d", &m, &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}
	}
	
	for(int i=0; i<m; i++){// 세로줄 정하고 
		int cnt=0;		
		for(int j=n-1; j>=0; j--){
			if(grp[j][i]==0){
				cnt++;
			}else{
				break;
			}
		}//for-j
		
		if(cnt>=3){			
			memcpy(tmp, grp, sizeof(tmp));
			for(int a=n-cnt; a<n-cnt+4; a++){ 
				tmp[a][i]=1;
			}
			
			int num=0;
			for(int a=0; a<n ; a++){ //세로 
				int lcnt=0;
				for(int b=0; b<m; b++){
					if(grp[a][b]==1) lcnt++;
				}//for-b				
				if(lcnt==m) num++;
			}//for-a
			
			if(num>mmax) mmax=num;
		}//if
	}//for-i
	
	printf("%d", mmax);
	
	return 0;
}//main

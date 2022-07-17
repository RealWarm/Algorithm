#include<iostream> 
#include<cstring>
using namespace std;
int grp[110][110];
int wei[110][110];
int ch[110];

int main(){
	
	int t; scanf("%d", &t);	
	for(int tt=1; tt<=t; tt++){
		memset(wei, 0, sizeof(wei));
		memset(ch, 0, sizeof(ch));
		int n, k, total=0; scanf("%d %d", &n, &k);	
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &grp[i][j]);
			}//for-j
		}//for-i
		//////////////////////////////////////////////////////
		//세로 차이맵 만들기. 
		for(int i=0; i<n; i++){
			for(int j=1; j<n; j++){
				wei[j][i]=grp[j-1][i]-grp[j][i];
			}//for-j
		}//for-i				
		//내리막 구해보기 
		for(int i=0; i<n; i++){
			int cnt=0;		
			for(int j=1; j<n; j++){
				if(wei[j][i]>=2){
					cnt++;				
				}else{
					cnt=0;
				}				
				if(cnt==k-1){				
					total++;
					ch[i]=1;//능선이 있는 곳은 더 탐색 안하겠다. 
					break;
				}				
			}//for-j			
		}//for-i		
		//오르막 구해보기 
		for(int i=0; i<n; i++){		
			int cnt=0;
			if(ch[i]==1) continue;
			for(int j=1; j<n; j++){
				if(wei[j][i]<=-2){
					cnt++;				
				}else{
					cnt=0;
				}				
				if(cnt==k-1){				
					total++;
					break;
				}
			}//for-j			
		}//for-i
		//////////////////////////////////////////////////////
		//////////////////////////////////////////////////////
		memset(wei, 0, sizeof(wei));
		memset(ch, 0, sizeof(ch));
		//가로 차이맵 만들기. 
		for(int i=0; i<n; i++){
			for(int j=1; j<n; j++){
				wei[i][j]=grp[i][j-1]-grp[i][j];
			}//for-j
		}//for-i			
		//내리막 구해보기 
		for(int i=0; i<n; i++){
			int cnt=0;
			for(int j=1; j<n; j++){
				if(wei[i][j]>=2){
					cnt++;				
				}else{
					cnt=0;
				}				
				if(cnt==k-1){
					total++;
					ch[i]=1;
					break;
				}
			}//for-j			
		}//for-i
		//오르막 구해보기 
		for(int i=0; i<n; i++){
			int cnt=0;
			if(ch[i]==1) continue;
			for(int j=1; j<n; j++){
				if(wei[i][j]<=-2){
					cnt++;				
				}else{
					cnt=0;
				}				
				if(cnt==k-1){				
					total++;
					break;
				}
			}//for-j			
		}//for-i
		printf("#%d %d\n", tt, total);
	}//for-tt
	
	return 0;
}//main

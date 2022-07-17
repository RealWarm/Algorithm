#include<iostream>
#include<cstring>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[22][22];
int ch[101];

int main(){
	
	int ts; cin >>ts;
	for(int t=1; t<=ts; t++){
		int n; cin >> n;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%d", &grp[i][j]);
				
		int max=0;
		for(int i=1; i<=n-2; i++){
			for(int j=1; j<=n-2; j++){
				memset(ch,0,sizeof(ch));
				int sum=grp[i][j];
				ch[grp[i][j]]=1;			
				for(int k=0; k<4; k++){				
					int ntx=i;
					int nty=j;
					while(1){
						ntx+=dx[k];
						nty+=dy[k];
						if(ntx<0 || ntx>=n || nty<0 || nty>=n) break;
						if(ch[grp[ntx][nty]]==0){
							sum+=grp[ntx][nty];
							ch[grp[ntx][nty]]=1;
						}
					}//while
				}//for-k
//				printf("***%d \n", sum);
				if(sum>max){
					max=sum;
				}
			}//for-j
		}//for-i
		
		printf("#%d %d\n", t, max);

	}//for-ts
	return 0;
}//main

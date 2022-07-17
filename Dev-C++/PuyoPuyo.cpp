#include<iostream> 
#include<cstring>
#include<vector>
#include<string>
using namespace std;
vector<string> grp(12);
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int wei[12][6];
int flag;

void dfs(int x, int y, int cc, int cnt, char pp){
	wei[x][y]=cc;
	if(cnt==4){		
		flag=1;
	}	
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || nty<0 || ntx>=12 || nty>=6) continue;
		if(grp[ntx][nty]==pp && wei[ntx][nty]==0){
			dfs(ntx, nty, cc, cnt+1, pp);
		}//if
	}//for-k	
	if(flag==1){		
		grp[x][y]='.';	
	}
	
}//dfs

int main(){
	for(int i=0; i<12; i++){
		cin >> grp[i];
	}//for-i
	//////////////////////////////////
//	while(1){
		// 터칠수 있는 뿌요탐색하기. 
		int clr=0;
		for(int i=0; i<12; i++){
			for(int j=0; j<6; j++){
				if(grp[i][j]!='.' && wei[i][j]==0){
					flag=0;
					dfs(i, j, ++clr, 1, grp[i][j]);
				}//if
			}//for-j
		}//for-i
		//////////////////////////////////////////////
		// 빈공간을 뿌요로 채우기.
		
		//////////////////////////////////////////////
		// 빈공간을 뿌요로 채우기.
	
		
		
//	}//while
	
	return 0;
}//main


// 입력 >> 


// 설계
// 위에서부터 >> 뿌요 잡고 터뜨릴수 있는지



#include<iostream> 
using namespace std;
int grp[510][510];
int tet[19][4][2]={
	{{0,0}, {0,1},{1,0},{1,1}}, //네모 
	
	{{0,0},{0,1},{0,2},{0,3}},//긴거 세운거 
	{{0,0},{1,0},{2,0},{3,0}},//긴거 눕힌거 
	
	{{0,0},{-2,0},{-1,0},{0,1}},//ㄴ 1번 
	{{0,0},{0,1},{0,2},{1,0}},//ㄴ 2번 
	{{0,0},{0,-1},{1,0},{2,0}},//ㄴ 3번 
	{{0,0},{-1,0},{0,-1},{0,-2}},//ㄴ 4번 실 
	
	{{0,0},{-2,0},{-1,0},{0,-1}},//ㄴ 4번 
	{{0,0},{-1,0},{0,1},{0,2}},//ㄴ 4번 
	{{0,0},{0,-2},{0,-1},{1,0}},//ㄴ 4번 
	{{0,0},{0,1},{1,0},{2,0}},//ㄴ 4번 
	
	{{0,0},{-1,0},{0,1},{1,1}},//n 1번 수 
	{{0,0},{0,-1},{-1,0},{-1,1}},//n 2번 
	
	{{0,0},{-1,0},{0,-1},{1,-1}},//
	{{0,0},{0,-1},{1,0},{1,1}},//
	
	{{0,0},{-1,0},{0,-1},{0,1}},//ㅗ 1번 
	{{0,0},{-1,0},{0,1},{1,0}},//ㅗ 2번 
	{{0,0},{0,-1},{0,1},{1,0}},//ㅗ 3번 
	{{0,0},{-1,0},{1,0},{0,-1}}//ㅗ4번 실수!!!!!!!!!!!! 
};//tet 
int n, m, mmax=-987987; // 세로, 가로, 최댓값

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %d", &grp[i][j]);
		}//for-j
	}//for-i
	////////////////////////////////////////////////
	for(int tt=0; tt<19; tt++){//테트로미노 선택하기
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				int flag=0;
				int sum=0;
				//좌표를 정한다 >> 정해진 좌표에서 
				//범위를 넘어가는지 아닌지세기 
				for(int k=0; k<4; k++){
					int ntx=i+tet[tt][k][0];
					int nty=j+tet[tt][k][1];
					if(ntx<0 || nty<0 || ntx>=n || nty>=m){		
										//여기 실수!!!!!		
						flag=1;	
						break;
					}else{
						sum+=grp[ntx][nty];
					}//if					
				}//for-k	
				
				if(flag==0 && mmax<sum){
					mmax=sum;
				}//if
			}//for-j
		}//for-i		
	}//for-tt
	
	printf("%d\n", mmax);
	
	return 0;
}//main












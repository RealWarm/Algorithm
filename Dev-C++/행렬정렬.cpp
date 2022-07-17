#include<iostream>
#include<cstring>
using namespace std;
int n, m, r, c, k;
int rmax=0, cmax=0;
int grp[110][110];
int trp[110][110];

int compare(int ttt[110][110]){
	printf("compare invoked!!\n");
	//행의 길이가 크면 1반환 >> 행정렬 
	//열의 길이가 크면 0반환 >> 열정렬 
	rmax=0, cmax=0;
	for(int i=0; i<110; i++){
		//행의 길이 >> 세로길이 
		if(ttt[i][0]==0){
			break;		
		}//if 
		cmax++;
	}//for-i
	
	for(int i=0; i<110; i++){
		//열의 길이 >> 가로길이 
		if(ttt[0][i]==0){
			break;		
		}//if 
		rmax++;
	}//for-i
	
	if(cmax>=rmax){
		//세로길이가 길면 >> 행정 
		return 0;
	}else{
		return 1;
	}//if
	
}//main

int ssort(int nn){
	printf("ssort invoked!!\n");
	memset(trp, 0, sizeof(trp));
	
	if(nn==1){
		//행정렬 
			
	}else if(nn=0){
		printf(" ++++++++++ nn == 0 \n");
		//열정렬
		
		// | | 방향으로 계수정열을 한다. 
		for(int a=0; a<rmax; a++){
			//해당 열을 잡고 
			for(int b=0; b<cmax; b++){
				//계수 정렬 시작 
				trp[a][grp[b][a]]++;
			}//for-b
		}//for-a
		
//		for(int a=0; a<cmax; a++){
//			int min=999, minx=0;
//			for(int b=0; b<111; b++){
//				if(trp[a][b]>0 && min>trp[a][b]){
//					min=trp[a][b];
//					minx=b;
//				}
//			}//for-b					
//		}//for-a
		
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				printf("%d ", trp[i][j]);
			}
			printf("\n");
		}
		return 1;
	}//if
	
}//ssort


int main(){
	
//	memset(grp, -1, sizeof(grp));
	scanf("%d %d %d %d %d", &n, &m, &r, &c, &k);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
		}//for-j
	}//for-i		
	
	while(1){
		if(ssort(compare(grp))==1){
			break;
		}
	}//while
	
	return 0;
}//main

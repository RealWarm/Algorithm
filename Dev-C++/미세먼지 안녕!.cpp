#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int grp[60][60];
int tmp[60][60];
int wei[60][60];
int r, c, t; // 세로 가로, 경과시간
vector<pair<int, int>> v1;

void spread(){	
	memset(tmp, 0, sizeof(tmp));	
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(grp[i][j]==-1){
				tmp[i][j]=-1;
			}else if(grp[i][j]>=1){
				int snum=0; //퍼진 칸의수
				for(int k=0; k<4; k++){
					int ntx=i+dx[k];
					int nty=j+dy[k];
					if(ntx<0 || nty<0 || ntx>=r || nty>=c) continue;				
					if(tmp[ntx][nty]>=0){//안해도됨 
//						printf("/5 ::%d\n",grp[ntx][nty]/5);
						tmp[ntx][nty]+=(grp[i][j]/5);
						snum++;
					}//if 					
				}//for-k				
				tmp[i][j]+=grp[i][j]-((grp[i][j]/5)*snum);
			}//if
		}//for-j
	}//for-i
	memcpy(grp, tmp, sizeof(tmp));	
}//spread

void circul(int n, int m){// 청정기의 위, 아래 좌표 
	memcpy(tmp, grp, sizeof(tmp));
	// 위에 반시계 방향 
	for(int j=0; j<=c-2; j++){
		if(grp[n][j]==-1){
			tmp[n][j+1]=0;	
		}else{
			tmp[n][j+1]=grp[n][j];
		}		
	}//for-i
	for(int j=n; j>=1; j--){
		tmp[j-1][c-1]=grp[j][c-1];
	}//for-i
	for(int j=c-1; j>=1; j--){
		tmp[0][j-1]=grp[0][j];
	}//for-j
	for(int i=0; i<n-1; i++){
		tmp[i+1][0]=grp[i][0];
	}//for-i
	////////////////////////////////
	//아래 반시계 
//	for(int j=m; j<=r-2; j++){
//		if(grp[j][0]==-1){
//			tmp[j+1][0]=0;	
//		}else{
//			tmp[j+1][0]=grp[j][0];
//		}//if		
//	}//for-j
//	for(int j=0; j<=c-2; j++){
//		tmp[r-1][j+1]=grp[r-1][j];
//	}//for-j
//	for(int j=r-1; j>=m+1; j--){
//		tmp[j-1][c-1]=grp[j][c-1];
//	}//for-j
//	for(int j=c-1; j>=2; j--){
//		tmp[m][j-1]=grp[m][j];
//	}//for-j
	////////////////////////////////
	//아래 시계방향
	for(int i=0; i<=c-2; i++){
		if(grp[m][i]==-1) tmp[m][i+1]=0;
		else tmp[m][i+1]=grp[m][i];
	}//for-i
	
	for(int i=m; i<=r-2; i++){
		tmp[i+1][c-1]=grp[i][c-1];
	}//for-i
	
	for(int i=c-1; i>=1; i--){
		tmp[r-1][i-1]=grp[r-1][i];
	}//for-i
	
	for(int i=r-1; i>=m+2; i--){
		tmp[i-1][0]=grp[i][0];
	}//for-i
	
	////////////////////////////////
	memcpy(grp, tmp, sizeof(tmp));
	////////////////////////////////
}//circul

int main(){
	scanf("%d %d %d", &r, &c, &t);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			scanf("%d", &grp[i][j]);
			if(grp[i][j]==-1){
				v1.push_back(make_pair(i,j));
			}//if
		}//for-j
	}//for-i
	//////////////////////////////////////
	for(int a=1; a<=t; a++){
		spread();
//		printf("----------------------\n");
		circul(v1[0].first, v1[1].first);
//		for(int i=0; i<r; i++){
//			for(int j=0; j<c; j++){
//				printf("%2d ", grp[i][j]);
//			}//for-j
//			printf("\n");
//		}//for-i
	}//for-a
	///////////////////////////////////////
	int sum=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(grp[i][j]!=-1){
				sum+=grp[i][j];
			}//if
		}//for-j
	}//for-i
	printf("%d\n", sum);
//	spread();
//	circul(v1[0].first, v1[1].first);
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			printf("%2d ", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i

	return 0;	
}//main

// 청정기는 항상 1번열에 설치 && 크기는 두 행을 차지
// 확산되는 양은 Ar,c/5 이다.
// 남은 양은  Ar,c - (Ar,c/5)×(확산된 방향의 개수)  
















//	printf("--------------------------\n");
//	
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			printf("%2d ", grp[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
 

#include<iostream>
#include<cmath>
using namespace std;
int grp[30][30];
int n, dis, mnum; 	// 너비, 총이동거리, 적의 숫자. 
int ldis, inx, iny;	// 임시길의 최소값, 최소값의 좌표 

typedef struct pp{
	int lv=2;
	int exp=0;
	int x, y;
};

pp p1;

int cal(int x1, int y1){
	int temp=(abs(x1-p1.x)+abs(y1-p1.y));
	if(ldis > temp){
		ldis=temp;
		inx = x1;
		iny = y1;
	}//if
	
	return temp;
}//cal

void calDis(int x1, int y1){	
	//거리를 계산하여 총거리량에 더하고
	//p1의 좌표를 적의 좌표로 바꾼다. 
	dis+=(abs(x1-p1.x)+abs(y1-p1.y));
	mnum--;
	grp[x1][y1]=0;
	p1.x=x1;
	p1.y=y1;
	p1.exp++;
	if(p1.lv==p1.exp){
		p1.exp=0;
		p1.lv++;
	}//if
	
	printf("좌표: (%d, %d), 거리 : %d\n", p1.x, p1.y, dis);
}//calDis

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &grp[i][j]);
			if(grp[i][j]<=8 && grp[i][j]>=1){
//				mnum++;//적의 숫자. 
			}else if(grp[i][j]==9){
				//낙하지점이라면 				
				p1.x=i;
				p1.y=j;				
			}//if 
		}//for-j
	}//for-i	
		
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j]<=8 && grp[i][j]>=1){
				printf("%d ", cal(i, j));
			}else if(grp[i][j]==9){
				printf("* ");
			}else{
				printf("0 ");
			}
		}//for-j
		printf("\n");
	}//for-i
	
	return 0;
}//main

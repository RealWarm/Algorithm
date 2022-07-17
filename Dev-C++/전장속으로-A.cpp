#include<iostream>
#include<cmath>
using namespace std;
int grp[30][30];
int n, dis, mnum;
typedef struct pp{
	int lv=2;
	int exp=0;
	int x, y;
};
pp p1;

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
				mnum++;//적의 숫자. 
			}else if(grp[i][j]==9){
				//낙하지점이라면 
				grp[i][j]=0;
				p1.x=i;
				p1.y=j;				
			}//if 
		}//for-j
	}//for-i
	printf("좌표: (%d, %d)\n", p1.x, p1.y);
	
	while(1){
		int flag=0;
		if(mnum==0)	break;
		for(int i=0; i<n; i++){
			if(flag==1) break;
			for(int j=0; j<n; j++){
				if(grp[i][j]>=1 && p1.lv>grp[i][j]){
					//해당적이 나의 레벨보다 낮다면 
					calDis(i,j);					
					flag=1;
					break;
				}//if
			}//for-j
		}//for-i
	}//while 
	
	printf("%d\n", dis);
	return 0;
}//main





















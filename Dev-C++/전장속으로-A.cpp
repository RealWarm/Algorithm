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
	//�Ÿ��� ����Ͽ� �ѰŸ����� ���ϰ�
	//p1�� ��ǥ�� ���� ��ǥ�� �ٲ۴�. 
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
	
	printf("��ǥ: (%d, %d), �Ÿ� : %d\n", p1.x, p1.y, dis);
}//calDis

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &grp[i][j]);
			if(grp[i][j]<=8 && grp[i][j]>=1){
				mnum++;//���� ����. 
			}else if(grp[i][j]==9){
				//���������̶�� 
				grp[i][j]=0;
				p1.x=i;
				p1.y=j;				
			}//if 
		}//for-j
	}//for-i
	printf("��ǥ: (%d, %d)\n", p1.x, p1.y);
	
	while(1){
		int flag=0;
		if(mnum==0)	break;
		for(int i=0; i<n; i++){
			if(flag==1) break;
			for(int j=0; j<n; j++){
				if(grp[i][j]>=1 && p1.lv>grp[i][j]){
					//�ش����� ���� �������� ���ٸ� 
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





















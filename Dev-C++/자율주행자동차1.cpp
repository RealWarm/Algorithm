#include<iostream> 
#include<cstring>
#include<vector>
using namespace std;
struct Car{
	float x; 
	float y;
	int r;  	// �ٶ󺸴� ����
	int st=0; 	// �浹�� �ð� 
};//Car
float dx[]={0.5, -0.5,   0,  0}; // ��ǥ���� ��(��)��(��) + �̴�!!! 
float dy[]={   0,   0,-0.5,0.5}; // �� �� �� �� 
vector<Car> c1;
int s; 				// �ڵ����� ���� 
int remain, col;	// ���� �ڵ�����, �浹�� �ڵ�����

Car make_p(float x, float y, int r){
	Car c;
	c.x=x;	// ���� 
	c.y=y;	// ���� 
	c.r=r;	// ���� 
	return c;
}//make_p

void go(){	
	for(int i=0; i<c1.size(); i++){
		if(c1[i].st!=0){
			// �浹�� �ڵ����� ������ ��Ű�� �ʴ´�. 
			continue;
		}else if(c1[i].st==0){
			// �浹���� �ڵ����� �ٶ󺸴� �������� 0.5��ū ������Ų��.
			int dd=c1[i].r;
			c1[i].x+=dx[dd];
			c1[i].y+=dy[dd];
		}//if
		
		//�ڵ����� ������ �Ѿ��ٸ� 
		if(c1[i].x>1000.0 || c1[i].x<-1000.0 ||
			c1[i].y>1000.0 || c1[i].y<-1000.0){
				remain--; 
				c1[i].st=-2;
//				printf("+ %d ��°(%f, %f)���� ����\n", i, c1[i].x, c1[i].y);
		}//if
	}//for-i
}//go

void check(int time){
//	printf("check invoked!!\n");
	for(int i=0; i<c1.size(); i++){
//		printf("inhere1\n");
		if(c1[i].st!=0){
			// �浹�� �����̶�� 
			// ������ �ʴ´�. 
			continue;
		}//if
		for(int j=i+1; j<c1.size(); j++){
//			printf("inhere2\n");
//			printf("(%f, %f) (%f, %f)\n", 
//					c1[i].x, c1[i].y, c1[j].x, c1[j].y);
			if(c1[j].st!=0) continue;
			
			if(c1[i].x==c1[j].x && c1[i].y==c1[j].y){
//				printf("inhere3\n");	
				//�浹�� �ߴٸ�
				if(c1[i].st==0){
					c1[i].st=time;
					remain--;
					col++;
//					printf("collison!!\n");
				}//if
				
				c1[j].st=time;
				remain--;
//				col++;				
			}//if
		}//for-j
	}//for-i	
}//check

int main(){
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		c1.clear();
		col=0;		
		scanf("%d", &s);
		for(int i=0; i<s; i++){
			float x, y; 
			int r; 
			scanf("%f %f %d", &y, &x, &r);// ���� �ȹٷ� ����!!!!!!!!!!!!!!!! 
			c1.push_back(make_p(x, y, r));
		}//for-i
		remain=c1.size(); 
		/////////////////////////////////////////////////	
		for(int i=1; ; i++){	
	//		printf("�ð�:: %d || ���� ���� :: %d \n", i, remain);			
			if(remain==0) break;
			if(i==3000) break;
			go();
			check(i);		
		}//for-i
		
		printf("#%d %d\n", tt, col);	
	}//for-tt
	
	return 0;
}//main

//for(int i=0; i<s; i++){
//	printf("%f %f %d\n", c1[i].x, c1[i].y, c1[i].r);		
//}//for-i

// �浹�� �ð� �ֱ�. 
// �Է� 
// S :: �ڵ����� ����
// X, Y, R(����ٶ󺸴� ����)
// R :: �� �� �� ��{0, 1, 2, 3} 

// ���
// �� �׽�Ʈ ���̽��� ���� �ڵ����� ��� ����������� 
// �ڵ������� �浹 Ƚ���� ����Ѵ�. 

// ���� 
// ���� �ε��� �ڵ����� �ִ�? 
// 0.5�� �ڿ� �ε��� �ڵ����� �ִ�? 
// ���� �ִ�? 
//////////////////////////////////////////////////////////////////////////
// �ùķ������� ��ǥ����� ũ��� 2000 * 2000 ���� �����Ǿ��ִ�. 
// x, y ��ǥ�� �ִ񰪰� �ּڰ��� ���� 1000, -1000���� �����Ǿ���
// �浹�ϰų� �ʹٱ����� ����� �ڵ����� �������.

// 1�� �������� �ε����� ���
// 0.5�� �ڿ� �ε��� ��� 

// 0.5�� ���� >> �ε�����? >> 0.5�� ���� >> �ε�����? 

// go >> check
// go >> ��� �ڵ����� 0.5��ŭ ������Ų��.
// check >> ���� �ڵ����� �浹 �ߴٸ� >> �浹�� �ڵ����� ���� ���� 
// >> �ڵ����� ���¿� �浹�� �ð��� ���´�. 










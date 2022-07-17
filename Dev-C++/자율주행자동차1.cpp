#include<iostream> 
#include<cstring>
#include<vector>
using namespace std;
struct Car{
	float x; 
	float y;
	int r;  	// 바라보는 방향
	int st=0; 	// 충돌한 시간 
};//Car
float dx[]={0.5, -0.5,   0,  0}; // 좌표에서 상(위)은(는) + 이다!!! 
float dy[]={   0,   0,-0.5,0.5}; // 상 하 좌 우 
vector<Car> c1;
int s; 				// 자동차의 갯수 
int remain, col;	// 남은 자동차수, 충돌한 자동차수

Car make_p(float x, float y, int r){
	Car c;
	c.x=x;	// 세로 
	c.y=y;	// 가로 
	c.r=r;	// 방향 
	return c;
}//make_p

void go(){	
	for(int i=0; i<c1.size(); i++){
		if(c1[i].st!=0){
			// 충돌한 자동차는 전진을 시키지 않는다. 
			continue;
		}else if(c1[i].st==0){
			// 충돌안한 자동차를 바라보는 방향으로 0.5만큰 전진시킨다.
			int dd=c1[i].r;
			c1[i].x+=dx[dd];
			c1[i].y+=dy[dd];
		}//if
		
		//자동차가 범위를 넘었다면 
		if(c1[i].x>1000.0 || c1[i].x<-1000.0 ||
			c1[i].y>1000.0 || c1[i].y<-1000.0){
				remain--; 
				c1[i].st=-2;
//				printf("+ %d 번째(%f, %f)에서 나감\n", i, c1[i].x, c1[i].y);
		}//if
	}//for-i
}//go

void check(int time){
//	printf("check invoked!!\n");
	for(int i=0; i<c1.size(); i++){
//		printf("inhere1\n");
		if(c1[i].st!=0){
			// 충돌한 차량이라면 
			// 비교하지 않는다. 
			continue;
		}//if
		for(int j=i+1; j<c1.size(); j++){
//			printf("inhere2\n");
//			printf("(%f, %f) (%f, %f)\n", 
//					c1[i].x, c1[i].y, c1[j].x, c1[j].y);
			if(c1[j].st!=0) continue;
			
			if(c1[i].x==c1[j].x && c1[i].y==c1[j].y){
//				printf("inhere3\n");	
				//충돌을 했다면
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
			scanf("%f %f %d", &y, &x, &r);// 문제 똑바로 읽자!!!!!!!!!!!!!!!! 
			c1.push_back(make_p(x, y, r));
		}//for-i
		remain=c1.size(); 
		/////////////////////////////////////////////////	
		for(int i=1; ; i++){	
	//		printf("시간:: %d || 남은 차수 :: %d \n", i, remain);			
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

// 충돌별 시간 넣기. 
// 입력 
// S :: 자동차의 갯수
// X, Y, R(현재바라보는 방향)
// R :: 상 하 좌 우{0, 1, 2, 3} 

// 출력
// 각 테스트 케이스에 대해 자동차가 모두 사라질때까지 
// 자동차끼리 충돌 횟수를 출력한다. 

// 설계 
// 현재 부딪힌 자동차가 있니? 
// 0.5초 뒤에 부딪힐 자동차가 있니? 
// 차가 있니? 
//////////////////////////////////////////////////////////////////////////
// 시뮬레이터의 좌표평면의 크기는 2000 * 2000 으로 고정되어있다. 
// x, y 좌표의 최댓값과 최솟값은 각각 1000, -1000으로 설정되었다
// 충돌하거나 맵바깥으로 벗어나면 자동차는 사라진다.

// 1초 지났을때 부딪히는 경우
// 0.5초 뒤에 부딪힌 경우 

// 0.5초 전진 >> 부딪혔니? >> 0.5초 전진 >> 부딪혔니? 

// go >> check
// go >> 모든 자동차를 0.5만큼 전진시킨다.
// check >> 지금 자동차가 충돌 했다면 >> 충돌한 자동차의 수를 센다 
// >> 자동차의 상태에 충돌한 시간을 적는다. 










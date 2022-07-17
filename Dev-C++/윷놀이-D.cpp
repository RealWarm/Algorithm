#include<iostream>
using namespace std;
int grp[50]	={0, 5, 10, 15, 20,
			  50, 30, 35, 40, 45,
			  100, 55, 60, 65, 70,
			  75, 80, 85, 90, 95,
			  500, 1000,   275, 250, 300, // 0~21, 22~30
			  150, 175, 150, 125, 350, 
			  400
			 };
int grp2[][6]={{ 5, 22, 23, 24, 25, 26}, // 인덱스, 5가지 진행경로 
			   {10, 27, 28, 24, 29, 30},
			   {22, 23, 24, 25, 26, 15},
			   {23, 24, 25, 26, 15, 16},
			   {24, 29, 30, 20, 21, 21},
			   {25, 26, 15, 16, 17, 18},
			   {26, 15, 16, 17, 18, 19},
			   {27, 28, 24, 29, 30, 20},
			   {28, 24, 29, 30, 20, 21},
			   {29, 30, 20, 21, 21, 21},
			   {30, 20, 21, 21, 21, 21} //10
			  };
int ans[15]; // 전진할 칸의 수 
int npc[15]; // 전진할 말들의 순서. 
int pc[5];	 // 말들의 위치를 저장한다. 1~4
int num, flag, total;// 이동횟수 

void forward(int inx, int anss){
	// 해당말의 위치가 끝점이 아니라면
	// 
	//해당말(inx)를 anss만큼 전진시킨다. 
	if(pc[inx]==21) return;
	if(pc[inx]==5 || pc[inx]==10 || (pc[inx]>=22 && pc[inx]<=30)){
		for(int w=0; w<=10; w++){
			if(grp2[w][0]==pc[inx]){
				pc[inx]=grp2[w][anss];
				break;
			}//if-2
		}//for-w
	}else{
		pc[inx]+=anss;
		if(pc[inx]>=21) pc[inx]=21;
	}
	
//	for(int i=1; i<=3; i++){
//		if(flag==1) break;
//		if(pc[i]==0) continue;
//		if(pc[i]==21) continue;
//		for(int j=i+1; j<=4; j++){
//			if(pc[j]==0) continue;
//			if(pc[i]==pc[j]){				
//				flag=1;
//				break;
//			}//if
//		}//for-j
//	}//for-i
	
}//foward

int main(){
	
	scanf("%d", &num); // 이동횟수 입력 
	for(int i=0; i<num; i++){
		scanf("%d", &ans[i]); // 이동하게 되는 칸의 수 
	}//for-i
	for(int i=0; i<num; i++){
		scanf("%d", &npc[i]); // 전진할 말의 순서 
	}//for-i
		
	for(int a=0; a<num; a++){	
		if(flag==1) break;
		forward(npc[a], ans[a]); // 움직일 말을 정한다 >> 움직인다. 							
	}//for-a
	
//	if(flag==1){
//		printf("-1\n");				
//	}else{		 
//		for(int i=1; i<=4; i++){
//			total+=grp[pc[i]];
//		}//for-i
//		printf("%d", total);
//	}//if
//	
	for(int a=1; a<=4; a++){	
		printf("%d ", pc[a]);
	}//for-a
	printf("\n");
	for(int i=1; i<=4; i++){		
		total+=grp[pc[i]];
	}//for-i
	printf("%d", total);
	 	
	return 0;
}//main

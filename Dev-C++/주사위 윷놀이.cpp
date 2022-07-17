#include<iostream> 
#include<cstring>
using namespace std;
int grp[100]={ 0, 2, 4, 6, 8,
			  10,12,14,16,18,
			  20,22,24,26,28,
			  30,32,34,36,38,
			  40,13,16,19,25,
			  26,27,28,22,24,
			  30,35};
int grp2[][6]={  { 5, 22, 23, 24, 25, 31},
				 {10, 29, 30, 25, 31, 32},
				 {15, 28, 27, 26, 25, 31},
				 {22, 23, 24, 25, 31, 32},
				 {23, 24, 25, 31, 32, 20},
				 {24, 25, 31, 32, 20, 21},
				 {25, 31, 32, 20, 21, 21},
				 {26, 25, 31, 32, 20, 21},
				 {27, 26, 25, 31, 32, 20},
				 {28, 27, 26, 25, 31, 32},
				 {29, 30, 25, 31, 32, 20},
				 {30, 25, 31, 32, 20, 21},
				 {31, 32, 20, 21, 21, 21},
				 {32, 20, 21, 21, 21, 21}
				};
int turn[20];	// 주사위에서 나온 숫자들을 저장한다.
int pnum[20];	// 말들의 순서들을 정한다.
int pic[10];		//말들의 위치를 저장한다. 
int r=10;
int mmax=-987987987;

void go(int num, int dis){
	if(pic[num]==21) return;
	//num번의 말을 dis만큼 전진시킨다.
	
	if(pic[num]==5){
		pic[num]=grp2[0][dis];
		
	}else if(pic[num]==10){
		pic[num]=grp2[1][dis];
		
	}else if(pic[num]==15){
		pic[num]=grp2[2][dis];
		
	}else if(pic[num]>=22 && pic[num]<=32){
		for(int i=3; i<14; i++){
			if(pic[num]==grp2[i][0]){
				pic[num]=grp2[i][dis];
				break;
			}//if
		}//for-i
	}else{
		pic[num]+=dis;
		if(pic[num]>21) 
			pic[num]=21;
	}//if
	 
}//go

void get(int x){
	
	if(x>=r){		
		int total=0;
		memset(pic, 0, sizeof(pic));
		for(int i=0; i<10; i++){
			go(pnum[i], turn[i]);
		}//for-i
		
		for(int i=0; i<4; i++){
			total+=grp[pic[i]];
		}//for-i
		
		if(total>mmax){
			mmax=total;
		}//if
		
	}else{
		for(int i=0; i<5; i++){
			pnum[x]=i;
			get(x+1);			
		}//for-i
	}//if	
}//get

int main(){	
	for(int i=0; i<10; i++){
		scanf("%d", &turn[i]);
	}//for-i
	get(0);	
	printf("%d\n", mmax);
	return 0;
}//main



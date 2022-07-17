#include<iostream>
using namespace std;
int grp[]={0, 5, 10, 15, 20,
		   50, 30, 35, 40, 45,
		   100, 55, 60, 65, 70,
		   75, 80, 85, 90, 95, 
		   500, 1000
		  };
int step[20];
int pic;

int main(){	
	int num; scanf("%d", &num);
	for(int i=0; i<num; i++){
		if(pic==21) break;
		scanf("%d", &step[i]);
		pic+=step[i];
		if(pic>21) pic=21;
		printf("%d ",  grp[pic]);
	}//for-i	
	return 0;
}//main

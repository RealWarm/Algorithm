#include<iostream>
using namespace std;
int grp[9][9];

int main(){
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			scanf("%d", &grp[i][j]);
		}
	}
	
	int max=0, xinx=0, yinx=0;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(grp[i][j]>max){
				max=grp[i][j];
				xinx=i;
				yinx=j;
			}
		}
	}	
	
	printf("%d\n%d %d", max, xinx+1, yinx+1);
	
	return 0;
}//main

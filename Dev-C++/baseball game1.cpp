#include<iostream>
using namespace std;
int grp[101][3];

int main(){
	
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &grp[i][0], &grp[i][1], &grp[i][2]);
	}//for-i
	int total=0;
	for(int a=1; a<=9; a++){
		for(int b=1; b<=9; b++){
			for(int c=1; c<=9; c++){
				if(a==b || b==c || a==c) continue;
				int cnt=0;
				for(int i=0; i<n; i++){
					int strike=0;
					int ball=0;
					int fs = grp[i][0]/100;
					int sd = (grp[i][0]/10)%10;
					int td = grp[i][0]%10;
					
					if(fs==a) strike++;
					if(sd==b) strike++;
					if(td==c) strike++;
					
					if(fs==b || fs==c) ball++;
					if(sd==a || sd==c) ball++;
					if(td==a || td==b) ball++;
					
					if(grp[i][1]==strike && grp[i][2]==ball){
						cnt++;
					}else{
						break;
					}//if
				}//for-i
				if(cnt==n){
					total++;
				}//if
			}//for-c
		}//for-b
	}//for-a
	
	printf("%d", total);
	return 0;
}//main

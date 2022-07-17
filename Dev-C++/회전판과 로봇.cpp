#include<cstdio>
using namespace std;
int grp[505][505];
int rol[10];
int m, n, x, y, k, rolcnt, sum;

int rand(int a, int b){
	if(a==1){
		while(b--){
			rolcnt--;
			if(rolcnt<0) 
				rolcnt=k-1;						
		}//while
	}else if(a==2){
		while(b--){
			rolcnt++;
			if(rolcnt>=k)
				rolcnt=0;
		}//while
	}//if
	return rol[rolcnt];	
}//rand

void forward(char a, int b){
	if(a=='N'){
		while(b--){
			y-=1;
			if(y<0){
				y+=1;
				return;
			}//if
			if(grp[y][x]==-1){
				y+=1;			
				return;
			}
			sum+=grp[y][x];
			grp[y][x]=0;				
		}//while
	}else if(a=='S'){
		while(b--){
			y+=1;
			if(y>=m){
				y-=1;
				return;
			}
			if(grp[y][x]==-1){
				y-=1;
				return;
			}
			sum+=grp[y][x];
			grp[y][x]=0;
		}//while		
	}else if(a=='W'){
		while(b--){
			x-=1;
			if(x<0){
				x+=1;
				return;
			}
			if(grp[y][x]==-1){
				x+=1;
				return;
			}
			sum+=grp[y][x];
			grp[y][x]=0;
		}//while		
	}else if(a=='E'){
		while(b--){
			x+=1;
			if(x>=n){
				x-=1;
				return;
			}
			if(grp[y][x]==-1){
				x-=1;
				return;
			}
			sum+=grp[y][x];
			grp[y][x]=0;
		}//while
	}//if-else
}//forward

int main(){	
	int t; scanf("%d", &t);	
	for(int q=1; q<=t; q++){			
		sum=0, rolcnt=0;
		scanf("%d %d %d %d", &n, &m, &x, &y);
		x-=1;
		y-=1;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				scanf(" %d", &grp[i][j]);
				
		sum+=grp[y][x];
		grp[y][x]=0;
		
		scanf("%d", &k);
		for(int i=0; i<k; i++)
			scanf("%d", &rol[i]);				
		
		int l; scanf("%d", &l);
		for(int i=0; i<l; i++){
			char na;
			int rolDir, rolNum;
			scanf(" %c %d %d", &na, &rolDir, &rolNum);
			forward(na, rand(rolDir, rolNum));			
		}//while-2
		
		printf("#%d %d %d %d\n", q, sum, x+1, y+1);
		
	}//for-q
	
	return 0;
}//main

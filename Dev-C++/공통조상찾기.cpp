#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int color[1005] ={0};
	int parent[1005]={0};
	int n;
	int x, y;
	
	scanf("%d %d %d", &n, &x, &y);
	
	for(int i=0; i<n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		//b의 위에는 a가 있다. 
		parent[b]=a;
	}
	
	while(1){
		color[x]=1;
		if(x==0) break;
		x=parent[x];	
	}//while
	
	while(1){
		if(color[y]==1){
			printf("%d", y);
			break; 
		}
		color[y]= 1;
		y=parent[y];
	}//while
	
	//(1) x의 모든 조상을 색칠한다.
	//(2) y의 모든 조상을 색칠한다.
	//		만약, 이미 조상체크가 되어있다면
	//				이 조상을 출력하고 끝낸다. 
	
	return 0;
}//main

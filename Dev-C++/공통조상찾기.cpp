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
		//b�� ������ a�� �ִ�. 
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
	
	//(1) x�� ��� ������ ��ĥ�Ѵ�.
	//(2) y�� ��� ������ ��ĥ�Ѵ�.
	//		����, �̹� ����üũ�� �Ǿ��ִٸ�
	//				�� ������ ����ϰ� ������. 
	
	return 0;
}//main

#include<iostream> 
#include<algorithm> 
#include<vector>
using namespace std;
int dx[]={0, -1,  0, 1};	// 우, 상, 좌, 하
int dy[]={1,  0, -1, 0};
vector<int> v1;
int ntx, nty;	// 세로, 가로
int wei[110][110];
int n, cnt, nm=100;

void go(){
	// 지금의 드래곤커브로 새로운 드래곤 커브를 만들고
	// 전진하면서 채우기 	
	int vs=v1.size();
	for(int i=vs-1; i>=0; i--){
		int tmp = (v1[i]+1)%4;
		ntx+=dx[tmp];
		nty+=dy[tmp];
		wei[ntx][nty]=1;		
		v1.push_back(tmp);
	}//for-i
}//go

int main(){
	int total=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){		
		v1.clear();
		int y, x, d, g; 
		scanf("%d %d %d %d", &y, &x, &d, &g);		
		v1.push_back(d);
		ntx=x+dx[d];
		nty=y+dy[d];
		wei[x][y]=1;
		wei[ntx][nty]=1;		
		for(int a=0; a<g; a++){
			go();
		}//for-a		
	}//for-i
	////////////////////////////////////////	
	for(int i=0; i<=nm-1; i++){
		for(int j=0; j<=nm-1; j++){
			if(wei[i][j]==1     &&
			   wei[i][j+1]==1   &&
			   wei[i+1][j]==1   &&
			   wei[i+1][j+1]==1){			   
			   cnt++;
			}//if			
		}//for-j		
	}//for-i
	////////////////////////////////////////
//	for(int i=0; i<20; i++){
//		for(int j=0; j<20; j++){
//			printf("%d ", wei[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
	printf("%d\n", cnt);
	
	return 0;
}//main

//3
//3 3 0 1
//4 2 1 3
//4 2 2 1





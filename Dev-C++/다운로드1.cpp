#include<iostream> 
#include<algorithm>
#include<cstring>
#include<vector> 
#include<cmath>
#include<tuple>
using namespace std;
//여태까지 x를 세로, y를 가로로 해왔음 
//여기선 >> y : 가로, x : 세로
//제자리, 위, 오른쪽, 아래, 왼쪽
int dx[]={0, -1, 0, 1, 0};//제자리, 위쪽, 오른쪽, 아래쪽, 왼쪽 
int dy[]={0, 0, 1, 0, -1};
int grp[20][20][7];
int n, m, k; // 세로 가로 공유기의 갯수 
int s; //이동길이 
int ax, ay, ad, bx, by, bd; // y:세로, x:가로 
int adir[111]; //시간별 이동 방법을 저장하는 배열 
int bdir[111];
struct aps{
	int y;
	int x;
	int r;
	int d;
};
vector<aps> v1;//ap의 좌표들을 저장한다. 

void make(int y, int x, int r, int d, int z){	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int dis = abs(y-i) + abs(x-j); //$$$$$$ 
				if(dis <= r){//범위 안이니? 
					grp[i][j][z]=d;					
				}//if
		}//for-j
	}//fori			
}//make
///////////////////변경지점////////////////////////////////////////////////////////////// 
int compAp(int y, int x, int ds){
	// 함수의 정의 :: 해당 좌표가 포함되면서, 세기가 d인 ap인 번호를 반환한다. 
	// d세기의 ap의 좌표를 반환한다.
	// 지금 ap의 범위에 포함되고 세기가 d라면 그 ap의 번호를 반환한다.	
	for(int i=0; i<v1.size(); i++){
		if(v1[i].d == ds){//세기가 같고
			int dis = abs(y-v1[i].y)+abs(x-v1[i].x);
			if(dis<=v1[i].r){
				//지금좌표가 범위에도 포함되면 해당 ap의 좌표를 출력한다.
				int num=i; 
				return num;
			}//if			
		}//if
	}//for-i
}//compAp 
///////////////////////////////////////////////////////////////////////////////////////
void go(int tt){
	
	int tempA=ad;
	int tempB=bd;
	//a에 대한 연산만
	if(grp[ay][ax][0]>0){
		//ap 영역에 있다면 
		if(grp[ay][ax][0]!=grp[by][bx][0]){
			//a와 b가 다른 세기의 ap 범위에 있니? 
			ad-=grp[ay][ax][0];
///////////////////변경지점////////////////////////////////////////////////////////////// 
		}else if(grp[ay][ax][0] == grp[by][bx][0] &&
			 compAp(ay, ax, grp[ay][ax][0]) != compAp(by, bx, grp[ay][ax][0])){		 
//			 printf("a: in here||||| %d %d \n", grp[ay][ax][0], compAp(ay, ax, grp[ay][ax][0]));
			// 세기가 같지만 다른 에이피일 경우. 
			// 해당되는 ap의 번호를 비교해서 다르면 본래의 세기로 뺀다. 
			ad-=grp[ay][ax][0];
		}else{
///////////////////////////////////////////////////////////////////////////////////////						
			//a와 b가 같은 ap의 범위에 있다. 
			if(grp[ay][ax][1]>0 && grp[by][bx][1]==0){
				//a는 다른ap를 선택할수 있지만
				//b는 없는 경우								
				ad-=grp[ay][ax][1];
			}else if(grp[ay][ax][1]==0 && grp[by][bx][1]>0){
				//b는 다른 ap를 선택 할수 있지만
				//a는 없는 경우 
				ad-=grp[ay][ax][0];
			}else if(grp[ay][ax][1]==0 && grp[by][bx][1]==0){
				//a와 b 모두 다른 선택을 할 수 없는 경우 
				ad-=(grp[ay][ax][0]/2);
				
			}else if(grp[ay][ax][1]>0 && grp[by][bx][1]>0){
				//a와 b 모두 다른 선택을 할 수 있는 경우 
				//다운로드 용량 합이 최대가 되도록 결정한다. 
				//선택할수 있는 ap의 크기가 큰놈을 선택한다.				 
				if(grp[ay][ax][1]>grp[by][bx][1]){
					ad-=grp[ay][ax][1];
				}else if(grp[ay][ax][1]<grp[by][bx][1]){
					ad-=grp[ay][ax][0];
				}else if(grp[ay][ax][1]==grp[by][bx][1]){
					//선택가능한 ap의 세기각 같다면 
					//다운로드를 더많이 해야하는 사람이
					//높은 속도의 ap에 접근하도록 설정한다. 
					if(tempA>=tempB){
						ad-=grp[ay][ax][0];
					}else{
						ad-=grp[ay][ax][1];
					}//if-5
				}//if-4
			}//if-3
		}//if-2
	}//if-1
	
	//b에 대한 연산만 
	if(grp[by][bx][0]>0){
		//현재위치가 ap의 범위니? 
		if(grp[ay][ax][0]!=grp[by][bx][0]){
			//a와 b가 다른 ap의 범위에 있니? 
			bd-=grp[by][bx][0];
///////////////////변경지점////////////////////////////////////////////////////////////// 
		}else if(grp[ay][ax][0] == grp[by][bx][0] &&
			 compAp(ay, ax, grp[ay][ax][0]) != compAp(by, bx, grp[ay][ax][0]) ){		 			
			// 세기가 같지만 다른 에이피일 경우. 
			// 해당되는 ap의 번호를 비교해서 다르면 본래의 세기로 뺀다. 
//			printf("b: in here ||||| %d %d \n", grp[by][bx][0], compAp(by, bx, grp[by][bx][0]));
			bd-=grp[by][bx][0];
///////////////////////////////////////////////////////////////////////////////////////									
		}else{
			//a와 b가 같은 ap의 범위에 있다. 
			if(grp[ay][ax][1]>0 && grp[by][bx][1]==0){
				//a는 다른ap를 선택할수 있지만
				//b는 없는 경우									
				bd-=grp[by][bx][0];
			}else if(grp[ay][ax][1]==0 && grp[by][bx][1]>0){
				//b는 다른 ap를 선택할수 있지만
				//a는 없는 경우	
				bd-=grp[by][bx][1];
			}else if(grp[ay][ax][1]==0 && grp[by][bx][1]==0){
				//a와 b 모두 다른 선택을 할 수 없는 경우 
				bd-=(grp[by][bx][0]/2);
			}else if(grp[ay][ax][1]>0 && grp[by][bx][1]>0){
				if(grp[ay][ax][1]>grp[by][bx][1]){
					bd-=grp[by][bx][0];
				}else if(grp[ay][ax][1]<grp[by][bx][1]){
					bd-=grp[by][bx][1];
				}else if(grp[ay][ax][1]==grp[by][bx][1]){
					//선택가능한 ap의 세기각 같다면 
					//다운로드를 더많이 해야하는 사람이
					//높은 속도의 ap에 접근하도록 설정한다.
					if(tempA>=tempB){
						bd-=grp[by][bx][1];
					}else{
						bd-=grp[by][bx][0];
					}//if-5
				}//if-4
			}//if-3
		}//if-2	
	}//if-1
	
//	printf("%d :: ad: %d, bd:%d  //", tt, ad, bd);
//	printf("%d :: ay : %d, ax: %d   //", tt, ay, ax);
//	printf("%d :: by : %d, bx: %d\n", tt, by, bx);
	
}//go


int main(){
	
	int tt; scanf("%d", &tt);
	for(int ts=1; ts<=tt; ts++){
		memset(grp, 0, sizeof(grp));
		memset(adir, 0, sizeof(adir));
		memset(bdir, 0, sizeof(bdir));
		scanf("%d %d %d", &n, &m, &k);//좌표, 공유기갯수
		for(int i=0; i<k; i++){
			int y, x, r, d;//공유기의 좌표, 범위, 다운속도 
			scanf("%d %d %d %d", &y, &x, &r, &d);
			y--; x--; // 좌표가 (1,1)에서 시작하는 것을 (0,0)로 바꾼다.
			v1.push_back({y, x, r, d});
			make(y, x, r, d, i);
		}//for-i
				
		//와이파이의 세기별로 재배열한다. 
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				sort(grp[i][j], grp[i][j]+7, greater<int>());//내림차순 
			}
		}	
		///////////////////////////////////////////////////////////////
		scanf("%d", &s);
		for(int i=0; i<s; i++){
			scanf("%d", &adir[i]);
		}//for-i	
		for(int i=0; i<s; i++){
			scanf("%d", &bdir[i]);
		}//for-i
		///////////////////////////////////////////////////////////////	
		//여기서 실수!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		scanf("%d %d %d", &ay, &ax, &ad); ax--; ay--;// 좌표가 (1,1)에서 시작하는 것을 (0,0)로 바꾼다.
		scanf("%d %d %d", &by, &bx, &bd); bx--; by--;// 좌표가 (1,1)에서 시작하는 것을 (0,0)로 바꾼다.
		///////////////////////////////////////////////////////////////	
		for(int i=0; i<=s; i++){
			//A와 B의 시작 위치는 공유기의 위치가 될 수 있으며, 
			//서로 같은 시작점을 가질수도 있다. 시작점이 만약 공유기 범위 내부라면 
			//이동 시작과 동시에 공유기 용량만큼 다운로드를 받을 수 있다.
			//처음 시작의 위치부터 판별을 하기위해서				
			go(i);		 
			//여기서 실수!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			ax+=dy[adir[i]];
			ay+=dx[adir[i]];
			bx+=dy[bdir[i]];
			by+=dx[bdir[i]];
		}//for-i
		
		if(ad<0) ad=0;
		if(bd<0) bd=0;
		
		printf("#%d %d %d\n", ts, ad, bd);
		///////////////////////////////////////////////////////////////	
	//	//와이파이 배열이 제대로 출력되는지
	//	for(int i=0; i<k; i++){
	//		for(int j=0; j<n; j++){
	//			for(int t=0; t<m; t++){
	//				printf("%d ", grp[j][t][i]/100);
	//			}
	//			printf("\n");
	//		}
	//		printf("\n\n\n");
	//	}
	}//for-ts
	
	
	return 0;
}//main

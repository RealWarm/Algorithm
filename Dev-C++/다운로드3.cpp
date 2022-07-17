#include<iostream> 
#include<algorithm>
#include<cstring>
#include<vector> 
#include<cmath>
#include<tuple>
using namespace std;
int dx[]={0, -1, 0, 1, 0};//제자리, 위쪽, 오른쪽, 아래쪽, 왼쪽 
int dy[]={0, 0, 1, 0, -1};
int n, m, k; // 세로 가로 공유기의 갯수 
int s; //이동길이 
int ax, ay, ad, bx, by, bd; // y:세로, x:가로 
int adir[111]; //시간별 이동 방법을 저장하는 배열 
int bdir[111];

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
	}//for-ts
	
	
	return 0;
}//main

#include <iostream> 
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
struct person{
	int px;
	int py;
	int gx;
	int gy;
	int dis=-987;//손님과 택시사이의 거리 
};
struct taxi{
	int x;
	int y;
	int f=0;
};
vector<person> v1;
int grp[25][25];
int wei[25][25];
int n, m, f;	//변의길이, 승객의수, 초기 연료량 
taxi tx;		//택시 

person make_pp(int px, int py, int gx, int gy){
	person ps;
	ps.px=px;
	ps.py=py;
	ps.gx=gx;
	ps.gy=gy;
	return ps;
}//make_pp

int comp(person p1, person p2){
	if(p1.dis<p2.dis){
		return 1;
	}else if(p1.dis==p2.dis){
		if(p1.py<p2.py){
			return 1;
		}else if(p1.py==p2.py){
			if(p1.px<p2.px){
				return 1;
			}else{
				return 0;
			}//if-3
		}else if(p1.py>p2.py){
			return 0;
		}//if-2
	}else if(p1.dis>p2.dis){
		return 0;
	}//if-1
}//comp

int go(){
	// 가장 가까운 손님을 선택한다 >> 혹시 손님과 같은자리니?
	// >> yes >> 택시의 좌표초기화
	// >> No  >> 택시를 기준으로 bfs를 시작 >> 가장 가까운 손님 고르기
	// 손님까지 갈수있는 연료가 되니? >> NO >> 함수종료
	//						>> yes >> 택시의 좌표 초기화 && 연료 감소 
	
	// 손님을 기준으로 bfs 시전 >> 목적지까지 갈 연료가 되니? >> NO >>종료
	// >> yes >> 택시의 좌표 초기화 && 연료 충전 
	///////////////////////////////////////////////////////////////////
	// 택시부터 사람까지의 최단거리를 구한다 
	queue<pair<int, int> > q1;
	int mmin=987987, del=0; // 손님과의 최소거리, 태운 손님 인덱스 
	int flag=0;
	for(int i=0; i<v1.size(); i++){
		if(v1[i].px==tx.x &&
			v1[i].py==tx.y){
			flag=1;
			tx.x=v1[i].px;
			tx.y=v1[i].py;	
			mmin=0;
			del=i;		
			break;
		}//if
	}//for-i
		
	if(flag==0){
		memset(wei, -1, sizeof(wei));		
		q1.push(make_pair(tx.x, tx.y));
		wei[tx.x][tx.y]=0;
		
		while(!q1.empty()){
			int nwx=q1.front().first;
			int nwy=q1.front().second;
			q1.pop();
			for(int k=0; k<4; k++){
				int ntx=nwx+dx[k];
				int nty=nwy+dy[k];
				if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
				if(grp[ntx][nty]==0 && wei[ntx][nty]==-1){
					wei[ntx][nty]=wei[nwx][nwy]+1;
					q1.push(make_pair(ntx, nty));
				}//if
			}//for-k
		}//while
		// 못가는 손님이 있다면 -1 리턴 
		for(int i=0; i<v1.size(); i++){
			// 손님의 위치중에서 갈수 없는 곳이있다면 탈출 
			int xx=v1[i].px;
			int yy=v1[i].py;			
			if(wei[xx][yy]==-1) return -1;
			v1[i].dis=wei[xx][yy];
		}//for-i
		/////////////////////////////////////////		
		// 가장 가까운 손님좌표 고르기 
		// 1) 거리가 가장짧고 2) 행 작고 3) 열 작고 
		sort(v1.begin(), v1.end(), comp);
		/////////////////////////////////////////
		// 연료가 되니? 
		if(tx.f>=v1[0].dis){
			tx.f-=v1[0].dis;	
		}else{
			return -1;
		}//if 	
		
	}//if-1
	///////////////////////////////////////////////////////////	
//	printf("==========================================\n");
//	printf("손님좌표::(%d, %d) || 최단거리:: %d\n", 
//						v1[del].px, v1[del].py, mmin);
	////////////////////////////////////////////////////////////
	// 손님에서 목적지까지의 최단거리 구하기 
	memset(wei, -1, sizeof(wei));	
	q1.push(make_pair(v1[del].px, v1[del].py));
	wei[v1[del].px][v1[del].py]=0;	
	
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) continue;
			if(grp[ntx][nty]==0 && wei[ntx][nty]==-1){
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while	
	
	// 택시에서 목표까지 못가는게 있다면. 
	for(int i=0; i<v1.size(); i++){
		// 손님의 위치중에서 갈수 없는 곳이있다면 탈출 
		int xx=v1[i].gx;
		int yy=v1[i].gy;			
		if(wei[xx][yy]==-1) return -1;		
	}//for-i
				
	int ggx=v1[del].gx;
	int ggy=v1[del].gy;
//	printf("목적지 좌표::(%d, %d) || 거리:: %d\n", 
//			v1[del].gx, v1[del].gy, wei[ggx][ggy]);
	if(tx.f>=wei[ggx][ggy]){
		tx.f=tx.f+wei[ggx][ggy];
		tx.x=ggx;
		tx.y=ggy;
		v1.erase(v1.begin()+del);
	}else{
		return -1;
	}//if 
//	printf("남은 연료 :: %d\n", tx.f);
		
	return 0;
}//go

int main(){
	/////////////////////////////////////////////////////////////
	scanf("%d %d %d", &n, &m, &f);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %d", &grp[i][j]);
		}//for-j
	}//for-i	
	scanf("%d %d", &tx.x, &tx.y);
	tx.x--, tx.y--;
	tx.f=f;
	for(int i=0; i<m; i++){
		int px, py, gx, gy;
		scanf("%d %d %d %d", &px, &py, &gx, &gy);
		px--, py--, gx--, gy--;
		v1.push_back(make_pp(px, py, gx, gy));
	}//for-i	
	sort(v1.begin(), v1.end(), comp);
//	printf("=====================================\n");
//	for(int i=0; i<v1.size(); i++){
//		printf("%d %d %d %d\n", v1[i].px, v1[i].py, v1[i].gx, v1[i].gy);
//	}//for-i
	/////////////////////////////////////////////////////////////
	for(int i=0; i<m; i++){
//		printf("v1 size ::: %d \n", v1.size());
		if(v1.size()==0 || go()==-1){
			// 아직 모든 손님을 태우지 못했는데
			// 끝나면 -1 출력 
			printf("-1\n");
			return 0;
		}//if
	}//for-i
	/////////////////////////////////////////////////////////////
	printf("%d\n", tx.f);
	
	return 0;
}//main

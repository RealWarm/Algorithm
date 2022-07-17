#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct tp{
	int x;
	int y;
	int tnum;
}; 
int dx[]={-1,0,1, 0};//상, 우, 하, 좌  
int dy[]={ 0,1,0,-1};
vector<tp> v1; // 수도꼭지의 번호를 저장한다. 
int tap[6][4]={ {0,0,0,0},
				{1,0,0,0},
				{1,0,1,0},
				{1,1,0,0},
				{1,1,0,1},
				{1,1,1,1} };
int grp[20][20];
int tmp[20][20];
int ch[10];//수도꼭지의 방향저장
int r, mmin=987987987;//수도꼭지의 갯수 
int n, m;

void fill(tp tt, int dir){
	int xx=tt.x;
	int yy=tt.y;
	int tn=tt.tnum;
	int ppap[4];
	/////////꼭지를 복사한다. 
	for(int i=0; i<4; i++){
		ppap[i]=tap[tn][i];
	}//for-i
	while(dir--){		
		int ed=ppap[3];
		for(int i=3; i>=1; i--){			
			ppap[i]=ppap[i-1];
		}
		ppap[0]=ed;
	}//while	
	for(int i=0; i<4; i++){
		int nwx=xx;
		int nwy=yy;
		if(ppap[i]==1){
			while(1){
				nwx+=dx[i];
				nwy+=dy[i];
				if(nwx<0 || nwy<0 || nwx>=n || nwy>=m) break;
				if(tmp[nwx][nwy]==0){
					tmp[nwx][nwy]=-1; //////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 2로 하면 안되지 
				}else if(tmp[nwx][nwy]>=1 && tmp[nwx][nwy]<=5){
					continue;
				}if(tmp[nwx][nwy]==6){
					break;
				}//if
			}//while
		}//if
	}//for-i
	
}//fill

void get(int x){

	if(x>=r){
		int emsp=0;
		memcpy(tmp, grp, sizeof(tmp));
		
		for(int i=0; i<r; i++){ // v1의 인덱스에 ch[i]를 넣었음 
			fill(v1[i], ch[i]);
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(tmp[i][j]==0){
					emsp++;
				}//if
			}//for-j
		}//for-i
		
		if(mmin>emsp){
			mmin=emsp;
		}
	}else{
		for(int i=0; i<4; i++){
			ch[x]=i;
			get(x+1);
		}//for-i		
	}//if	
}//get

int main(){
	
	
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		v1.clear();
		mmin=987987987;		
		memset(ch, 0, sizeof(ch));
		memset(grp, 0, sizeof(grp));
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &grp[i][j]);
				if(grp[i][j]>=1 && grp[i][j]<=5){
					v1.push_back({i, j, grp[i][j]});
				}//if
			}//for-j
		}//for-i
		r=v1.size(); 
		get(0);
		printf("#%d %d\n", tt, mmin);	
	}//for-tt
	
	
	return 0;
}//main


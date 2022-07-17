#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
int dx[]={-1, 1,  0, 0}; // 위, 아래, 왼쪽, 오른쪽
int dy[]={ 0, 0, -1, 1};
struct shark{
	int num;	// 상어의 번호 1<=num<=m
	int sx;		// 상어의 세로좌표 
	int sy;		// 상어의 가로좌표
	int dir=0;	// 상어의 현재 방향
	int sdir[4][4]={{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0}};	
};//shark 
int n, m, k;		// 그래프의 넓이, 상어의 수, 영역의 세기 
int grp[200][200][4];	// [0] : 영역의 상어의 번호, [1] : 영역의 세기, [2] : 현재 상어의 위치 
vector<shark> v1;

shark make_sh(int num, int sx, int sy){
	shark tmp;
	tmp.num=num;
	tmp.sx=sx;
	tmp.sy=sy;
	return tmp;
}//make_sh

int compare(shark s1, shark s2){
	// 상어의 번호를 내림차순으로 정렬한다. 
	if(s1.num<s2.num){
		return 1;
	}else{
		return 0;
	}//if
}//compare

void go(){
	if(v1.size()<=1) return; //런타임에러
	// 상어를 해당방향으로 전진 시켜본다
	// 전진이 가능하다 == grp[1]이 "영" 일때 
	// 전진이 가능하면 전진시키고 grp[0]에 상어의 번호, grp[1]에 k 저장 안함 
	// 전진이 안된다면 이전 방향으로 이동하기 && 이전 방향 grp[1]에 k 저장
	for(int i=0; i<v1.size(); i++){
		int td=v1[i].dir;// 상어의 현재 방향 추출 
		int flag=0;// 전진하면 1, 전진 못하면 0 
		for(int j=0; j<4; j++){
			int ndir=v1[i].sdir[td][j];	// 우선 순위별 방향 추출 
			int ntx=v1[i].sx+dx[ndir];	// 방향으로 전진하기 
			int nty=v1[i].sy+dy[ndir];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) {
//				printf("range1!\n");
				continue;
			}
			if(grp[ntx][nty][1]==0){
				// 진행 할 수 있다면 >> 진행한다 
				// 전진하기전 나의 위치를 0으로 바꾼다 
				grp[v1[i].sx][v1[i].sy][2]=0;
				flag=1;
				v1[i].sx=ntx;
				v1[i].sy=nty;
				v1[i].dir=ndir;
				
				if(grp[ntx][nty][0]!=0 &&
					grp[ntx][nty][0]>v1[i].num){
					//요거!!!!!!! 
					grp[ntx][nty][0]=v1[i].num;	
				}else if(grp[ntx][nty][0]==0){
					grp[ntx][nty][0]=v1[i].num;	
				}//if
				grp[ntx][nty][2]=v1[i].num;
				break;// 전진가능한 방향을 찾았다면 전진하고 탈출 
			}//if			
		}//for-j
		
		if(flag==0){ 
			// 전진하지 못했다면 
			// 아까 전진했던 방향을 찾아 돌아가기 
			int td=v1[i].dir;// 상어의 현재 방향 추출 
			for(int j=0; j<4; j++){
				int ndir=v1[i].sdir[td][j];	// 우선 순위별 방향 추출 
				int ntx=v1[i].sx+dx[ndir];	// 방향으로 전진하기 
				int nty=v1[i].sy+dy[ndir];
				if(ntx<0 || nty<0 || ntx>=n || nty>=n) {
//					printf("range2!\n");
					continue;
				}
				if(grp[ntx][nty][0]==v1[i].num){
					// 그 방향으로 전진하고
					// 영역의 세기를 k로 초기화 
					grp[v1[i].sx][v1[i].sy][2]=0;//여기!!!!!!!!!! 
					v1[i].sx=ntx;
					v1[i].sy=nty;
					v1[i].dir=ndir;
					grp[ntx][nty][2]=v1[i].num;
					break; 
				}//if
			}//for-j
		}//if-1
		
	}//for-i
		 
}//go

void col(){
	// 전진한 상어는 아직 영역 표시를 하지않았다 
	// 충돌한 상어들을 찾아내어 제거한다
	// 사라지더라도 영역은 남는다.
	if(v1.size()<=1) return; //런타임에러 
	for(int i=0; i<v1.size(); i++){
		for(int j=i+1; j<v1.size(); ){
			if(v1[i].sx==v1[j].sx &&
				v1[i].sy==v1[j].sy &&
				grp[i][j][1]==0){					
					if(v1.size()<=1) return; //런타임에러
					v1.erase(v1.begin()+j);  // erase 주의 사항 찾기 
//					j--; 					
				}else{
					j++;
				}
		}//for-i
	}//for-i	
}//col

void vanish(){
	if(v1.size()<=1) return;//런타임에러
	// 상어가 있었었던 위치의 영역의 세기를 1씩 줄인다
	// 1) 상어가 위치해있으면서 && grp[i][j][1]==0이면 k를 넣는다. >> 전진한경우 
	// 2) 상어가 위치해있으면서 && grp[i][j][1]!=0이면 k를 넣는다. >> 돌아온경우 
	//  ** 상어가 있으면(grp[i][j][2]!=0) >> grp[i][j][1]=k 
	// 3) 상어가 없고 && grp[i][j][0]!=0 && grp[i][j][1]!=0 이면 1을 감소하고
	//		영역의 값이 영이면(grp[i][j][1]==0)  >> grp[i][j][0]=0으로 초기화하기 	 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grp[i][j][2]!=0){
				grp[i][j][1]=k;
			}else if(grp[i][j][2]==0 &&
					 grp[i][j][0]!=0 && 
					 grp[i][j][1]!=0 ){
				grp[i][j][1]-=1;
			}//if
			
			if(grp[i][j][1]==0){ 
				// 런타임 에러 
				grp[i][j][0]=0;
			}//if
			
		}//for-j
	}//for-i
}//vanish

int main(){
	
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %d", &grp[i][j][0]);
			if(grp[i][j][0]!=0){	//	상어를 발견했다면 
				grp[i][j][1]=k;		// 	해당위치에 영역표시하기 
				grp[i][j][2]=grp[i][j][0];	//	상어의 현재위치 
				v1.push_back(make_sh(grp[i][j][0], i, j));
			}//if
		}//for-j
	}//for-i
	sort(v1.begin(), v1.end(), compare); //충돌할때 번호작은게 살아남게하기위해서 
	////////////////////////////////////////////////////////
	for(int i=0; i<v1.size(); i++){
		scanf(" %d", &v1[i].dir);
		v1[i].dir-=1;
	}//for-i
	////////////////////////////////////////////////////////
	for(int i=0; i<v1.size(); i++){		
		for(int j=0; j<4; j++){
			scanf("%d %d %d %d", &v1[i].sdir[j][0], 
								 &v1[i].sdir[j][1],
								 &v1[i].sdir[j][2], 
								 &v1[i].sdir[j][3]);
			
			v1[i].sdir[j][0]-=1; 
			v1[i].sdir[j][1]-=1; 
			v1[i].sdir[j][2]-=1; 
			v1[i].sdir[j][3]-=1; 
		}//for-k		
	}//for-i		
	/////////////////////////////////////////////////////
	int time=1;
	for( ; time<=1001; time++){
		vanish(); // 변경 
		go();	
		col();		
		if(v1.size()<=1){ //런타임에러!!!!!!!! 
			break;
		}//if
	}//for-i
	/////////////////////////////////////////////////////
	if(time>=1000){ //여기? 
		printf("-1\n");
	}else{
		printf("%d\n", time);
	}//if
	
	return 0;
}//main

//	for(int i=0; i<m; i++){				
//		printf("%d %d %d \n", v1[i].num, v1[i].sx,
//				v1[i].sy);		
//	}//for-i

//	for(int i=0; i<m; i++){
//		printf("%d ", v1[i].dir);		
//	}//for-i

//	printf("%d %d %d\n", n, m, k);
//	printf("====================================\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%d ", grp[i][j]);			
//		}//for-j
//		printf("\n");
//	}//for-i
//	printf("====================================\n");
//	for(int i=0; i<m; i++){		
//		printf("%d 번째 상어의 우선순위\n", v1[i].num);
//		for(int j=0; j<4; j++){
//			printf("%d %d %d %d\n", v1[i].sdir[j][0], 
//									v1[i].sdir[j][1],
//									v1[i].sdir[j][2], 
//									v1[i].sdir[j][3]);
//		}//for-k		
//		printf("\n");
//	}//for-i



//		printf("====================================\n");
//		for(int i=0; i<n; i++){
//			for(int j=0; j<n; j++){
//				printf("%d ", grp[i][j][0]);
//			}//for-j
//			printf("\n");
//		}//for-i
//		printf("====================================\n");
//		for(int i=0; i<n; i++){
//			for(int j=0; j<n; j++){
//				printf("%d ", grp[i][j][1]);
//			}//for-j
//			printf("\n");
//		}//for-i



	//////////////////////////////////////////////////
//	printf("====================================\n");
//	printf("%d %d %d\n", n, m, k);
//	printf("====================================\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n; j++){
//			printf("%d ", grp[i][j][0]);			
//		}//for-j
//		printf("\n");
//	}//for-i	
	
//	printf("====================================\n");
//	for(int i=0; i<m; i++){		
//		printf("%d 번째 상어의 우선순위:: 방향: %d \n", v1[i].num,v1[i].dir);
//		for(int j=0; j<4; j++){
//			printf("%d %d %d %d\n", v1[i].sdir[j][0], 
//									v1[i].sdir[j][1],
//									v1[i].sdir[j][2], 
//									v1[i].sdir[j][3]);
//		}//for-k		
//		printf("\n");
//	}//for-i










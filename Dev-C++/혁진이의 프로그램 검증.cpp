#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[]={0, 0,-1, 1}; // �����ϻ� 
int dy[]={1,-1, 0, 0};
struct cmp{
	int x=0;
	int y=0;
	int dir=0;
	int mm=0;
	cmp(){}
	cmp(int x1, int y1, int d1, int m1) : 
	x(x1), y(y1), dir(d1), mm(m1) {}
};//cmp 
int wei[30][30][10][20]; // x, y, ����, �޸� >> �湮���� 
char grp[30][30];
int r, c; // ���� ���� 

cmp make_c(int x, int y, int d, int m){
	cmp tmp;
	tmp.x=x;
	tmp.y=y;
	tmp.dir=d;
	tmp.mm=m;
	return tmp;
}//make_c

string bfs(){
	queue<cmp> q1;
	q1.push(make_c(0,0,0,0));
	wei[0][0][0][0]=1;
	
	while(!q1.empty()){
		int nwx=q1.front().x;
		int nwy=q1.front().y;
		int nwd=q1.front().dir;
		int nwm=q1.front().mm;		
		q1.pop();	
		
		// �� �� �� �� 
		if(grp[nwx][nwy]>='0' && grp[nwx][nwy]<='9'){
			nwm=grp[nwx][nwy]-'0';
		}else if(grp[nwx][nwy]=='<'){
			nwd=1;
		}else if(grp[nwx][nwy]=='>'){
			nwd=0;
		}else if(grp[nwx][nwy]=='^'){
			nwd=3;
		}else if(grp[nwx][nwy]=='v'){
			nwd=2;
		}else if(grp[nwx][nwy]=='_'){
			// 0�̸� ��, �ƴϸ� �� 
			nwd= nwm==0 ? 0:1;
		}else if(grp[nwx][nwy]=='|'){
			// 0�̸� �Ʒ�, �ƴϸ� ��
			nwd= nwm==0 ? 2:3;
		}else if(grp[nwx][nwy]=='?'){ // �� �� �� �� 	 
			for(int k=0; k<4; k++){
				int ntx=nwx+dx[k];
				int nty=nwy+dy[k];				
				// ������ �Ѿ��ٸ� ������ �ٲ��ش�. 
				if(ntx>=r){
					// �Ʒ� ���� �����ٸ� ���� 
					ntx=0;
				}else if(ntx<0){
					// ���� ���� �����ٸ� �Ʒ��� 
					ntx=r-1;
				}else if(nty>=c){
					// �����ʳ��� �����ٸ� ��������
					nty=0;
				}else if(nty<0){
					// ���� ���� �����ٸ� ���������� 
					nty=c-1;
				}//if
				if(wei[ntx][nty][k][nwm]==1) continue;	 
				q1.push(make_c(ntx, nty, k, nwm));
				wei[ntx][nty][k][nwm]=1;
			}//for-k			
		}else if(grp[nwx][nwy]=='+'){
			nwm=nwm==15 ? 0 : nwm+1;
		}else if(grp[nwx][nwy]=='-'){
			nwm=nwm==0 ? 15 : nwm-1;
		}else if(grp[nwx][nwy]=='@'){
			return "YES";		
		}//if		
		
		
		int ntx=nwx+dx[nwd];
		int nty=nwy+dy[nwd];
		if(ntx>=r){
			// �Ʒ� ���� �����ٸ� ���� 
			ntx=0;
		}else if(ntx<0){
			// ���� ���� �����ٸ� �Ʒ��� 
			ntx=r-1;
		}else if(nty>=c){
			// �����ʳ��� �����ٸ� ��������
			nty=0;
		}else if(nty<0){
			// ���� ���� �����ٸ� ���������� 
			nty=c-1;
		}//if
		if(wei[ntx][nty][nwd][nwm]==1) continue;	 
		q1.push(make_c(ntx, nty, nwd, nwm));
		wei[ntx][nty][nwd][nwm]=1;
		
	}//while
	
	return "NO";	
}//bfs
 
int main(){	
	int tt; scanf("%d", &tt);
	for(int ts=1; ts<=tt; ts++){		
		// �Է� & �ʱ�ȭ 
		memset(wei, -1, sizeof(wei));
		scanf("%d %d", &r, &c);		
		for(int i=0; i<r; i++){
			scanf("%s", grp[i]);
		}//for-i
		printf("#%d %s\n", ts, bfs().c_str());	
		////////////////////////////////////
	}//for-ts	
    return 0;
}//main

















//		for(int i=0; i<r; i++){
//			for(int j=0; j<c; j++){
//				printf("%c", grp[i][j]);
//			}//for-j
//			printf("\n");
//		}//for-i




















#include<iostream>
using namespace std;
int dx[]={-1, 0, 1,  0}; // �� �� �� �� 
int dy[]={ 0, 1, 0, -1};
int grp[1010][1010];
int r, c; // ���� ����(y, x)
int inx, iny; // k��° ������ ��ǥ 
int k, flag, cnt; 

int main(){
	scanf(" %d %d %d", &r, &c, &k);
	///////////////////////////////////////////////	
	k= k%(r*c+1);
	printf("%d\n", k);
	int dir=0;
	int nwx=r-1; // ����  
	int nwy=0; // ���� 
	for(int tt=1; tt<=(r*c); tt++){	
		int ntx=nwx+dx[dir];
		int nty=nwy+dy[dir];
		if(ntx<0 || nty<0 || ntx>=c || nty>=r){
			//������ ���� ���ٸ� ������ �ٲ۴�. 
			dir=(dir+1)%4;
			--tt;		 /// ���� �Ǽ� 
			continue;
		}//if 
		if(grp[ntx][nty]==0){
			// ������ ���ٸ� �ش� �������� ���� 
			nwx=ntx;
			nwy=nty;
			grp[ntx][nty]=++cnt;
//			printf("%d\n", cnt);
		}else if(grp[ntx][nty]!=0){
			// ������ �ִٸ� ������ �ٲ۴�.	
			--tt;		 /// ���� �Ǽ�  
			dir=(dir+1)%4;
		}//if
		if(cnt==k){
			inx=(c-ntx);
			iny=nty;			
			break;
		}//if		
	}//while
//	for(int i=0; i<c; i++){
//		for(int j=0; j<r; j++){
//			printf("%2d ", grp[i][j]);
//		}
//		printf("\n");
//	}
	///////////////////////////////////////////////
	///////////////////////////////////////////////	
	printf("%d %d\n", iny+1, inx);
	return 0;
}//main

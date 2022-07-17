#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath> 
using namespace std;
queue<pair<int, int> > q1, q2;
int dx[]={0, 0,1,-1};
int dy[]={1,-1,0, 0};
int grp[60][60]; 
int wei[60][60];
int wei2[60][60];
int px, py;//������� ��ǥ 
int r, c;	//	����, ���� 

void bfs(){	
	memset(wei, -1, sizeof(wei));
	while(!q1.empty()){
		int nwx=q1.front().first;
		int nwy=q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];
			if(ntx<0 || nty<0 || ntx>=r || nty>=c) continue;
			if(wei[ntx][nty]==-1 && 
				grp[ntx][nty]!=2 && 
				grp[ntx][nty]!=3){
				//�湮 ���߰�, ���� �ƴϰ� ������� �ƴϸ� �����ִ�. 
				wei[ntx][nty]=wei[nwx][nwy]+1;
				q1.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while
}//bfs

void bfs2(){
	memset(wei2, -1, sizeof(wei2));
	while(!q2.empty()){
		int nwx=q2.front().first;
		int nwy=q2.front().second;
		q2.pop();
		for(int k=0; k<4; k++){
			int ntx=nwx+dx[k];
			int nty=nwy+dy[k];			
			if(ntx<0 || nty<0 || ntx>=r || nty>=c) continue;
			//////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////
			if(wei2[ntx][nty]==-1 && //�湮���� �ʾҰ�			 
			   grp[ntx][nty]!=2 &&
			   wei2[ntx][nty]+1 < wei[ntx][nty]			   
			   ){				
				wei2[ntx][nty]=wei2[nwx][nwy]+1;
				q2.push(make_pair(ntx, nty));
			}//if
		}//for-k
	}//while
	
	if(wei2[px][py]!=-1){
		printf("%d \n", wei2[px][py]);
	}else{
		printf("KAKTUS\n");
	}
}//bfs

int main() {
	
	scanf("%d %d", &r, &c);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){			
			int num;
			char ch; 
			scanf(" %c", &ch);
						
			if(ch=='.'){//��� 
				num=0;	
			}else if(ch=='*'){//�� 
				q1.push(make_pair(i, j));
				wei[i][j]=0;
				num=1;
			}else if(ch=='X'){//�� 
				num=2;
			}else if(ch=='D'){//�����
				px=i; py=j;
				num=3;
			}else if(ch=='S'){//����ġ 
				q2.push(make_pair(i, j));
				wei2[i][j]=0;
				num=4;
			}//if
			grp[i][j]=num;
		}//for-j
	}//for-i
	
	bfs();	 	
//	printf("\n");
//	for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			printf("%2d ", wei[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
//	printf("\n");
	
	bfs2();
//    for(int i=0; i<r; i++){
//		for(int j=0; j<c; j++){
//			printf("%2d ", wei2[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
	
    return 0;
}//main

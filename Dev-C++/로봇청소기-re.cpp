#include<iostream>
#include<cstring>
using namespace std;
int grp[110][110];
int wei[110][110];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n, cnt;

void go(int x, int y, int dir){	
	wei[x][y]=1;	
	int nwx=x;
	int nwy=y;
	int gox=dx[dir];
	int goy=dy[dir];
//	printf("*����:(%d, %d) (%d, %d) dir :%d  \n", x, y, dx[dir], dy[dir], dir);
	while(1){
		//�ϴ� �����غ��� �Ǵ� 
		nwx+=gox;
		nwy+=goy;		
		if(nwx<0 || nwx>=n || nwy<0 || nwy>=n){
			//���� ������ 180�� ������ �ٲ۴�.
			//�����·� ���ƿ´�.
			gox=gox*-1;
			goy=goy*-1;			
			nwx+=gox;
			nwy+=goy;
//			printf("* ���� ���� :(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
			////////////////////////////////////////////////////////////////
			//������ �ߴµ� ���� �ٷ� �ε������ 
			int flag=0; 
			if(grp[nwx][nwy]>=6 && grp[nwx][nwy]<=10){
				//������ ��´�. 
//				printf("* �������� �ٷ� ���� ����:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);				
				for(int a=0; a<n; a++){
					for(int b=0; b<n; b++){
						if(a==nwx && b==nwy){
							//�����ڽ��̸� pass 
							continue;
						}else if(grp[a][b]==grp[nwx][nwy]){
							//�����̸鼭 �ڽİ� ��ȣ�� ������ �̵�
							if(flag==0){
								nwx=a;
								nwy=b;
//								printf("*�������� �ٷ� ���� �̵�:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);							
								flag=1;
							}//if							
						}//if-1
					}//for-b
				}//for-a
			}//if-1	
			
			if(grp[nwx][nwy]>=1 && grp[nwx][nwy]<=5){
				//��Ź� üũ�ϰ� >> �������� ����. 
				//������ �ٲ��ش�. 
//				printf("* %d ��ֹ� ����:(%d, %d) ���⺯����(%d, %d) cnt :%d  \n", grp[nwx][nwy], nwx, nwy, gox, goy, cnt);				
							
				if(grp[nwx][nwy]==1 && gox==1 && goy==0){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox	= 0;
					goy	= -1;
				}else if(grp[nwx][nwy]==1 && gox==0 && goy==1){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox	= -1;
					goy	= 0;
				}else if(grp[nwx][nwy]==2 && gox==1 && goy==0){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox	= 0;
					goy = 1;
				}else if(grp[nwx][nwy]==2 && gox==0 && goy==-1){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = -1;
					goy = 0;
				}else if(grp[nwx][nwy]==3 && gox==0 && goy==-1){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = 1;
					goy = 0;
				}else if(grp[nwx][nwy]==3 && gox==-1 && goy ==0){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = 0;
					goy = 1;
				}else if(grp[nwx][nwy]==4 && gox==0 && goy==1){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = 1;
					goy = 0;
				}else if(grp[nwx][nwy]==4 && gox==-1 && goy==0){
					if(wei[nwx][nwy]==0){
						wei[nwx][nwy]=1;
						cnt++;					
					}//if-2
					gox = 0;
					goy = -1;
				}else{
					if(wei[nwx][nwy]==0){//���ص��Ǵ°ǰ�? 
						wei[nwx][nwy]=1;						
					}//if-2
					gox=gox*-1;
					goy=goy*-1;				
				}//if-2			
//				printf("* %d ��ֹ� ����:(%d, %d) ���⺯����(%d, %d) cnt :%d  \n", grp[nwx][nwy], nwx, nwy, gox, goy, cnt);
			}//if-1 
											
		}else if(grp[nwx][nwy]==0 && wei[nwx][nwy]==0){
			//�湮���� ���� ���̸�
			//üũ�ϰ� �������� ������Ų��. 
			wei[nwx][nwy]=1;
			cnt++;
//			printf("* ��:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
		}else if(grp[nwx][nwy]==0 && wei[nwx][nwy]==1){
			//�������� �Դ����̶��
//			printf("* ��:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
//			continue;	///////////////////////////////		
		}else if(grp[nwx][nwy]==-1){
			//���̸� �ٷ� ������. 
//			printf("* �θ���:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
			return;
		}else if(grp[nwx][nwy]>=6 && grp[nwx][nwy]<=10){
			//������ ��´�. 
//			printf("* ���� ����:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
			if(wei[nwx][nwy]==0){
				wei[nwx][nwy]=1;
				cnt++;					
			}			
			// ������ ������ �ش��ڸ��� üũ�ϰ�(wei�� 1��) ������ ����(cnt++) 
			// �ٸ� ������ ��ǥ�� �̵��Ѵ� >> �ش���ǥ�� üũ�ϰ� >> cnt++ 
			int flag=0;
			for(int a=0; a<n; a++){
				for(int b=0; b<n; b++){
					if(a==nwx && b==nwy){
						//�����ڽ��̸� pass 
						continue;
					}else if(grp[a][b]==grp[nwx][nwy]){
						//�����̸鼭 �ڽİ� ��ȣ�� ������ �̵� 
						
//						printf("* ���� �̵�:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);
						
//�Ǽ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
						if(wei[a][b]==0){
							wei[a][b]=1;
							cnt++;								
						}//if-2 
						
						if(flag==0){
							nwx=a;
							nwy=b;
//							printf("*�������� �ٷ� ���� �̵�:(%d, %d) (%d, %d) cnt :%d  \n", nwx, nwy, gox, goy, cnt);							
							flag=1;
						}//if
						
						
					}//if-1
				}//for-b
			}//for-a
		}else if(grp[nwx][nwy]>=1 && grp[nwx][nwy]<=5){
			//��Ź� üũ�ϰ� >> �������� ����. 
			//������ �ٲ��ش�. 
//			printf("* %d ��ֹ� ����:(%d, %d) ���⺯����(%d, %d) cnt :%d  \n", grp[nwx][nwy], nwx, nwy, gox, goy, cnt);				
						
			if(grp[nwx][nwy]==1 && gox==1 && goy==0){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox	= 0;
				goy	= -1;
			}else if(grp[nwx][nwy]==1 && gox==0 && goy==1){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox	= -1;
				goy	= 0;
			}else if(grp[nwx][nwy]==2 && gox==1 && goy==0){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox	= 0;
				goy = 1;
			}else if(grp[nwx][nwy]==2 && gox==0 && goy==-1){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = -1;
				goy = 0;
			}else if(grp[nwx][nwy]==3 && gox==0 && goy==-1){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = 1;
				goy = 0;
			}else if(grp[nwx][nwy]==3 && gox==-1 && goy ==0){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = 0;
				goy = 1;
			}else if(grp[nwx][nwy]==4 && gox==0 && goy==1){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = 1;
				goy = 0;
			}else if(grp[nwx][nwy]==4 && gox==-1 && goy==0){
				if(wei[nwx][nwy]==0){
					wei[nwx][nwy]=1;
					cnt++;					
				}//if-2
				gox = 0;
				goy = -1;
			}else{
				if(wei[nwx][nwy]==0){//���ص��Ǵ°ǰ�? 
					wei[nwx][nwy]=1;						
				}//if-2
				gox=gox*-1;
				goy=goy*-1;				
			}//if-2			
//			printf("* %d ��ֹ� ����:(%d, %d) ���⺯����(%d, %d) cnt :%d  \n", grp[nwx][nwy], nwx, nwy, gox, goy, cnt);
		}//if-1 
		
		if(nwx==x && nwy==y && gox==dx[dir] && goy==dy[dir]){
			//����ġ�� ��ǥ�� ����
			//������ ���ٸ� ���� 
//			printf("*return home :: %d %d %d %d\n", nwx, nwy, gox, goy);
			return;
		}//if-1
	}//while	
}//go

int main(){
		
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		memset(grp, 0, sizeof(grp));
		memset(wei, 0, sizeof(wei));
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d", &grp[i][j]);
			}
		}
		
		int max=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(grp[i][j]==0){//��ֹ�, ���� �ƴϸ� Ž������. 
					for(int k=0; k<4; k++){//4���� ��� ���� ���Ѻ��� 
						memset(wei, 0, sizeof(wei));
						cnt=1;
						go(i, j, k);//x, y, dir
						if(cnt>max){
							max=cnt; 
						}//if
					}//for-k				
				}//if
			}//for-j
		}//for-i
	
	printf("#%d %d\n", tt, max);
	}//for-tt
	
	
	return 0;
}//main

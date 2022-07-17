#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
int dx[]={-1, 1,  0, 0}; // ��, �Ʒ�, ����, ������
int dy[]={ 0, 0, -1, 1};
struct shark{
	int num;	// ����� ��ȣ 1<=num<=m
	int sx;		// ����� ������ǥ 
	int sy;		// ����� ������ǥ
	int dir=0;	// ����� ���� ����
	int sdir[4][4]={{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0},
					{0,0,0,0}};	
};//shark 
int n, m, k;		// �׷����� ����, ����� ��, ������ ���� 
int grp[200][200][4];	// [0] : ������ ����� ��ȣ, [1] : ������ ����, [2] : ���� ����� ��ġ 
vector<shark> v1;

shark make_sh(int num, int sx, int sy){
	shark tmp;
	tmp.num=num;
	tmp.sx=sx;
	tmp.sy=sy;
	return tmp;
}//make_sh

int compare(shark s1, shark s2){
	// ����� ��ȣ�� ������������ �����Ѵ�. 
	if(s1.num<s2.num){
		return 1;
	}else{
		return 0;
	}//if
}//compare

void go(){
	if(v1.size()<=1) return; //��Ÿ�ӿ���
	// �� �ش�������� ���� ���Ѻ���
	// ������ �����ϴ� == grp[1]�� "��" �϶� 
	// ������ �����ϸ� ������Ű�� grp[0]�� ����� ��ȣ, grp[1]�� k ���� ���� 
	// ������ �ȵȴٸ� ���� �������� �̵��ϱ� && ���� ���� grp[1]�� k ����
	for(int i=0; i<v1.size(); i++){
		int td=v1[i].dir;// ����� ���� ���� ���� 
		int flag=0;// �����ϸ� 1, ���� ���ϸ� 0 
		for(int j=0; j<4; j++){
			int ndir=v1[i].sdir[td][j];	// �켱 ������ ���� ���� 
			int ntx=v1[i].sx+dx[ndir];	// �������� �����ϱ� 
			int nty=v1[i].sy+dy[ndir];
			if(ntx<0 || nty<0 || ntx>=n || nty>=n) {
//				printf("range1!\n");
				continue;
			}
			if(grp[ntx][nty][1]==0){
				// ���� �� �� �ִٸ� >> �����Ѵ� 
				// �����ϱ��� ���� ��ġ�� 0���� �ٲ۴� 
				grp[v1[i].sx][v1[i].sy][2]=0;
				flag=1;
				v1[i].sx=ntx;
				v1[i].sy=nty;
				v1[i].dir=ndir;
				
				if(grp[ntx][nty][0]!=0 &&
					grp[ntx][nty][0]>v1[i].num){
					//���!!!!!!! 
					grp[ntx][nty][0]=v1[i].num;	
				}else if(grp[ntx][nty][0]==0){
					grp[ntx][nty][0]=v1[i].num;	
				}//if
				grp[ntx][nty][2]=v1[i].num;
				break;// ���������� ������ ã�Ҵٸ� �����ϰ� Ż�� 
			}//if			
		}//for-j
		
		if(flag==0){ 
			// �������� ���ߴٸ� 
			// �Ʊ� �����ߴ� ������ ã�� ���ư��� 
			int td=v1[i].dir;// ����� ���� ���� ���� 
			for(int j=0; j<4; j++){
				int ndir=v1[i].sdir[td][j];	// �켱 ������ ���� ���� 
				int ntx=v1[i].sx+dx[ndir];	// �������� �����ϱ� 
				int nty=v1[i].sy+dy[ndir];
				if(ntx<0 || nty<0 || ntx>=n || nty>=n) {
//					printf("range2!\n");
					continue;
				}
				if(grp[ntx][nty][0]==v1[i].num){
					// �� �������� �����ϰ�
					// ������ ���⸦ k�� �ʱ�ȭ 
					grp[v1[i].sx][v1[i].sy][2]=0;//����!!!!!!!!!! 
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
	// ������ ���� ���� ���� ǥ�ø� �����ʾҴ� 
	// �浹�� ������ ã�Ƴ��� �����Ѵ�
	// ��������� ������ ���´�.
	if(v1.size()<=1) return; //��Ÿ�ӿ��� 
	for(int i=0; i<v1.size(); i++){
		for(int j=i+1; j<v1.size(); ){
			if(v1[i].sx==v1[j].sx &&
				v1[i].sy==v1[j].sy &&
				grp[i][j][1]==0){					
					if(v1.size()<=1) return; //��Ÿ�ӿ���
					v1.erase(v1.begin()+j);  // erase ���� ���� ã�� 
//					j--; 					
				}else{
					j++;
				}
		}//for-i
	}//for-i	
}//col

void vanish(){
	if(v1.size()<=1) return;//��Ÿ�ӿ���
	// �� �־����� ��ġ�� ������ ���⸦ 1�� ���δ�
	// 1) �� ��ġ�������鼭 && grp[i][j][1]==0�̸� k�� �ִ´�. >> �����Ѱ�� 
	// 2) �� ��ġ�������鼭 && grp[i][j][1]!=0�̸� k�� �ִ´�. >> ���ƿ°�� 
	//  ** �� ������(grp[i][j][2]!=0) >> grp[i][j][1]=k 
	// 3) �� ���� && grp[i][j][0]!=0 && grp[i][j][1]!=0 �̸� 1�� �����ϰ�
	//		������ ���� ���̸�(grp[i][j][1]==0)  >> grp[i][j][0]=0���� �ʱ�ȭ�ϱ� 	 
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
				// ��Ÿ�� ���� 
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
			if(grp[i][j][0]!=0){	//	�� �߰��ߴٸ� 
				grp[i][j][1]=k;		// 	�ش���ġ�� ����ǥ���ϱ� 
				grp[i][j][2]=grp[i][j][0];	//	����� ������ġ 
				v1.push_back(make_sh(grp[i][j][0], i, j));
			}//if
		}//for-j
	}//for-i
	sort(v1.begin(), v1.end(), compare); //�浹�Ҷ� ��ȣ������ ��Ƴ����ϱ����ؼ� 
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
		vanish(); // ���� 
		go();	
		col();		
		if(v1.size()<=1){ //��Ÿ�ӿ���!!!!!!!! 
			break;
		}//if
	}//for-i
	/////////////////////////////////////////////////////
	if(time>=1000){ //����? 
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
//		printf("%d ��° ����� �켱����\n", v1[i].num);
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
//		printf("%d ��° ����� �켱����:: ����: %d \n", v1[i].num,v1[i].dir);
//		for(int j=0; j<4; j++){
//			printf("%d %d %d %d\n", v1[i].sdir[j][0], 
//									v1[i].sdir[j][1],
//									v1[i].sdir[j][2], 
//									v1[i].sdir[j][3]);
//		}//for-k		
//		printf("\n");
//	}//for-i










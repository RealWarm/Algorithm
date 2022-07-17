#include<iostream> 
#include<algorithm>
#include<cstring>
#include<vector> 
#include<cmath>
#include<tuple>
using namespace std;
//���±��� x�� ����, y�� ���η� �ؿ��� 
//���⼱ >> y : ����, x : ����
//���ڸ�, ��, ������, �Ʒ�, ����
int dx[]={0, -1, 0, 1, 0};//���ڸ�, ����, ������, �Ʒ���, ���� 
int dy[]={0, 0, 1, 0, -1};
int grp[20][20][7];
int n, m, k; // ���� ���� �������� ���� 
int s; //�̵����� 
int ax, ay, ad, bx, by, bd; // y:����, x:���� 
int adir[111]; //�ð��� �̵� ����� �����ϴ� �迭 
int bdir[111];
struct aps{
	int y;
	int x;
	int r;
	int d;
};
vector<aps> v1;//ap�� ��ǥ���� �����Ѵ�. 

void make(int y, int x, int r, int d, int z){	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int dis = abs(y-i) + abs(x-j); //$$$$$$ 
				if(dis <= r){//���� ���̴�? 
					grp[i][j][z]=d;					
				}//if
		}//for-j
	}//fori			
}//make
///////////////////��������////////////////////////////////////////////////////////////// 
int compAp(int y, int x, int ds){
	// �Լ��� ���� :: �ش� ��ǥ�� ���ԵǸ鼭, ���Ⱑ d�� ap�� ��ȣ�� ��ȯ�Ѵ�. 
	// d������ ap�� ��ǥ�� ��ȯ�Ѵ�.
	// ���� ap�� ������ ���Եǰ� ���Ⱑ d��� �� ap�� ��ȣ�� ��ȯ�Ѵ�.	
	for(int i=0; i<v1.size(); i++){
		if(v1[i].d == ds){//���Ⱑ ����
			int dis = abs(y-v1[i].y)+abs(x-v1[i].x);
			if(dis<=v1[i].r){
				//������ǥ�� �������� ���ԵǸ� �ش� ap�� ��ǥ�� ����Ѵ�.
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
	//a�� ���� ���길
	if(grp[ay][ax][0]>0){
		//ap ������ �ִٸ� 
		if(grp[ay][ax][0]!=grp[by][bx][0]){
			//a�� b�� �ٸ� ������ ap ������ �ִ�? 
			ad-=grp[ay][ax][0];
///////////////////��������////////////////////////////////////////////////////////////// 
		}else if(grp[ay][ax][0] == grp[by][bx][0] &&
			 compAp(ay, ax, grp[ay][ax][0]) != compAp(by, bx, grp[ay][ax][0])){		 
//			 printf("a: in here||||| %d %d \n", grp[ay][ax][0], compAp(ay, ax, grp[ay][ax][0]));
			// ���Ⱑ ������ �ٸ� �������� ���. 
			// �ش�Ǵ� ap�� ��ȣ�� ���ؼ� �ٸ��� ������ ����� ����. 
			ad-=grp[ay][ax][0];
		}else{
///////////////////////////////////////////////////////////////////////////////////////						
			//a�� b�� ���� ap�� ������ �ִ�. 
			if(grp[ay][ax][1]>0 && grp[by][bx][1]==0){
				//a�� �ٸ�ap�� �����Ҽ� ������
				//b�� ���� ���								
				ad-=grp[ay][ax][1];
			}else if(grp[ay][ax][1]==0 && grp[by][bx][1]>0){
				//b�� �ٸ� ap�� ���� �Ҽ� ������
				//a�� ���� ��� 
				ad-=grp[ay][ax][0];
			}else if(grp[ay][ax][1]==0 && grp[by][bx][1]==0){
				//a�� b ��� �ٸ� ������ �� �� ���� ��� 
				ad-=(grp[ay][ax][0]/2);
				
			}else if(grp[ay][ax][1]>0 && grp[by][bx][1]>0){
				//a�� b ��� �ٸ� ������ �� �� �ִ� ��� 
				//�ٿ�ε� �뷮 ���� �ִ밡 �ǵ��� �����Ѵ�. 
				//�����Ҽ� �ִ� ap�� ũ�Ⱑ ū���� �����Ѵ�.				 
				if(grp[ay][ax][1]>grp[by][bx][1]){
					ad-=grp[ay][ax][1];
				}else if(grp[ay][ax][1]<grp[by][bx][1]){
					ad-=grp[ay][ax][0];
				}else if(grp[ay][ax][1]==grp[by][bx][1]){
					//���ð����� ap�� ���Ⱒ ���ٸ� 
					//�ٿ�ε带 ������ �ؾ��ϴ� �����
					//���� �ӵ��� ap�� �����ϵ��� �����Ѵ�. 
					if(tempA>=tempB){
						ad-=grp[ay][ax][0];
					}else{
						ad-=grp[ay][ax][1];
					}//if-5
				}//if-4
			}//if-3
		}//if-2
	}//if-1
	
	//b�� ���� ���길 
	if(grp[by][bx][0]>0){
		//������ġ�� ap�� ������? 
		if(grp[ay][ax][0]!=grp[by][bx][0]){
			//a�� b�� �ٸ� ap�� ������ �ִ�? 
			bd-=grp[by][bx][0];
///////////////////��������////////////////////////////////////////////////////////////// 
		}else if(grp[ay][ax][0] == grp[by][bx][0] &&
			 compAp(ay, ax, grp[ay][ax][0]) != compAp(by, bx, grp[ay][ax][0]) ){		 			
			// ���Ⱑ ������ �ٸ� �������� ���. 
			// �ش�Ǵ� ap�� ��ȣ�� ���ؼ� �ٸ��� ������ ����� ����. 
//			printf("b: in here ||||| %d %d \n", grp[by][bx][0], compAp(by, bx, grp[by][bx][0]));
			bd-=grp[by][bx][0];
///////////////////////////////////////////////////////////////////////////////////////									
		}else{
			//a�� b�� ���� ap�� ������ �ִ�. 
			if(grp[ay][ax][1]>0 && grp[by][bx][1]==0){
				//a�� �ٸ�ap�� �����Ҽ� ������
				//b�� ���� ���									
				bd-=grp[by][bx][0];
			}else if(grp[ay][ax][1]==0 && grp[by][bx][1]>0){
				//b�� �ٸ� ap�� �����Ҽ� ������
				//a�� ���� ���	
				bd-=grp[by][bx][1];
			}else if(grp[ay][ax][1]==0 && grp[by][bx][1]==0){
				//a�� b ��� �ٸ� ������ �� �� ���� ��� 
				bd-=(grp[by][bx][0]/2);
			}else if(grp[ay][ax][1]>0 && grp[by][bx][1]>0){
				if(grp[ay][ax][1]>grp[by][bx][1]){
					bd-=grp[by][bx][0];
				}else if(grp[ay][ax][1]<grp[by][bx][1]){
					bd-=grp[by][bx][1];
				}else if(grp[ay][ax][1]==grp[by][bx][1]){
					//���ð����� ap�� ���Ⱒ ���ٸ� 
					//�ٿ�ε带 ������ �ؾ��ϴ� �����
					//���� �ӵ��� ap�� �����ϵ��� �����Ѵ�.
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
		scanf("%d %d %d", &n, &m, &k);//��ǥ, �����ⰹ��
		for(int i=0; i<k; i++){
			int y, x, r, d;//�������� ��ǥ, ����, �ٿ�ӵ� 
			scanf("%d %d %d %d", &y, &x, &r, &d);
			y--; x--; // ��ǥ�� (1,1)���� �����ϴ� ���� (0,0)�� �ٲ۴�.
			v1.push_back({y, x, r, d});
			make(y, x, r, d, i);
		}//for-i
				
		//���������� ���⺰�� ��迭�Ѵ�. 
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				sort(grp[i][j], grp[i][j]+7, greater<int>());//�������� 
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
		//���⼭ �Ǽ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		scanf("%d %d %d", &ay, &ax, &ad); ax--; ay--;// ��ǥ�� (1,1)���� �����ϴ� ���� (0,0)�� �ٲ۴�.
		scanf("%d %d %d", &by, &bx, &bd); bx--; by--;// ��ǥ�� (1,1)���� �����ϴ� ���� (0,0)�� �ٲ۴�.
		///////////////////////////////////////////////////////////////	
		for(int i=0; i<=s; i++){
			//A�� B�� ���� ��ġ�� �������� ��ġ�� �� �� ������, 
			//���� ���� �������� �������� �ִ�. �������� ���� ������ ���� ���ζ�� 
			//�̵� ���۰� ���ÿ� ������ �뷮��ŭ �ٿ�ε带 ���� �� �ִ�.
			//ó�� ������ ��ġ���� �Ǻ��� �ϱ����ؼ�				
			go(i);		 
			//���⼭ �Ǽ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			ax+=dy[adir[i]];
			ay+=dx[adir[i]];
			bx+=dy[bdir[i]];
			by+=dx[bdir[i]];
		}//for-i
		
		if(ad<0) ad=0;
		if(bd<0) bd=0;
		
		printf("#%d %d %d\n", ts, ad, bd);
		///////////////////////////////////////////////////////////////	
	//	//�������� �迭�� ����� ��µǴ���
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

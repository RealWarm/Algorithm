#include<iostream> 
#include<algorithm>
#include<cstring>
#include<vector> 
#include<cmath>
#include<tuple>
using namespace std;
int dx[]={0, -1, 0, 1, 0};//���ڸ�, ����, ������, �Ʒ���, ���� 
int dy[]={0, 0, 1, 0, -1};
int n, m, k; // ���� ���� �������� ���� 
int s; //�̵����� 
int ax, ay, ad, bx, by, bd; // y:����, x:���� 
int adir[111]; //�ð��� �̵� ����� �����ϴ� �迭 
int bdir[111];

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
	}//for-ts
	
	
	return 0;
}//main

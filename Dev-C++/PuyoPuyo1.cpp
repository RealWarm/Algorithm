#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<string> grp(12);
int wei[12][6];
int n=12, m=6;	// ���� ���� 
int cnt;
int total;

void dfs(int x, int y, int gr, char ch){
	wei[x][y]=gr;
	cnt++;
	for(int k=0; k<4; k++){
		int ntx=x+dx[k];
		int nty=y+dy[k];
		if(ntx<0 || ntx<0 || ntx>=n || nty>=m) continue;
		if(wei[ntx][nty]==0 && grp[ntx][nty]==ch){
			wei[ntx][nty]==gr;
			dfs(ntx, nty, gr, ch);
		}//if
	}//for-k	
}//dfs


int main(){
	for(int i=0; i<12; i++){
		getline(cin, grp[i]);
	}//for-i
	///////////////////////////////////////////////
	// �Ͷ߸��� 
	int time=0; 
	while(1){		
		memset(wei, 0, sizeof(wei));
		int flag=0;
		int clr=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(wei[i][j]==0 && grp[i][j]!='.'){
					cnt=0;
					dfs(i, j, ++clr, grp[i][j]);
					if(cnt>=4){						
						if(flag==0){
							flag=1;
							total++;
						}//if
						for(int a=0; a<n; a++){
							for(int b=0; b<m; b++){
								if(wei[a][b]==clr){
									grp[a][b]='.';
								}//if
							}//for-b
						}//for-a
					}//if
				}//if
			}//for-j
		}//for-i		
		if(flag==0){
			break;	
		}//if
		///////////////////////////////////////////////////////////
		// ������ 
		while(1){
			int flag1=0;
			for(int a=11; a>=1; a--){
				for(int b=0; b<6; b++){
					if(grp[a][b]=='.' && grp[a-1][b]!='.'){
						flag1=1;
						grp[a][b]=grp[a-1][b];
						grp[a-1][b]='.';
					}//if
				}//for-b
			}//for-a
			
			if(flag1==0){
				break;
			}//if
		}//while
		///////////////////////////////////////////////////////////		
//		for(int i=0; i<12; i++){
//			cout << grp[i] << endl;
//		}//for-i
		
	}//while
//	printf("-----------------------\n");
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			printf("%d ", wei[i][j]);
//		}//for-j
//		printf("\n");
//	}//for-i
//	
//	printf("-----------------------\n");
//	for(int i=0; i<12; i++){
//		cout << grp[i] << endl;
//	}//for-i

	printf("%d\n", total);
	
	return 0;
}//main

//	printf("-----------------------\n");
//	for(int i=0; i<12; i++){
//		cout << v1[i] << endl;
//	}//for-i

// �ѿ並 ���� �� ��, ���� �� �ѿ䰡 4�� �̻� 
// �����¿�� ����Ǿ� ������ ����� ���� �� �ѿ���� �Ѳ����� ��������.

// ���� �� �ִ� �ѿ䰡 ���� �׷��� �ִٸ� ���ÿ� ������ �ϰ� 
// ���� �׷��� �������� �ѹ��� ���Ⱑ �߰��ȴ�.

#include<iostream>
#include<cstring>
#include<vector>
#include<cmath> 
using namespace std;
vector<int> arr[15];
int anum[15];
int wei[15];
int ans[15];
int n, t, cnt, mmin=999999999;

void dfs(int x, int c){
	wei[x]=1;
	cnt++;	
	for(int i=0; i<arr[x].size(); i++){
		int ntx = arr[x][i];
		if(wei[ntx]==0 && ans[ntx]==c){			
			dfs(ntx, c);
		}//if
	}//for-i	
}//bfs

int check(int gnum, int snum){//�׷��ȣ, �׷��� 
	for(int i=0; i<n; i++){
		if(ans[i]==gnum){
			dfs(i, ans[i]);			
			if(cnt < snum){
				return 0;
			}//if-2	
			break;	
		}//if-1					
	}//for-i	
	return 1;
}//check

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int aa, bb; scanf("%d %d", &aa, &bb);
		anum[i]=aa;
		for(int i=0; i<bb; i++){
			char ttmp; scanf(" %c", &ttmp);
			arr[i].push_back(ttmp-'A');
			arr[ttmp-'A'].push_back(i);
		}//for-i
	}//for-i
	
	// �׷��� ���� >> �ش� �׽�Ʈ ��ȣ��ŭ ���� >> �׽�Ʈ���� �Է¹ޱ� ����
	// wei, ans, cnt �ʱ�ȭ 
	// ans �迭�� ���õ� �ο��� üũ�ѵ�. 
	// �׷��� 1�� �ο��� �������� Ȯ��.
	// wei, cnt �ʱ�ȭ 
	// �׷��� 0�� �ο��� �������� Ȯ��.
	// ��� ��������� �׷캰 �հ踦 �� �ѵڿ� �ּҰ��� ��. 
	int tnum=0;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		cnt=0;		
		memset(ans, 0, sizeof(ans));
		memset(wei, 0, sizeof(wei));
		int num; scanf("%d", &num);
		for(int i=0; i<num; i++){
			char ch; scanf(" %c", &ch);
			ans[ch-'A']=1;
		}//for-i
		
		if(check(1, num)==1){
			cnt=0;
			memset(wei, 0, sizeof(wei));
			if(check(0, n-num)==1){
				tnum++;
				
				int at=0, st=0;
				for(int i=0; i<num; i++){
					if(wei[i]==0){
						at+=anum[i];
					}else{
						st+=anum[i];
					}
				}//for-i
				
				int result=abs(at-st);
				printf("%d || at : %d || st : %d || result : %d \n", i , at, st, result);
				if(mmin>result){
//					printf("%d || at : %d || st : %d || result : %d \n", i , at, st, result);
					mmin=result;					
				}
			}//if-2	
		}//if-1
		
	}//for-i
	
	if(tnum==0){
		printf("-1\n");
	}else{
		printf("%d\n", mmin);
	}
	
	return 0;
}//main

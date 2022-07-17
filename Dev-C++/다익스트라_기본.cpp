#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX=100;
vector<int> graph[MAX];
vector<int> cost[MAX];
int n, m, start, eend;
int table[MAX];
int check[MAX]; 
// check[i] = 1 �̸� �ִܰŸ��� Ȯ���Ǿ���. 
// check[i] = 0 �̸� ���� �ִܰŸ��� Ȯ������ �ʾҴ�.  
 
int main(){
	scanf("%d %d %d %d", &n, &m, &start, &eend);
	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		// a --- (c) --> b
		graph[a].push_back(b);
		graph[b].push_back(a);
		
		cost[a].push_back(c);
		cost[b].push_back(c);		
	}//for-i
	
	for(int i=0; i<n; i++){
		table[i]=987987987;
	}	
	table[start]=0;
	////////////////////////////////////////////////////////////////////////	
	for(int i=0; i<n; i++){
		// (1) �ּڰ��� ���Ѵ�. ��, ���ݱ��� �ִܰŸ��� Ȯ������ �ʾҴ� ������ ���ؼ� 
		// (2) �� �ּڰ��� ���� ���� ���� �������. 
		int mmin=987987, mininx=-1;
		for(int j=0; j<n; j++){
			if(check[j]==0 && mmin>table[j]){
				// �ִܰŸ��� Ȯ�������� �����鼭				
				mmin=table[j];
				mininx=j;
			}//if			
		}//for-j
		
		check[mininx]=1;
		
		for(int j=0; j<graph[mininx].size(); j++){
			int node2 = graph[mininx][j];
			int cost2 = cost[mininx][j]; 
			
			// mininx --- (cost2) --- node
			if(table[node2]>table[mininx]+cost2){
				table[node2]=table[mininx]+cost2;
			}//if					
			
		}//for-j		
				
	}//for-i 
	
	for(int i=0; i<n; i++){
		//���������� ��� ���������� �ִܰŸ� 
		printf("%d ", table[i]);
	}//for-i
	
	
	return 0;
}//main


// �Է�
// ��������, ��������, ������, ���� 
// ������, ����, ����ġ 
//8 11 0 6
//0 1 3
//0 5 1
//1 2 4
//1 3 1
//1 5 1
//2 4 6
//2 6 9
//2 7 4
//3 4 2
//4 6 9
//6 7 3
//
//13


// T[i] : ���� i�� �����ϴµ� �ɸ��� �ִܰŸ�
// (1) T[i] �� �ּڰ��� ���Ѵ�. ��, ���ݱ��� �ּڰ����� ������ �ʾҴ� �͵� ��.
// (2) index�κ��� �������. T[index] + cost 







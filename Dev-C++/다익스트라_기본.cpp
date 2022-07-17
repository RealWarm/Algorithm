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
// check[i] = 1 이면 최단거리가 확정되었다. 
// check[i] = 0 이면 아직 최단거리가 확정되지 않았다.  
 
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
		// (1) 최솟값을 구한다. 단, 지금까지 최단거리롤 확정되지 않았던 정점에 대해서 
		// (2) 그 최솟값을 갖는 노드로 부터 뻗어나간다. 
		int mmin=987987, mininx=-1;
		for(int j=0; j<n; j++){
			if(check[j]==0 && mmin>table[j]){
				// 최단거리로 확정된적이 없으면서				
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
		//시작점에서 모든 정점까지의 최단거리 
		printf("%d ", table[i]);
	}//for-i
	
	
	return 0;
}//main


// 입력
// 정점갯수, 간선갯수, 시작점, 끝점 
// 시작점, 끝점, 가중치 
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


// T[i] : 정점 i에 도달하는데 걸리는 최단거리
// (1) T[i] 중 최솟값을 정한다. 단, 지금까지 최솟값으로 뽑히지 않았던 것들 중.
// (2) index로부터 뻗어나간다. T[index] + cost 







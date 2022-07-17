#include<iostream>
#include<algorithm> 
#include<vector> 
using namespace std;
struct edge{
	// 하나의 간선을 담는 변수 
	int p; 	// 시작점 
	int q;	// 끝점 
	int c;	// 가중치 
}; 
int n, m; // 정점 갯수, 간선 갯수 
int result;
vector<edge> el;
int par[100010]; // par[x] : x의 부모노드의 번호 

int comp(edge e1, edge e2){
	// 간선 가중치를 기준으로 오름차순 정렬한다. 
	if(e1.c<e2.c){
		return 1;
	}else if(e1.c==e2.c){
		if(e1.p<=e2.p) return 1;
		else return 0;
	}else{
		return 0;
	}//if
		
}//comp

edge make_ed(int p, int q, int c){
	edge e;
	e.p=p;
	e.q=q;
	e.c=c;
	return e;
}//make_ed

int find(int x){
	// 부모노드를 반환한다 >> 재귀호출 
	// 1) 내가 루트노트이니?
	if(x==par[x]){
		//내가 루트노트이면 
		return x; 
	}else{
		int y=find(par[x]); // 내부모의 루트를 찾아라 
		par[x]=y;// 내 부모를 루트로 바꾸겠다. 
		return y; 
	}//if
	
}//find 

int Union(int a, int b){
	// a와 b가 같은 그룹인지를 판단
	// 만약 같은 그룹이라면, 0를 반환
	// 같은 그룹이 아니라면, a와 b를 같은 그룹으로 만들고 1을 반환
	int rootA=find(a);
	int rootB=find(b);
	
	if(rootA==rootB) return 0;
	else{
		par[rootA]=rootB;
		return 1;
	}//if
	 
}//Union

int main(){
	
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		par[i]=i; // 내가 루트노드이다.		
	}//for-i
	for(int i=0; i<m; i++){
		int a, b, c; scanf("%d %d %d", &a, &b, &c);		
		el.push_back(make_ed(a, b, c));
	}//for-i
	///////////////////////////////////////////////////
	sort(el.begin(), el.end(), comp);
	///////////////////////////////////////////////////
	for(int i=0; i<m; i++){
		// el[i]의 간선을 선택하려고 시도할 것임 
		// 가중치가 작은 순서대로 간선을 선택한다
		if(Union(el[i].p, el[i].q)){// 만약 시작점과 끝점이 다른 그룹에 있다면 			
			// 총 가중치에 간선의 가중치를 더한다
			// 시작점과 끝점을 같은 그룹으로 묶는다
			result+=el[i].c;			
		}//if 
	}//for-i
	///////////////////////////////////////////////////
	printf("%d\n", result);
	///////////////////////////////////////////////////
	return 0;
}//main

// 정점의 갯수, 간선의수
// 시작점, 끝점, 가중치
// 8 11
// 1 2 1
// 1 3 2
// 2 3 3
// 2 4 4
// 4 5 1
// 4 6 2
// 5 6 2
// 5 8 2
// 6 7 3
// 7 8 4
// 3 6 2
// 
// 15 간선 가중치가 가장 작은 가중치를 선택했을때의 총가중치합 





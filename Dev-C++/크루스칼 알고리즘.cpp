#include<iostream>
#include<algorithm> 
#include<vector> 
using namespace std;
struct edge{
	// �ϳ��� ������ ��� ���� 
	int p; 	// ������ 
	int q;	// ���� 
	int c;	// ����ġ 
}; 
int n, m; // ���� ����, ���� ���� 
int result;
vector<edge> el;
int par[100010]; // par[x] : x�� �θ����� ��ȣ 

int comp(edge e1, edge e2){
	// ���� ����ġ�� �������� �������� �����Ѵ�. 
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
	// �θ��带 ��ȯ�Ѵ� >> ���ȣ�� 
	// 1) ���� ��Ʈ��Ʈ�̴�?
	if(x==par[x]){
		//���� ��Ʈ��Ʈ�̸� 
		return x; 
	}else{
		int y=find(par[x]); // ���θ��� ��Ʈ�� ã�ƶ� 
		par[x]=y;// �� �θ� ��Ʈ�� �ٲٰڴ�. 
		return y; 
	}//if
	
}//find 

int Union(int a, int b){
	// a�� b�� ���� �׷������� �Ǵ�
	// ���� ���� �׷��̶��, 0�� ��ȯ
	// ���� �׷��� �ƴ϶��, a�� b�� ���� �׷����� ����� 1�� ��ȯ
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
		par[i]=i; // ���� ��Ʈ����̴�.		
	}//for-i
	for(int i=0; i<m; i++){
		int a, b, c; scanf("%d %d %d", &a, &b, &c);		
		el.push_back(make_ed(a, b, c));
	}//for-i
	///////////////////////////////////////////////////
	sort(el.begin(), el.end(), comp);
	///////////////////////////////////////////////////
	for(int i=0; i<m; i++){
		// el[i]�� ������ �����Ϸ��� �õ��� ���� 
		// ����ġ�� ���� ������� ������ �����Ѵ�
		if(Union(el[i].p, el[i].q)){// ���� �������� ������ �ٸ� �׷쿡 �ִٸ� 			
			// �� ����ġ�� ������ ����ġ�� ���Ѵ�
			// �������� ������ ���� �׷����� ���´�
			result+=el[i].c;			
		}//if 
	}//for-i
	///////////////////////////////////////////////////
	printf("%d\n", result);
	///////////////////////////////////////////////////
	return 0;
}//main

// ������ ����, �����Ǽ�
// ������, ����, ����ġ
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
// 15 ���� ����ġ�� ���� ���� ����ġ�� ������������ �Ѱ���ġ�� 





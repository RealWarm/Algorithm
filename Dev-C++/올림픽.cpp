#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, k; // ������ �� N, ����� �˰� ���� ���� K
struct sc{
	int n;
	int g;
	int s;
	int b;
};

bool compare(sc c1, sc c2){
	// �������� 
	if(c1.g > c2.g){
		return true;
	}else if(c1.g==c2.g){
		if(c1.s>c2.s){
			return true;
		}else if(c1.s == c2.s){
			if(c1.b>c1.b){
				return true;
			}else if(c1.b==c2.b){
				return c1.n==k;
			}//if-3
		}//if-2
	}//if-1
	return false;
}//compare

//int compare(sc c1, sc c2){
//    if (c1.g != c2.g)
//        return c1.g > c2.g;
//    if (c1.s != c2.s)
//        return c1.s > c2.s;
//    if (c1.b != c2.b)
//        return c1.b > c2.b;
//}//compare

int main(){
	scanf("%d %d", &n, &k);
	vector<sc> v1(n);
	for(int i=0; i<n; i++){
		scanf("%d %d %d %d", &v1[i].n, &v1[i].g, &v1[i].s, &v1[i].b);
	}//for-i
	///////////////////////////////////////////////////////
	sort(v1.begin(), v1.end(), compare);
//	printf("------------------------------\n");
//	for(int i=0; i<v1.size(); i++){
//		printf("%d %d %d %d\n", v1[i].n, v1[i].g, v1[i].s, v1[i].b);
//	}//for-i

	for(int i=0; i<v1.size(); i++){
		if(v1[i].n==k){
			printf("%d\n", i+1);
			break;
		}//if
	}//for-i
	
	return 0;
}//main

// ����
// ������������ �����Ѵ�. >>  

// 1. pair<pair<int, int>, pair<int, int>>�� �迭�� �����Ͽ� ������ȣ, ��, ��, �� ������ �Է¹޽��ϴ�.
// 2. ���� ������ ���� cmp �Լ��� �ۼ��ϴµ� �Ʒ��� ���� �ۼ��մϴ�.
// i) ���� �������� �������� ����
// ii) ���� ���� �� ���� �������� �������� ����
// iii) ��, ���� ���� �� ���� �������� �������� ����
// iv) ��, ��, ���� ���� �� K��° ���� ���� �տ� ������
// 3. �迭�� Ž���ϸ鼭 ������ȣ�� K��°�� ������ �ε����� ������ָ� �˴ϴ�.




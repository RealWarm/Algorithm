#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, k; // 국가의 수 N, 등수를 알고 싶은 국가 K
struct sc{
	int n;
	int g;
	int s;
	int b;
};

bool compare(sc c1, sc c2){
	// 내림차순 
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

// 설계
// 내림차순으로 나열한다. >>  

// 1. pair<pair<int, int>, pair<int, int>>형 배열을 선언하여 국가번호, 금, 은, 동 순으로 입력받습니다.
// 2. 정렬 조건을 위해 cmp 함수를 작성하는데 아래와 같이 작성합니다.
// i) 금을 기준으로 내림차순 정렬
// ii) 금이 같을 때 은을 기준으로 내림차순 정렬
// iii) 금, 은이 같을 때 동을 기준으로 내림차순 정렬
// iv) 금, 은, 동이 같을 때 K번째 나라가 제일 앞에 오도록
// 3. 배열을 탐색하면서 국가번호가 K번째인 나라의 인덱스를 출력해주면 됩니다.




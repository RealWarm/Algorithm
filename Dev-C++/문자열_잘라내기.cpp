#include <iostream>
#include <vector>
#include <string>
#include <set> 
using namespace std;
vector<string> grp;
int r, c; // 세로 가로 

int check(int m){
	// grp의 열의 번호가 m ~ end를 문자로 만들었을때 
	// 중복이 있다면 "0"반환, 중복이 없다면 "1" 반환
	set<string> stk;
	for(int i=0; i<c; i++){
		string str;
		for(int j=0; j<r; j++){
			str+=grp[j][i];
		}//for-j
		stk.insert(str);
	}//for-i
	printf("Mid == %d \n");
	for(auto it=stk.begin(); it!=stk.end(); it++){
		cout << *it << " ";
	}//for-it
	printf("\n");
	if(stk.size()==c){
		return 1;
	}else{
		return 0;
	}//if
	
}//check

int main(){
	
	scanf(" %d %d", &r, &c);
	vector<int> wei(r);
	grp.resize(r);
	for(int i=0; i<r; i++){
		cin >> grp[i];
	}//for-i
	///////////////////////////
	int start=0, end=r; // 중복이 없는 경우, 중복이 있는 경우 
	while(start+1 < end){
		int mid=(start+end)/2;
		int result=check(mid);
		wei[mid]=result;
		if(result==1){
			// 중복이 없다면
			start=mid; 
		}else if(result==0){
			end=mid;
		}//if
	}//while
	for(int i=0; i<r; i++){
		printf("%d ", wei[i]);
	}//for-i
	printf("\n");
	printf("%d\n", start-1);
	return 0;
}//main

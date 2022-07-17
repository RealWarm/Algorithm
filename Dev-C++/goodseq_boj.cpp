#include <iostream>
#include <string>
using namespace std;
int N;
string num;
void permutation(char c, int cnt){
    //조건 만족(제일 먼저 나오는 숫자가 제일 작은 수)
    if (cnt - 1 == N){
		cout << num << "\n";
		exit(0);
    }
    num += c;
    for (int i = 1; i <= cnt / 2; i++){
		string a = num.substr(cnt - i, i);	
		string b = num.substr(cnt - i * 2, i);	
		//나쁜 수열
		
		if (a == b){	
			num.erase(cnt - 1);
			return;	
		}//if
    }//for-i
    for (int i = 1; i <= 3; i++){
    	permutation(i + '0', cnt + 1);
	}//for-i
	num.erase(cnt - 1); //cnt - 1 자리가 성립하지 않을 경우
}//permutation

int main(void){
	cin >> N; 
	for (int i = 1; i <= 3; i++){
		permutation(i + '0', 1);
	}//for-i
	return 0;
}//main

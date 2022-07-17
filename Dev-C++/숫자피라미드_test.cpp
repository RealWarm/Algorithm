#include<iostream>
using namespace std;

int main() {
	int n, s; cin >> n >> s;

	int layercnt = 1;
	for (int i = 1; i <= n; i++) {

		int bl = i;
		while (n - bl != 0) {
			cout << " ";
			bl++;
		}//while

		if (i % 2 != 0) {// 홀수는 오른쪽에서 왼쪽으로 1씩 증가. 			
			for (int t = 0; t < layercnt; t++) {
				if (s == 0) {
					s = 9;
				}//if
				if (t < layercnt - 1) {
					cout << s--;
				}
			}//for-t			
			s += 1;
			layercnt += 2;
		}else if (i % 2 == 0) {//짝수는 왼쫑에서 오른쪽으로 1씩 증가. 			
			for (int t = 0; t < layercnt; t++) {
				if (s == 10) {
					s = 1;
				}
				if (t < layercnt - 1) {
					cout << s++;
				}
			}//for-t
			layercnt += 2;
			for (int t = 0; t < layercnt; t++) {
				s++;
				if (s == 10 || s == 0) {
					s = 1;
				}				
			}//for-t
		}//if-else

		cout << endl;

	}//for-i
	return 0;
}

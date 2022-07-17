#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
///////주사위 게임 
int main() {

	int num; cin >> num;
	vector<vector<int> > a(num, vector<int>(3, 0));
	int maxValue = 0;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}//for-j
	}//for-i

	for (int i = 0; i < num; i++) {
		int nowSum = 0;
		int nowCnt = 1;
		sort(a[i].begin(), a[i].end());
		for (int j = 0; j <=1; j++) {
			if (a[i][j] == a[i][j + 1]) nowCnt++;
		}//for-j

		if (nowCnt == 1) {
			nowSum = a[i][2]*100;
		}
		else if (nowCnt == 2) {
			nowSum = 1000 + a[i][1]*100;
		}
		else if (nowCnt == 3) {
			nowSum = 10000 + a[i][1] * 1000;
		}

		maxValue = max(nowSum, maxValue);
	}//for-i

	cout << maxValue;

	return 0;
}

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main() {

	string str, ans; cin >> str;

	int cnt = 1;
	for (int i = 0; i < str.length(); i++) {
		
		if (str[i] == str[i + 1]) {
			cnt++;
		}else if(str[i] != str[i+1]){			
			if (cnt != 1) {
				ans += to_string(cnt);
			}
			ans += str[i];
			cnt = 1;
		}//if-else

	}//for-i

	cout << ans;

	return 0;
}

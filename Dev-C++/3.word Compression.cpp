#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string compressWord(string word, int K) {

    string temp = word;

    for (int t = 0; t < word.size(); t++) {
        int cnt = 1;
        for (int i = 0; i < temp.size(); i++) {
            for (int j = i + 1; j < temp.size(); j++) {
                if (temp[i] == temp[j]) {
                    cnt++;
                }
                else if (temp[i] != temp[j]) {
                    break;
                }
            }//for-j
            if (cnt >= K) {
                temp.erase(i, K);
            }//if                
        }//for-i

        if (temp.size() < K) {
            break;
        }//if

        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == temp[i + 1]) {
                return temp;
            }
            else {
                i += 1;
            }
        }//

    }//while

    return temp;

}//compressWord

int main() {

    string word;
    int K;
    cin >> word;
    cin >> K;
    cout << compressWord(word, K);

    return 0;
}//main

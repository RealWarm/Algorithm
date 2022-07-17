#include <string>
#include <vector>
#include <algorithm>
#include <iostream> 
using namespace std;

vector<int> solution(vector<int> ar, 
                     vector<vector<int>> ch) {    
    vector<int> ans;
    for(int i=0; i<ch.size(); i++){
        vector<int> tmp;
        //  i��° ���ں��� j��° ���ڱ��� �ڸ���
        for(int a=ch[i][0]-1; a<ch[i][1]; a++){
            tmp.push_back(ar[a]);
        }//for-a
            
        // ����
        sort(tmp.begin(), tmp.end());
            
        // k��°�� �ִ� ���� ���ϱ�
        ans.push_back(tmp[ch[i][2]-1]);
    }//for-i
    
    return ans;
}//solution

int main(){
	vector<int> ar1{1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> ch1{{2, 5, 3}, 
							{4, 4, 1}, 
							{1, 7, 3}};
	for(auto n : solution(ar1, ch1)){
		cout << n << " ";
	}
	return 0;
}//main

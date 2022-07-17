#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(const pair<float, int> a, 
			const pair<float, int> b){
	if (a.first == b.first ) return a.second < b.second;
    return a.first > b.first;
}//cmp

vector<int> solution(int n, vector<int> st) {
    // ��ü ���������� ���� N,
    // ������ �̿��ϴ� ����ڰ� ���� �����ִ� ���������� ��ȣ�� ��� �迭
    vector<int> ans;
    vector<pair<float, int> > v1;
    
    for(int i=1; i<=n; i++){
        int son=0, par=0;
        for(int j=0; j<st.size(); j++){            
            if(st[j]>=i){
                par++;
            }
            if(st[j]==i){
                son++;
            }
        }//for-j
        
        if(par==0){
        	v1.push_back(make_pair(0, i));
		}else{
			float tt=(float)son/(float)par;
    		v1.push_back(make_pair(tt, i));
		}//if
        
    }//for-i
    
    sort(v1.begin(), v1.end(), cmp);
    for(int i=0; i<v1.size(); i++){
       ans.push_back(v1[i].second);
    }//for-i
    
    return ans;
}//solution

// ||   ������
// ||   ���������� ���������� ���� Ŭ�������� ���� �÷��̾��� �� 
// ||   / ���������� ������ �÷��̾� ��

int main(){
	int n=5;
	vector<int> st1{2, 1, 2, 6, 2, 4, 3, 3};
	vector<int> ans=solution(n, st1);
	for(int i=0; i<ans.size(); i++){
		cout << ans[i] << " ";
	}//for-i
	
	return 0;
}//main










#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int flag;

void dfs(string str,                      // 
         vector<vector<string>> &tc, // 그래프
         vector<int> &wei,           // 방문체크
         vector<string> &ans1,       // 임시 그래프 답안
         vector<string> &ans2,        // 최종 그래프 답안
         int &cnt){                  // 경유한 공항의 수
            
         if(flag==1) return;
    
         if(cnt==tc.size()){
            ans2=ans1;
            flag=1;
            return;
         }//if
        
        for(int i=0; i<tc.size(); i++){
            if(wei[i]==0 && tc[i][0]==str){
                wei[i]=1;
                ans1.push_back(tc[i][1]);
                dfs(tc[i][1], tc, wei, ans1, ans2, ++cnt);
            }//if
        }//for-i
    
}//dfs

vector<string> solution(vector<vector<string>> tc) {
    vector<int> wei(tc.size());
    vector<string> ans1;
    vector<string> ans2;
    int cnt=0;
    
    sort(tc.begin(), tc.end());
    for(int i=0; i<tc.size(); i++){
        if(tc[i][0]=="ICN"){
            ans1.push_back(tc[i][0]);
            ans1.push_back(tc[i][1]);
            wei[i]==1;
            dfs(tc[i][1], tc, wei, ans1, ans2, ++cnt);
            break;
        }//if
    }//for-i
    
    return ans2;
}//solution

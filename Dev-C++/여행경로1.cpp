#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> re;
int flag;
int tt;

void dfs(string st, 
         vector<vector<string>> &tc, 
         vector<string>& ans, 
         vector<int>& wei,
         int& cnt){
         	
    if(flag==1){
        return;
    }
    
    if(cnt==tt){
        re=ans;
        flag=1;
        return;
    }
    
    
    for(int i=0; i<tc.size(); i++){
        if(wei[i]==0 && tc[i][0]==st){
            wei[i]=1;
            ans.push_back(tc[i][1]);
            dfs(tc[i][1], tc, ans, wei, ++cnt);    
            ans.pop_back();
            wei[i]=0;
        }//if  
    }//for-i    
}//dfs

vector<string> solution(vector<vector<string>> tc) {
    vector<int> wei(tc.size());    
    vector<string> ans;
    tt=tc.size();
    int cnt=0;
    sort(tc.begin(), tc.end());
    for(int i=0; i<tc.size(); i++){
    	if(tc[i][0]=="ICN"){                
            ans.push_back("ICN");
            ans.push_back(tc[i][1]);
            wei[i]=1;
    		dfs(tc[i][1], tc, ans, wei, ++cnt);            
    		break;
		}//if
	}//for-i    
    return re;
}//solution

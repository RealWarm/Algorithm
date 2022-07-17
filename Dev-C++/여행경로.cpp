#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<string> q1;
int wei[10010];

vector<string> solution(vector<vector<string> > tc) {
    vector<string> ans;
    sort(tc.begin(), tc.end());
    for(int i=0; i<tc.size(); i++){
    	if(tc[i][0]=="ICN"){                
            ans.push_back("ICN");
    		ans.push_back(tc[i][1]);
    		q1.push(tc[i][1]);
            tc.erase(tc.begin()+i);
    		break;
		}//if
	}//for-i
	
	while(!q1.empty()){
		string nws=q1.front();
		q1.pop();
		for(int i=0; i<tc.size(); i++){
			if(tc[i][0]==nws){				
				ans.push_back(tc[i][1]);
    			q1.push(tc[i][1]);
                tc.erase(tc.begin()+i);
                i--; 
			}//if
		}//for-i
	}//while
    
    return ans;
}//solution

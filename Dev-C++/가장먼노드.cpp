#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > grp(20010);
queue<int> q1;
int wei[20010];

int solution(int n, vector<vector<int> > edge) {
    
    for (int i = 0; i < edge.size(); i++) {
        grp[edge[i][0]].push_back(edge[i][1]);
        grp[edge[i][1]].push_back(edge[i][0]);
    }
    
    wei[1]=1;
    q1.push(1);    
    while(!q1.empty()){
        int nwx=q1.front();
        q1.pop();        
        for(int i=0; i<grp[nwx].size(); i++){
            int ntx=grp[nwx][i];
            if(wei[ntx]==0){
                wei[ntx]=wei[nwx]+1;
                q1.push(ntx);
            }//if
        }//for-i
    }//while    
    
    int mmax=-987;
    int cnt=0;
    for(int i=0; i<n+1; i++){
        if(wei[i]>mmax){
            mmax=wei[i];
            cnt=1;
        }else if(wei[i]==mmax){
            cnt++;
        }
    }//for-i

//	for(int i=0; i<n; i++){
//		printf("%d ", wei[i]);
//	}//for-i
    
    return cnt;    
    
}//solution

#include<iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int> > grp;
int wei[220];

void dfs(int x, int cc){
	wei[x]=cc;
	for(int i=0; i<grp[x].size(); i++){
		int ntx=grp[x][i];
		if(wei[ntx]==0){
			wei[ntx]=cc;
			dfs(ntx, cc);
		}//if
	}//for-i
}//dfs

int solution(int n, vector<vector<int>> cpt) { 
				// 컴퓨터 갯수, 연결정보가 담기 2차원 배열
    grp.resize(n);
    for(int i=0; i<cpt.size(); i++){
        for(int j=0; j<cpt[i].size(); j++){
            if(i!=j && cpt[i][j]==1){
                grp[i].push_back(j);
            }//if
        }//for-j
    }//for-i
	
	int clr=0;
	for(int i=0; i<n; i++){
		if(wei[i]==0){
			dfs(i, ++clr);
		}//if
	}//for-i
    
    return clr;
}//solution

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int> > grp; // 원본 배열
int wei[100010];          // 어떤 칸을 밟을지를 정하는 배열
int r, mmax;              // 

void get(int x, int be){  // 몇번째 줄이니?, 전에 밟았던 칸의 번호는?    
    if(x>=r){
        int sum=0;
        for(int i=0; i<grp.size(); i++){
            sum+=grp[i][wei[i]];
        }
        if(sum > mmax){
            mmax=sum;
        }
    }else{
        for(int i=0; i<4; i++){
            if(i!=be){
                //다음으로 밟을 칸이 전에 밟은 칸과 다르면.
                wei[x]=i;
                get(x+1, i);
            }//if            
        }//for-i        
    }//if    
}//get

int solution(vector<vector<int> > land){
    memset(wei, -1, sizeof(wei));
    grp=land;           // 재귀를 위해선 전역으로 돌려야 하므로
    r=land.size();      // 재귀의 탈출조건
    get(0, -2);         // 재귀시작 >> -1을 준 이유는 첫번째 칸에는 모든 경우를 탐색해야 하므로.
    return mmax;
}//solution

// n행 4열 >> 1행부터 한칸씩 내려온다. >> 전에 밟았던 칸은 밟으면 안된다.
// 밟은 칸들의 합이 최대가 될때의 합을 반환한다.
// 재귀
// 밟아야 하는 칸의 번호들을 정한다. >> 더해보고 비교해본다

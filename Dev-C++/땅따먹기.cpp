#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int> > grp; // ���� �迭
int wei[100010];          // � ĭ�� �������� ���ϴ� �迭
int r, mmax;              // 

void get(int x, int be){  // ���° ���̴�?, ���� ��Ҵ� ĭ�� ��ȣ��?    
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
                //�������� ���� ĭ�� ���� ���� ĭ�� �ٸ���.
                wei[x]=i;
                get(x+1, i);
            }//if            
        }//for-i        
    }//if    
}//get

int solution(vector<vector<int> > land){
    memset(wei, -1, sizeof(wei));
    grp=land;           // ��͸� ���ؼ� �������� ������ �ϹǷ�
    r=land.size();      // ����� Ż������
    get(0, -2);         // ��ͽ��� >> -1�� �� ������ ù��° ĭ���� ��� ��츦 Ž���ؾ� �ϹǷ�.
    return mmax;
}//solution

// n�� 4�� >> 1����� ��ĭ�� �����´�. >> ���� ��Ҵ� ĭ�� ������ �ȵȴ�.
// ���� ĭ���� ���� �ִ밡 �ɶ��� ���� ��ȯ�Ѵ�.
// ���
// ��ƾ� �ϴ� ĭ�� ��ȣ���� ���Ѵ�. >> ���غ��� ���غ���

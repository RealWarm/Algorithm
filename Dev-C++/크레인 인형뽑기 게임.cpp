#include <vector>
using namespace std;

int find(int x, vector<vector<int>> bd){
    // bd �迭�� X �ε������� 
    // ���� ���� �ִ� ������ �ε����� ��ȯ�Ѵ�.
    // ������ �ƿ����� ��� >> -1 ��ȯ
    for(int i=0; i<bd.size(); i++){
        if(bd[i][x]!=0){            
            return i;
        }//if
    }//for-i    
    return -1;
}//find

int solution(vector<vector<int>> bd, vector<int> mv) {
//    vector<vector<int>> bd; // �׷��� >> �ٲٸ鼭 �ҰŴϱ�
//    bd=bd2;                 // �׷��� >> �ٲٸ鼭 �ҰŴϱ�
    int cnt=0;              // ��� ������ ���������
    vector<int> ss;         // �ٱ���
    for(int i=0; i<mv.size(); i++){
        int del=find(mv[i]-1, bd);
        printf("del :: %d\n", del);
        if(del == -1) continue;
        int peek=bd[del][mv[i]-1];
        bd[del][mv[i]-1]=0;
        if(ss.size()>0 && ss[ss.size()-1]==peek){ //����  !!!!!!!!!!!!!1
            ss.pop_back();
            cnt+=2;
        }else{
            ss.push_back(peek);
        }//if
        ////////////////////////////////////////////////////////////
//        for(int a=0; a<bd.size(); a++){
//        	for(int j=0; j<bd[a].size(); j++){
//        		printf("%d ", bd[a][j]);
//			}//for-j
//			printf("\n");
//		}//for-a
//				
//		for(int a=0; a<ss.size(); a++){
//			printf("%d ", ss[a]);
//		}
//		printf("\n");
//		printf("\n");
		////////////////////////////////////////////////////////////
    }//for-i    
    return cnt;
}//solution

int main(){
	vector<vector<int>> bd2{{0,0,0,0,0},
							{0,0,1,0,3},
							{0,2,5,0,1},
							{4,2,4,4,2},
							{3,5,1,3,1}
							};
	vector<int> mv{1,5,3,5,1,2,1,4};
	
	for(int a=0; a<bd2.size(); a++){
    	for(int j=0; j<bd2[a].size(); j++){
    		printf("%d ", bd2[a][j]);
		}//for-j
		printf("\n");
	}//for-a
	printf("\n");
	printf("\n");
	cout << "******* " << solution(bd2, mv);
	
	return 0;
}//main

// �׷��� ��ġ�� ������ ��´� >> ���� ������ 0 ���� �ٲ۴�.
// �ٱ��Ͽ� �ִ´� >> �� �Ʒ� ��ġ �ϴ°� �ִ��� ã�´� >> ��ġ�ϸ� �Ͷ߸���.


// ������ ���� �ڸ��� 0���� ���ٲ۴�. >> �ε����� �Ųٷ� ����. 

#include <vector>
using namespace std;

int find(int x, vector<vector<int>> bd){
    // bd 배열의 X 인덱스에서 
    // 가장 높이 있는 인형의 인덱스를 반환한다.
    // 인형이 아에없는 경우 >> -1 반환
    for(int i=0; i<bd.size(); i++){
        if(bd[i][x]!=0){            
            return i;
        }//if
    }//for-i    
    return -1;
}//find

int solution(vector<vector<int>> bd, vector<int> mv) {
//    vector<vector<int>> bd; // 그래프 >> 바꾸면서 할거니까
//    bd=bd2;                 // 그래프 >> 바꾸면서 할거니까
    int cnt=0;              // 몇개의 인형이 사라졌는지
    vector<int> ss;         // 바구니
    for(int i=0; i<mv.size(); i++){
        int del=find(mv[i]-1, bd);
        printf("del :: %d\n", del);
        if(del == -1) continue;
        int peek=bd[del][mv[i]-1];
        bd[del][mv[i]-1]=0;
        if(ss.size()>0 && ss[ss.size()-1]==peek){ //여기  !!!!!!!!!!!!!1
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

// 그래프 위치에 인형을 잡는다 >> 잡은 인형은 0 으로 바꾼다.
// 바구니에 넣는다 >> 위 아래 일치 하는게 있는지 찾는다 >> 일치하면 터뜨린다.


// 인형을 뽑은 자리를 0으로 못바꾼다. >> 인덱스를 거꾸로 했음. 

#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> tobin(int x){
    //x를 이진수로 만든다.
    vector<int>tmp; 
    while(x!=0){
        tmp.push_back(x%2);
        x/=2;
//        if(x==0) break;
    }//while  
    reverse(tmp.begin(), tmp.end());
	return tmp;
}//tobin


string makeg(int x, int n){
    // 숫자 x를 n자리의 이진수로 만든다.
    // 이진수를 만든다 >> n-배열길이 >> 만큼 tmp에
    string tmp;
    vector<int> v1=tobin(x);
    int znum = n - v1.size();
    for(int i=0; i<znum; i++){
        tmp+='0';
    }//for-i
    
    for(int i=0; i<v1.size(); i++){
        tmp+=to_string(v1[i]);
    }//for-i
    return tmp;
}//makeg

vector<string> solution(int n, 
						vector<int> arr1, 
						vector<int> arr2) {
    vector<string> ans(n);
    vector<string> grp1(n), grp2(n);
    for(int i=0; i<arr1.size(); i++){
        grp1[i]=makeg(arr1[i], n);
    }//for-i
    for(int i=0; i<arr1.size(); i++){
        grp2[i]=makeg(arr2[i], n);
    }//for-i
    //////////////////////////////////////////////////////////////////////    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grp1[i][j]=='1' || grp2[i][j]=='1'){
                ans[i]+='#';
            }else{
                ans[i]+=' ';
            }//if
        }//for-j
    }//for-i
    
    return ans;
}//solution

// arr1과 arr2를 그래프로 만든다.
// 통합한 그래프를 만든다.
// 반환한다.

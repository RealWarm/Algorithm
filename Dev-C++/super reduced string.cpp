#include <bits/stdc++.h>
using namespace std;

string superReducedString(string s) {
    //0부터 s.size()-1까지 i와 i+1번째가 같으면 삭제한다.
    string tmp;
    for(int i=0; i<s.size()-1; i++){
        if(s[i]==s[i+1]){
            s.erase(i,2);    
            i--;
        }//if        
    }//for-i

    if(s.size()==0){
        return "Empty String";
    }else{
        return s;
    }//if

}//superReducedString

int main(){
	string str;
   	cin>> str;
   	cout <<superReducedString(str)<<endl;
    return 0;
}//main


#include <bits/stdc++.h>
using namespace std;

string superReducedString(string s) {
    //0���� s.size()-1���� i�� i+1��°�� ������ �����Ѵ�.
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


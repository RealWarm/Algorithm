#include <iostream>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;
string str;
stack<char> st; 

int main(void){

        ios_base::sync_with_stdio(0);
        cin.tie(0); //cin 실행속도 향상
        cin >> str; 

        ll result = 0;
        int temp = 1;
        bool impossible = false; 

        for (int i = 0; i < str.size(); i++){

             if (str[i] == '('){
                 temp *= 2;
                 st.push('(');
             }else if(str[i] == '['){
                 temp *= 3;
                 st.push('[');
             }else if(str[i] == ')' && (st.empty() || st.top() != '(')){
                 impossible = true;
                 break;
             }else if(str[i] == ']' && (st.empty() || st.top() != '[')){
                 impossible = true;
                 break;
             }else if(str[i] == ')'){
                 if (str[i - 1] == '('){
                 	result += temp;
				 }
                 st.pop();
                 temp /= 2;
             }else if (str[i] == ']'){
                 if (str[i - 1] == '['){
                 	result += temp;
				 }
                 st.pop();
                 temp /= 3;
             }
        } 

        if (impossible || !st.empty()){
        	printf("0");
		}else{
			printf("%d",result);
		}
		return 0;

}

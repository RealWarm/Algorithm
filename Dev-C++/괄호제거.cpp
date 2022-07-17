#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
vector<int> wei;
string str;
int ch[15];		// 삭제해볼 괄호쌍의 번호저장 
int leng, r; 	// 괄호쌍의수, 삭제해볼 괄호쌍의 수 
vector<string> ans;
set<string> sset;

void get(int x){
	
	if(x>=r){
		string tmp;
		for(int i=0; i<str.size(); i++){
			if(wei[i]==0){
				tmp+=str[i];
			}else{		
				int flag=0; // 지워야할 괄호면 1, 아니면 0		
				for(int a=0; a<r; a++){
					if(wei[i]==ch[a]){
						flag=1;
						break; 
					}//if
				}//for-a
				
				if(flag==1){
					continue;
				}else{
					tmp+=str[i];
				}//if-2				
			}//if-1
		}//for-i
//		cout<< tmp << endl;
		sset.insert(tmp);
//		for(int i=0; i<r; i++) {
//			printf("%d ", ch[i]);
//		}//for-i
//		printf("\n");
	}else{
		for(int i=1; i<=leng; i++){
			if(x==0 || ch[x-1]<i){
				ch[x]=i;
				get(x+1);
			}//if
		}//for-i
	}//if
	
}//get

int main(){
	getline(cin, str);
	int num=0; //괄호 번호 
	stack<int> st;
	wei.resize(str.size()); // 괄호에 번호를 저장할 배열 
	
	for(int i=0; i<str.size(); i++){
		if(str[i]=='('){
			num++;
			wei[i]=num;
			st.push(num);
		}else if(str[i]==')'){
			if(!st.empty()){
				wei[i]=st.top();
				st.pop();
			}//if			
		}//if
		leng=max(leng, num);
	}//for-i
	
//	for(int i=0; i<wei.size(); i++){
//		printf("%d ", wei[i]);
//	}//for-i
	
	for(int i=1; i<=leng; i++){
		r=i;
//		printf("r :: %d\n", r);		
		get(0);
	}//for-i
	
//	sort(ans.begin(), ans.end());
//	for(int i=0; i<ans.size(); i++){
//		cout << ans[i] << endl;
//	}//for-i
	
	set<string>::iterator iter;
	for(iter=sset.begin(); iter!=sset.end(); iter++){
		cout << (*iter) << endl;
	}
	// ((((0))))(1)
	return 0;	
}//main



#include<iostream>
#include<stack>
using namespace std;

int main(){
	
	int n, m; cin >> n >> m;
	stack<int> st;
	
	while(m--){
		int num; cin >> num;
		
		if(num==1){
			int val; cin >> val;//위치 중요 
			if(st.size()<=n-1){
				st.push(val);
			}else if(st.size()>=n){
				cout<<"Overflow\n";
				continue;				
			}
		}else if(num==2){
			if(!st.empty()){
				st.pop();
			}else if(st.empty()){
				cout << "Underflow\n";
			}
		}else if(num == 3){
			if(!st.empty()){
				cout << st.top() << "\n";
			}else if(st.empty()){
				cout << "NULL" << "\n";
			}
		}//if-else		
	}//while
	
	return 0;
}

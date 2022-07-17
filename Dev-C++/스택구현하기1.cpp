#include<iostream> 
#include<cstdio>
#include<stack>
using namespace std;

int main(){
	
	int n, m; cin >> n >> m;
	stack<int> st;
	while(m--){
		int a; scanf("%d", &a);
		
		if(a==1){
			int b; scanf("%d", &b);
			if(st.size()>=n){
				printf("Overflow\n");
			}else{				
				st.push(b);
			}			
		}else if(a==2){
			if(st.empty()){
				printf("Underflow\n");
			}else{
				st.pop();
			}			
		}else if(a==3){		
			if(st.empty()){
				printf("NULL\n");
			}else{
				cout<< st.top()<<'\n';
			}	
		}
		
	}//while
	
	return 0;
}

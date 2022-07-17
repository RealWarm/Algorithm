// 1. string size()와 length()의 반환형이 unsigned int이기 때문에 주어진 문자열의 
// 크기보다 부분문자열의 크기가 클 경우 underflow가 발생하기 때문에 런타임 에러가 
// 뜹니다.


#include<iostream> 
#include<cstring>
using namespace std;

int main(){
	int cnt=0;
	string s, t;
	getline(cin, s);
	getline(cin, t);
	if(s.size() < t.size()){
		 cout << 0 << "\n";
		 return 0;
	}
	////////////////////////////////////////////////////////////
	for(int i=0; i<s.size()-t.size()+1; i++){
		if(s[i]==t[0]){
//			cout << "s[i]==t[0] "<< s[i] << " || i :: " << i << endl;
//			cout << "===============================" << endl;
			int flag=0;
			for(int a=0; a<t.size(); a++){				
				if(s[i+a]!=t[a]){
//					cout << "s[i]!=t[0] || " << s[i+a] << "  " << t[a]<< endl;		
					flag=1;
					break;
				}else{
					
				}
			}//for-a
			
			if(flag==0){
				cnt++;
				if(i+t.size()<s.size()){
					i+=t.size()-1;
				}else{
					break;
				}
			}//if
		}//if
	}//for-i
	
	printf("%d \n", cnt);
	
	return 0;
}//main

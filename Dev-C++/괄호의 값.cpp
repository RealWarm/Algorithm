#include<iostream>
#include<cstring>
using namespace std;

int main(){
	
	string str; cin >> str;
	int len=str.length();
	
	int sum1=0, sum2=0, total=0;
	for(int i=0; i<len; i++){
		if(str[i]='('){
			sum1++;
		}else if(str[i] = '['){
			sum2++;
		}if(str[i]=')'){
			if(sum1<=0){
				cout << 0;
				return 0;
			}else if(sum1>=1){
				sum1--;
			}//if-else			
		}
	}//for-i
	
	
	
	return 0;
}

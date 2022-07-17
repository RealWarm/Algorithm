#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int ts; cin>>ts;
	for(int tt=1; tt<=ts; tt++){
		vector<string> arr1(18);
		vector<string> arr2(18);
		vector<string> arr3(18);
		int k; cin>>k;
		string str; cin >> str;
		
		for(int i=0; i<18; i++){
			string temp ="";
			for(int j=0; j<3; j++){
				temp+=str[(i+j)%18];
			}
			arr1[i]=temp;
		}//for-i
		
		arr3=arr1;	
		sort(arr3.begin(), arr3.end());
		string ans = arr3[k-1];
		
		for(int i=0; i!=3; i--){
			string temp ="";
			if(i<0){
				i=17;
			}
			for(int j=0; j<3; j++){
				int inx = i+j;
				temp+=str[inx];
			}
			arr1[i]=temp;
		}//for-i
		
		int i=0;
		int cnt=0;
		do{
			string temp ="";
			if(i<0){
				i=17;
			}
			for(int j=0; j<3; j++){
				int inx = i+j;
				temp+=str[inx%18];
			}
			arr2[cnt++]=temp;
			i--;
		}while(i!=0);
		
		int min=0;
		for(int i=0; i<arr1.size(); i++){
			if(arr1[i] == ans || arr2[i]==ans){
				min=i;
				break;
			}
		}
		
		int result=0;
		if(ans[0]>='A'){
			result+=(ans[0]-'A'+10)*32*32;
//			printf("*** %d\n", result);
		}else{
			result+=(ans[0]-'0')*32*32;
//			printf("### %d\n", result);
		}
		
		if(ans[1]>='A'){
			result+=(ans[1]-'A'+10)*32;
//			printf("*** %d\n", result);
		}else{
			result+=(ans[1]-'0')*32;
//			printf("### %d\n", result);
		}
		
		if(ans[2]>='A'){
			result+=(ans[2]-'A'+10);
//			printf("*** %d\n", result);
		}else{
			result+=(ans[2]-'0');
//			printf("### %d\n", result);
		}
	
		
		printf("#%d %d %d\n", tt, min, result);
	}
		
	return 0;
}//main

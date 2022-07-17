#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

vector<string> split(string str, char delimiter){	
	vector<string> internal;
	stringstream ss(str);
	string temp;	
	while(getline(ss, temp, delimiter)){
		internal.push_back(temp);
	}//while	
	return internal;	
}//Split

int main(){
	
	int tt; scanf("%d ", &tt);
		
	for(int ts=0; ts<tt; ts++){		
		string str; getline(cin, str);
		vector<string> ans=split(str, ' ');
		while(1){
			string tmp; getline(cin, tmp);
			if(tmp.compare("what does the fox say?")==0) break;
			vector<string> tv1;
			tv1=split(tmp, ' ');
//			printf("tv1[2] :: %s \n", tv1[2].c_str());
			
			for(int a=0; a<ans.size(); a++){
				if(tv1[2]==ans[a]){
					ans.erase(ans.begin()+a);
					a--;
				}//if
			}//for-a
			
		}//while
		
		for(int i=0; i<ans.size(); i++){
			printf("%s ", ans[i].c_str());
		}//for-i
	}//for-ts
		
	return 0;
}//main

//int main(){
//	int t; scanf(" %d ", &t);
//	for(int ts=1; ts<=t; ts++){
//		string tmp; getline(cin, tmp);
//		vector<string> ans=split(tmp, ' ');
//		while(1){
//			string tmp2; getline(cin, tmp2);
//			if(tmp2=="what does the fox say?") break;
//			vector<string> tv=split(tmp2, ' ');
//			for(int i=0; i<ans.size();){
//				if(ans[i]==tv[2]){
//					ans.erase(ans.begin()+i);
//				}else{
//					i++;
//				}//if
//			}//for-i
//		}//while
//		
//		for(int i=0; i<ans.size(); i++){
//			printf("%s ", ans[i].c_str());
//		}//for-i
//	}//for-ts
//	return 0;
//}//main

#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int ch[100010], wei[100010];
int grp[100010];
int r, mmax;

void get(int x){	
	if(x>=r){
		string cp;
		for(int i=0; i<r; i++){
			cp+=to_string(grp[ch[i]]);
		}//for-i
		int comp=stoi(cp);
		if(mmax<comp){
			mmax=comp;
		}				
	}else{
		for(int i=0; i<r; i++){
			if(wei[i]==0){
				wei[i]=1;
				ch[x]=i;
				get(x+1);
				wei[i]=0;
			}//if
		}//for-i
	}//if
}//get

string solution(int numbers[], size_t nl) {
	memcpy(grp, numbers, sizeof(grp));
   	r=nl;
   	get(0);
   	string str=to_string(mmax);
    return str;
}//solution

int main(){
	int tmp[100010]={3, 30, 34, 5, 9};	
	cout << solution(tmp, 5);
	return 0;
}//main

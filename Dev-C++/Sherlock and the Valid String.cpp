#include <bits/stdc++.h>
using namespace std;
int ch[30];//���ĺ����� ������ �����Ѵ�. 
int nf[100010];//���ڵ��� �� 
int fnum; //�ְ� �Ǵ� ��. 

string isValid(string s) {
	for(int i=0; i<s.size(); i++){
		ch[s[i]-'a']++;
	}//for-i
	
	int cnt=0; // ���ڵ��� ���� ��  
	for(int i=0; i<26; i++){
		if(ch[i]>0){
			nf[ch[i]]++;
			cnt++;
		}
	}//for-i
	
	for(int i=0; i<=100000; i++){
		if(nf[i]>=fnum){
			fnum=nf[i];
		}//if
	}//for-i
	
	int sum=0;
	for(int i=0; i<26; i++){		
		if(fnum-ch[i]<-1 || fnum-ch[i]>1){
			return "NO";
		}if(fnum-ch[i]==-1 && cnt==2){
			return "YES";
		}else if(fnum-ch[i] == -1 && cnt>2){
			return "NO";
		}else if(fnum-ch[i]==1){
			sum+=(fnum-ch[i]);
		}
	}//for-i
	
	if(sum==1){
		return "YES";
	}else{
		return "NO";
	}//if	

}//isValid

int main(){
    string  str; cin >> str;
    cout << isValid(str);
    return 0;
}//main


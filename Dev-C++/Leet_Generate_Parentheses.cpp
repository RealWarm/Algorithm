#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> vv;
int wei[20]; 	// 1 : '(', -1 : ')'
int n, r;		// �յ��� ��ȣ�� ��, ���ڿ� ����

void get(int x, int num){ // ��ȣ�� �ε���, ��ȣ�� ������
	// x��  
	if(num<0) return;
	if(x>r){
		string str;
		int sum=0;
		for(int i=0; i<r; i++) {
			sum+=wei[i];
		}//for-i
		if(sum!=0) return;
		for(int i=0; i<r; i++) {
			if(wei[i]==1){
				str+="(";
			}else if(wei[i]==-1){
				str++")";
			}//if			
		}//for-i
		vv.push_back(str);
	}else{
		wei[x]=1;
		get(x+1, num+1);
		wei[x]=-1;
		get(x+1, num-1);
	}//if
	
}//get

int main(){
	int n; scanf(" %d", &n);
	r=n*2;
	get(0, 0);
	return 0;
}//main

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

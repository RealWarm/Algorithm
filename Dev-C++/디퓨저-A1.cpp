#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int> > v1;
int grp[110][110];
int ch[11];
int n, m, k, t, flag, cnt;
int len;

void get(int x){
	
	if(flag==1) return;
	
	if(x==k){
		cnt++;
		if(cnt==t){
			for(int i=0; i<k; i++){
				printf("%d %d\n", v1[ch[i]].first+1, v1[ch[i]].second+1);
			}//for-i
			flag=1;
		}		
	}else{
		for(int i=0; i<v1.size(); i++){
			if(x==0 || ch[x-1]<i){
				ch[x]=i;
				get(x+1);	
			}			
		}//for-i
	}//if
	
}//get

int main(){
	scanf("%d %d %d %d", &n, &m, &k, &t);
	for(int a=0; a<n; a++){
		for(int b=0; b<m; b++){
			scanf("%d", &grp[a][b]);
			if(grp[a][b]==2){
				v1.push_back(make_pair(a, b));				
			}//if
		}//for-b
	}//for-a	
	len=v1.size();
	get(0);
	return 0;
}//main

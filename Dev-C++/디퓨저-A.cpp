#include<iostream>
#include<vector>
using namespace std;
int grp[110][110];
int result[10]; // for문의 변수값  
int n, m, k, t, sum;
int cnt, flag;
vector<pair<int, int> > v1;

void get(int x){
	
	if(flag==1) return;
	
	if(x==k){ 
		// k중 for문을 만들었다. 
		cnt++;
		if(cnt==t){
			for(int i=0; i<k; i++){
				printf("%d %d\n", v1[result[i]].first+1, v1[result[i]].second+1);
			}//for-i			
			flag=1;
		}//if
		return;
	}//if
	
	for(int q=0; q<v1.size(); q++){//result
		if(x==0 || result[x-1]<q){//갈수록 숫자가 커진다. 
			result[x]=q;
			get(x+1);
		}
	}//for-q
	
}//get


int main(){
	
	scanf("%d %d %d %d", &n, &m, &k, &t);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &grp[i][j]);
			if(grp[i][j]==2){
				v1.push_back(make_pair(i, j));
				sum++;
			}//if
		}//for-j
	}//for-i
	
	get(0);
	return 0;
}//main

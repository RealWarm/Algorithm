#include <iostream> 
#include <vector>
using namespace std;
typedef long long ll;
int opp[20];
int n, cnt; // 소들의 수, 가능한 경우의 수 

void get(int x){
	
	if(x>n){
		string all;		
		all+="1";
		for(int i=2; i<=n; i++){
			if(opp[i]==1){
				all+="+";
				all+=to_string(i);
			}else if(opp[i]==2){
				all+="-";
				all+=to_string(i);
			}else if(opp[i]==3){				
				all+=to_string(i);
			}//if
		}//for-i
		/////////////////////////////////
		vector<ll> vv;
		vector<char> op;
		string tmp;
		
		int len=0;
		for(int i=0; i<all.size(); i++){
			if(all[i]>='0' && all[i]<='9'){
				tmp+=all[i];
				len++;
				if(len>9) return;
			}else if(all[i]=='+' || all[i]=='-'){
				len=0;
				op.push_back(all[i]);
				if(tmp.size()>0){
					vv.push_back(stoll(tmp));
					tmp.clear();
				}//if
			}//if
		}//for-i
		
		if(tmp.size()>0){
			vv.push_back(stoll(tmp));
			tmp.clear();
		}//if
		///////////////////////////////////////////////////////////////
		int sum=0;
		if(op.size()==0){
			sum=vv[0];
		}else{
			sum=vv[0];
			for(int i=1; i<vv.size(); i++){
				if(op[i-1]=='+'){
					sum+=vv[i];
				}else if(op[i-1]=='-'){
					sum-=vv[i];
				}//if				
				if(i> && sum==0){
					return;
				}
			}//for-i
			
			if(sum>=12345678910 || sum<-12345678910){
				return;
			}//if
		}//if
		
		if(sum==0 && cnt<20){
			cnt++;				
//			for(int i=0; i<vv.size()-1; i++){
//				printf("%d ", vv[i]);
//				printf("%c ", op[i]);
//			}//for-i
//			printf("%d ", vv[vv.size()-1]);
//			printf("  ||  %d", sum);
//			printf("\n");		
			printf("1");
			for(int i=2; i<=n+1; i++){
				if(opp[i-1]==1){
					printf(" + %lld", i-1);
				}else if(opp[i-1]==2){
					printf(" - %lld", i-1);
				}else if(opp[i-1]==3){				
					printf(" . %lld", i-1);
				}//if
			}//for-i
			printf("\n");
		}//if		
		///////////////////////////////////////////////////		
	}else{
		for(int i=1; i<=3; i++){
			opp[x]=i;
			get(x+1);
		}//for-i
	}//if
}//get

int main(){
	scanf(" %d", &n);
	if(n==2){
		printf("1 - 1 \n1");
		return 0;
	}//if	
	get(2);
	////////////////////////////
	printf("%d\n", cnt);
	return 0;
}//main

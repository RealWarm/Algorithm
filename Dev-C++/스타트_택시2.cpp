#include<iostream>
using namespace std;
typedef long long ll;
ll tt[1000010];
ll n, m; // 나무의수, 원하는 나무 길이 

ll cut(int h){
	ll sum=0;
	for(int i=0; i<n; i++){
		ll tmp=tt[i]-h;
		if(tmp>0)sum+=tmp;
		if(sum>=m) return 1;
	}//for-i
	return-1;
}//cut

int main(){
	ll start=0, end=0;
	scanf(" %lld %lld", &n, &m);
	for(int i=0; i<n; i++){
		scanf(" %lld", &tt[i]);
		if(tt[i]>end){
			end=tt[i];
		}//if
	}//for-i
	printf("%d - %d\n", start, end);
	////////////////////////////////
	while(start<=end){
		ll mid=(start+end)/2;
		if(cut(mid)==1){
			start=mid;
		}else{
			end=mid;
		}//if		
		printf("%d - %d - %d\n", start, mid, end);
	}//while
	printf("%d\n", start);
	
	return 0;
}//main

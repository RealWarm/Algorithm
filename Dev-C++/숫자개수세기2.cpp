#include<iostream>
#include<algorithm>
using namespace std;
int ar[100010];
int n, q; 

int gstt(int v){
	// val이 등장하기 시작하는 인덱스를 반환한다.
	// start : val보다 작은 값을 가르킨다
	// end 	 : val과 같거나 큰 값을 가르킴
	int s=0;
	int e=n-1; 
	// 2 3 4 5 6 7
	// 1
	if(ar[s]>v){
		return -1;
	}else if(ar[s]==v){
		return s;
	}//if
	
	// 2 3 4 5 6 7
	// 8
	if(ar[e]<v){
		return -1;
	}
	
	while(s+1<e){
		int mid = (s+e)/2;
		if(ar[mid]>=v) e=mid;		
		else if(ar[mid]<v) s=mid;		
	}//while
	
	if(ar[e]==v) return e;
	else return -1;
	
}//gst

int gent(int v){
	// val이 끝나는 인덱스를 반환한다.
	// s=val보다 작거나 같은 값을 가르킨다.
	// e=val보다 큰 값을 가르킨다.
	int s=0;
	int e=n-1;
	
	if(ar[s]>v) return -1;
	
	if(ar[e]<v) return -1;
	else if(ar[e]==v) return e;
	
	while(s+1<e){
		int mid = (s+e)/2;
		if(ar[mid]<=v) s=mid;
		else if(ar[mid]>v) e=mid;		
	}//while
	
	if(ar[s]==v) return s;	
	else return -1;
	 
}//gent

int main(){
	scanf(" %d %d", &n, &q);
	for(int i=0; i<n; i++){
		scanf(" %d", &ar[i]);
	}//for-i
	sort(ar, ar+n);
	////////////////////////////
	for(int i=0; i<q; i++){	
//		printf("q == %d \n", q);
		int tmp; scanf(" %d", &tmp);
		int s=gstt(tmp);
		int e=gent(tmp);
		if(s!=-1) printf("%d\n", e-s+1);
		else printf("0\n");
	}//while
	return 0;
}//main

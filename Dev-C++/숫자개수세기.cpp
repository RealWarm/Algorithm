#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int ges(int arr[], int s, int e, int v){
	// s:: v���� ���� ���� ����Ų��.
	// e:: v�� ���ų� ū���� ����Ų��.
	int ss=s;
	int ee=e;
	int mid;
	
	if(arr[ss]==v) return ss;
	else if(arr[ss]>v) return -1;
	
	if(arr[ee]<v) return -1;
	
	while(ss+1 < ee){
		int mid=(ss+ee)/2;
		if(arr[mid]==v) return mid;
		else if(arr[mid]>v) ee=mid;
		else if(arr[mid]<v) ss=mid;
	}//while
	
	if(arr[ee]==v) return ee;
	else return -1;
	
}//ges

int gee(int arr[], int s, int e, int v){
	// s :: v�� ���ų� ���� ���� ����Ų��
	// e :: v���� ū ���� ����Ų�� 
	int ss=s;
	int ee=e;
	int mid;
	 
	
	
}//ger

int main(){
	
	int arr[100010]={0};
	int n, q; cin >> n >> q;
	
	for(int i=0; i<n; i++){
		scanf(" %d", &arr[i]);
	}//for-i
	sort(arr, arr+n);
	
	while(q--){
		int num; scanf(" %d", &num);
		int s=ges(arr, 0, n-1, num);
		int e=gee(arr, 0, n-1, num);
		
		if(s!=-1) printf("%d\n", e-s+1);
		else printf("-1\n");		
	}//while
	
	
	return 0;
}//main

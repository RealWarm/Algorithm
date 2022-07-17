#include<iostream>
#include<cstdio>
using namespace std;
int n;
int data[100005];

int getResult(int start, int end){
	
	if(start==end){
		return data[start];
	}
	int mid=(start+end)/2;
	int leftMax = getResult(start, mid);
	int rightMax = getResult(mid+1, end);
	
	int leftSubMax = data[mid];
	int rightSubMax =data[mid+1];
	
	int leftSubSum=data[mid];
	int rightSubSum=data[mid+1];
	
	for(int i=mid-1; i>=start; i--){
		leftSubSum+=data[i];
		if(leftSubMax<leftSubSum){
			leftSubMax = leftSubSum;
		}//if
	}//for-i
	
	for(int i=mid+2; i<=end; i++){
		rightSubSum += data[i];
		if(rightSubMax < rightSubSum){
			rightSubMax = rightSubSum;
		}//if
	}//for-i
	
	int middleMax =leftSubMax + rightSubMax;
	
	if(leftMax>= rightMax && leftMax >= middleMax) return leftMax;
	else if(rightMax >= leftMax && rightMax >= middleMax) return rightMax;
	else return middleMax;
	
	
}//getResult

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &data[i]);
	}
	printf("%d\n", getResult(0,n-1));
	return 0;
}//main


#include<iostream>
#include<cstdio>
using namespace std;

void merging(int arr[], int s1, int e1, int s2, int e2){
  
  // 5 4 6  2 9 7
  // p      q
  
  //s1~e1 까지 정렬을하고 s2~e2 까지 정렬을 하겠다.
  int temp[100]; // 임시로 원소들을 저장 하겠다.
  int p = s1;
  int q = s2;
  int temp_inx=0;
  
  while(p<=e1 && q<=e2){
    if(arr[p]<=arr[q]){
      temp[temp_inx++]=arr[p];
      p++;
    }else{
      temp[temp_inx++]=arr[q];
      q++;
    }
    
    if(p>e1){
      for(int k=q; k<=e2; k++){
        temp[temp_inx++]=arr[k];
      }
    }else if(q>e2){
      for(int k=p; k<=e1; k++){
        temp[temp_inx++]=arr[k];
      }
    }//if-else    
  }//while
  
  for(int i=s1; i<=e2; i++){
  	arr[i]=temp[i-s1];
  }
  
}//merging

void mergeSort(int arr[], int start, int end){
  
  if(start>=end) return;
  else{
    int mid = (start+end)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    //start부터 end까지 정렬이 되어 있다.
    merging(arr, start, mid, mid+1, end);
  }//if-else
}//mergeSort

int main(){
  
  int n; scanf("%d", &n);
  int arr[100];
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  
  mergeSort(arr, 0, n-1);
  
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }//for-i
  
  return 0;
}//main

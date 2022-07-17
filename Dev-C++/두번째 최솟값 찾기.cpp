#include<iostream>
using namespace std;

int main() {

 int arr[9]={0}; 
 for(int i=0; i<9; i++){
 	cin >> arr[i];
 }
 
 int max1, max2;
 if(arr[0]>arr[1]){
 	max1=arr[1];
 	max2=arr[0];
 }else{
 	max1=arr[0];
 	max2=arr[1];
 }
  
  for(int i=0; i<9; i++){
    if(arr[i]<max1){
      int temp=max1;
      max1=arr[i];
      max2=temp;
    }else if(arr[i]>max1){
      if(arr[i]<max2){
        max2=arr[i];
      }
    }//if-else
  }//for-i
    
  cout << max2 << endl;
  for(int i=0; i<9; i++){
  	if(arr[i]==max2){
  		cout << i+1;
		break;	
	}
  }
  
 
  return 0;
}

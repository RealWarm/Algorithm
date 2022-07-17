#include<iostream>
using namespace std;

int prime(int n){
  
  if(n==1) return 0;
  
  for(int i=2; i<n/2; i++){
    if(n%i==0){
      return 0;
    }
  }
  
  return 1;
}//prime

int rangePrime(int n){
  
  int sum=0;
  for(int i=n+1; i<=2*n; i++){
    sum+=prime(i);
  }//for-i
  
  return sum;
  
}//rangePrime

int main(){
  
  while(1){
    
    int num; cin >>num;
    if(num==0)break;
    cout << rangePrime(num);
    
  }//while
  
  return 0;
}

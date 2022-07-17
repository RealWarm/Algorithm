#include<iostream>
#include<vector>
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

int main() {

  int n; cin>>n;
  
  int sum=0;
  for(int i=0; i<n; i++){
    int num; cin >> num;
    sum+=prime(num);
  }//for-i
  
  cout << sum;

  return 0;
}

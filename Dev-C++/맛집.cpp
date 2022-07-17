#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
  
  int n, k; cin >> n >> k;
  vector<int> arr(n);
  vector<int> inter(k);
  vector<int> ans(k);
  
  for(int i=0;i<n;i++){
    cin >>arr[i];
  }
  for(int i=0;i<k;i++){
    cin >>inter[i];
  }
  
  for(int i=0; i<k; i++){
    for(int j=0; j<n; j++){
      
     if(inter[i]>arr[j] && j==(n-1)){
       ans[i]=n+1;
       break;
     }else if(inter[i]>arr[j]){
        continue;
      }else if(inter[i]<arr[j]){
        ans[i]=j+1;
        break;
      }
    }//for-j
  }//for-i
  
  for(int i=0;i<k;i++){
    cout << ans[i] << " ";
  }
  
  return 0;
}

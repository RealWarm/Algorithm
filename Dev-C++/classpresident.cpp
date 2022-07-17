#include<iostream>
#include<vector>
using namespace std;
/*
4
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
*/
int main(){
  
  int num; cin >>num;
  vector<vector<int> > arr(num, vector<int>(5));
  vector<int> ans(num);
  
  for(int i=0; i<num; i++){
    for(int j=0; j<5; j++){
      scanf("%d", &arr[i][j]);
    }//for-j
  }//for-i
  
  for(int i=0; i<num; i++){
    for(int j=0; j<num; j++){
      if(i==j) continue;
      for(int t=0; t<5; t++){
        if(arr[i][t]==arr[j][t]){
          ans[i]++;
          break;
        }//if
      }//for-t
    }//for-j
  }//for-i
  
  int maxval=-1, maxinx=0;
  for(int i=0; i<num; i++){
  	if(ans[i]>maxval){
  		maxval=ans[i];
  		maxinx = i+1;
	  }else if(ans[i]==maxval){
	  	continue;
	  }//if
  }//for-i
  
  cout << maxinx;
  
  return 0;
}//main

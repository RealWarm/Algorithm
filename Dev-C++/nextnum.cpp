#include<iostream>
using namespace std;

int main(){
  
  while(1){
    
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    if( n1==0 && n2==0 && n3==0) break;
    
    if(2*n2 == n3 +n1){
      cout << "AP " << (n3+(n2-n1)) << endl;
    }else if(n2*n2 == n3 * n1){
      cout << "GP " << (n3*(n2/n1)) << endl;
    }
    
  }//true
  
  return 0;
}//main

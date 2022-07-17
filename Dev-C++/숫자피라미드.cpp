#include<iostream>
using namespace std;

int main(){
	
	int n, s; cin >> n >> s; // n : layer, s : startNum
	int layercnt = 1;
	for(int i=0; i<n; i++){
			
		int bl=i;
		while(n-bl!=0){
			cout<<" ";
			bl++;
		}
				
		if(i%2 == 0){// 홀수는 오른쪽에서 왼쪽으로 1씩 증가. 
			for(int t=0; t<layercnt; t++){
				if(s==0){
					s=1;
				}//if
				cout<<s--;
			}//for-t			
		}else if(i%2 != 0){//짝수는 왼쫑에서 오른쪽으로 1씩 증가. 
			for(int t=0; t<layercnt; t++){
				if(s==10){
					s=1;
				}
				cout<<s++;				
			}//for-t
		}//if-else
		
		cout<< endl;
		layercnt+=2;
		
	}//for-i
	
	return 0;
}




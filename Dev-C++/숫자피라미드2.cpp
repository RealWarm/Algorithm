#include<iostream>
using namespace std;

int main(){
	
	int n, s; scanf("%d %d", &n, &s);	 
	int space = n-1, number=1;
	int previousFirst, previousLast; 
	 
	for(int i=1; i<=n; i++){
		//(1) ������ ���
		//(2) ���ڵ��� ��� 
		for(int j=0; j<space; j++) printf(" ");
		space--;
		
		if(i%2==0){//¦���� >> �����ϸ鼭 ��� 
			int currentFirst = previousFirst + 1;
			if(currentFirst >= 10) currentFirst = 1;
			
			for(int j=0; j<number; j++){
				printf("%d", currentFirst);
				previousLast = currentFirst;
				currentFirst   +=1;
				if(currentFirst>=10) currentFirst =1;
			}//for-j
			
		}else{ // Ȧ�� ��, �����ϸ鼭 ��� 
			int currentFirst;
			
			if(i==1) currentFirst = s;
			else{
				currentFirst = previousLast;			
				for(int j=0; j<number; j++){
					currentFirst += 1;
					if(currentFirst>=10) currentFirst=1;
				}//for-j				
			}//if-else
			
			
			previousFirst = currentFirst;
			
			for(int j=0; j<number; j++){
				printf("%d", currentFirst);
				currentFirst -= 1;
				if(currentFirst <= 0) currentFirst = 9;
			}//for-j
		}//if-else
		
		number+=2;
		printf("\n");
	}//for-i
	
	return 0;
}//main

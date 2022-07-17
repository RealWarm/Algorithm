#include<iostream> 
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[100];
int wei[50];

int main(){
	int flag=0;
	int nleng=0;
	string str, tstr; getline(cin, str);
	int inx=0;
	for(int i=0; i<str.size(); i++){
		if(str[i]>='1' && str[i]<='9'){
			tstr+=str[i];
		}else{
			if(tstr.size()==0) continue;			
			num[inx]=stoi(tstr);
			inx++;
			tstr.clear();
			if(wei[num[inx]]!=0){
				flag=1;
				printf("false\n");
				break;
			}else{
				wei[num[inx]]=1;
			}//if
			
			if(num[num[inx]]>45){
				flag=1;
				printf("false\n");
				break;
			}
			
			for(int j=num[inx]+1; j<=45; j++){
				if(wei[j]>=1){
					flag=1;
					printf("false\n");
					break;
				}//if
			}//for-j
			
			if(flag==1){
				break;
			}			
			
		}//if
	}//for-i
	if(inx!=6){
		printf("false\n");
		return 0;
	}
	
	if(flag==0){
		printf("true\n");
	}
	
	
//	for(int i=0; i<str.size(); i++){		
//		if(str[i]>='1' && str[i]<='9'){			
//			int inx=str[i]-'0';
//			if(wei[inx]!=0){
//				flag=1;
//				printf("false\n");
//				break;
//			}else{
//				wei[inx]=1;
//			}//if
//			if(inx>45){
//				flag=1;
//				printf("false\n");
//				break;
//			}
//			
//			for(int j=inx+1; j<=45; j++){
//				if(wei[j]>=1){
//					flag=1;
//					printf("false\n");
//					break;
//				}//if
//			}//for-j
//			if(flag==1){
//				break;
//			}
//		}
//	
//	}//for-i
//	if(nleng!=5){
//		printf("false\n");
//		return 0;
//	}
	
//	if(flag==0){
//		printf("true\n");
//	}
	
	return 0;
}//main
//
//	입력으로 들어온 로또 번호 문자열의 유효성을 검사하는 코드를 작성해주십시오.
//
//	규칙
//
//	로또 번호는 중복되지 않는 숫자 6개로 구성된다. 
//	각 번호는 1 부터 45 까지의 숫자로 구성된다.
//	로또 번호는 오름차순으로 정렬되어야 한다.
//
//	위의 규칙을 모두 준수하는 로또 번호면 true 
//	그렇지 않으면 false를 반환하는 코드를 구현해주시면 됩니다.
//
//
//	1 2 3 4 5 6
//	true
//	46 1 3 5 7 9
//	false


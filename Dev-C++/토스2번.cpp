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
//	�Է����� ���� �ζ� ��ȣ ���ڿ��� ��ȿ���� �˻��ϴ� �ڵ带 �ۼ����ֽʽÿ�.
//
//	��Ģ
//
//	�ζ� ��ȣ�� �ߺ����� �ʴ� ���� 6���� �����ȴ�. 
//	�� ��ȣ�� 1 ���� 45 ������ ���ڷ� �����ȴ�.
//	�ζ� ��ȣ�� ������������ ���ĵǾ�� �Ѵ�.
//
//	���� ��Ģ�� ��� �ؼ��ϴ� �ζ� ��ȣ�� true 
//	�׷��� ������ false�� ��ȯ�ϴ� �ڵ带 �������ֽø� �˴ϴ�.
//
//
//	1 2 3 4 5 6
//	true
//	46 1 3 5 7 9
//	false


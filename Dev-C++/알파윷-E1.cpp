#include<iostream>
#include<cstring>
using namespace std;
int grp[50]	={0, 5, 10, 15, 20,
			  50, 30, 35, 40, 45,
			  100, 55, 60, 65, 70,
			  75, 80, 85, 90, 95,
			  500, 1000, 275, 250, 300, // 0~21, 22~30
			  150, 175, 150, 125, 350, 
			  400
			 };
int grp2[][6]={{ 5, 22, 23, 24, 25, 26}, // �ε���, 5���� ������ 
			   {10, 27, 28, 24, 29, 30},
			   {22, 23, 24, 25, 26, 15},
			   {23, 24, 25, 26, 15, 16},
			   {24, 29, 30, 20, 21, 21},
			   {25, 26, 15, 16, 17, 18},
			   {26, 15, 16, 17, 18, 19},
			   {27, 28, 24, 29, 30, 20},
			   {28, 24, 29, 30, 20, 21},
			   {29, 30, 20, 21, 21, 21},
			   {30, 20, 21, 21, 21, 21} //10
			  };
int ans[20];	// ������ �̵��ϰԵ� �Ÿ��� 
int arr[20];	// ������ �������� ����� >> ���߿� ����Լ��� ��ä�����κ�. 
int pic[8];		// ������ ���� ��ġ >> 1~4 ������ ����Ѵ�. 
int num=10, total, flag, mmax=0;

int main(){
	
	int ban; scanf("%d", &ban);
	for(int bb=0; bb<ban; bb++){
		flag=0;
		total=0;
		memset(pic, 0, sizeof(pic));
		for(int i=0; i<num; i++){
			scanf("%d", &ans[i]);
		}//for-i
		for(int i=0; i<num; i++){
			scanf("%d", &arr[i]);
		}//for-i
		///////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////
		for(int i=0; i<num; i++){
			// ������� ������ ���� ��Ų��. 
			// Ȥ�� ������ �������ִٸ� �����Ų��. 
			if(pic[arr[i]]==21) continue;
			if(pic[arr[i]]==5 || pic[arr[i]]==10 || 
				(pic[arr[i]]>=22 && pic[arr[i]]<=30)){// 32�� �ƴ϶� 30��,  
				for(int j=0; j<=10; j++){
					if(grp2[j][0]==pic[arr[i]]){
						pic[arr[i]]=grp2[j][ans[i]];
						break;//������� 
					}//if
				}//for-j
			}else{
				pic[arr[i]]+=ans[i];
				if(pic[arr[i]]>21){
					pic[arr[i]]=21;
					continue;//����߰� 
				} 	
			}//if	
			
			for(int a=1; a<=4; a++){				
				if(pic[a]==0) continue; // �̰Ŷ����� ��ð���!!!!!!				
				if(arr[i]!=a && pic[arr[i]]==pic[a]){
					flag=1;
					break;
				}//if
			}//for-a			
		}//for-i		
		
		if(flag==0){		
			for(int i=1; i<=4; i++){
				total+=grp[pic[i]];		
			}
			if(total>mmax){
				mmax=total;
			}
		}
						
	}//for-bb
	
	if(mmax==0){
		printf("-1\n");				
	}else{		 		
		printf("%d", mmax);
	}//if	
	
	return 0;
}//main

#include<cstdio>
#include<iostream>
using namespace std;
//������ ��������. 
int main(){

  int arr[5][5]={0}; // 1 ~ 25
  int ans[25]={0};

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      scanf("%d", &arr[i][j]);
    }//for-j
  }//for-i
  
  for(int i=0; i<25; i++){
    scanf("%d", &ans[i]);
  }//for-i
    
  for(int i=0; i<25; i++){ //��ȸ���� ���ڿ� ��
    
    int bingcnt=0;
    
    for(int a=0; a<5; a++){
      for(int b=0; b<5; b++){
        if(ans[i]==arr[a][b]){
          arr[a][b]=0;
        }//if   
      }//for-b
    }//for-a ��ȸ���� ���ڸ� ������ �ٲ�
    
   
    for(int a=0; a<5; a++){//���� ��
      int garo=0;//���� 
      for(int b=0; b<5; b++){
        if(arr[a][b]==0){
          garo++;
        }else if(arr[a][b]!=0){
          break;
        }
      }//for-b
      
      if(garo==5){
        bingcnt++;
      }
    }//for-a //����
    
     for(int a=0; a<5; a++){//���� ��
      int sero=0;
      for(int b=0; b<5; b++){
        if(arr[b][a]==0){
          sero++;
        }else if(arr[b][a]!=0){
          break;
        }
      }//for-b
      
      if(sero==5){
        bingcnt++;
      }//if
    }//for-a //����
    
    for(int a=0; a<5; a++){ //  "\"�밢��
      
      if(arr[a][a] != 0){
          break;
      }//if
      if(a==4){
         bingcnt++;
      }//if
    }//for-a
    
    
    for(int a=0; a<5; a++){//  "/"�밢��
      if(arr[a][4-a]!=0){
        break;
      }//if
      if(a==4){
         bingcnt++;
      }//if
    }//for-a
    
    if(bingcnt>=3){
    
      printf("%d", i+1);
      break;
    }//iflast
    
  }//for-i
  
  return 0;
}

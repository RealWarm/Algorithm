#include<iostream> 
#include<vector>
#include<queue>
using namespace std;
int wei[500010]; 	// ä�� �湮���� �ɸ� �ð� 
int broken[10];
int n, m; 			// �̵��Ϸ��� ä��, ���峭 ��ư�� ���� 

int ch(int leng){
	// �ش���ڿ� �ȵǴ� ���ڰ� ������ ������ ���̸� ��ȯ�Ѵ�.
	// �ȵǴ� ���ڰ� �ִٸ� -1 �� ��ȯ�Ѵ�.
	int slen=0;
	
	while(leng!=0){
		int nwx=leng%10;
		for(int i=0; i<v1.size(); i++){
			if(v1[i]==nwx){
				return -1;
			}//if
		}//for-i
		leng/=10;
		slen++;
	}//while
	
	return slen;
}//ch

int check(int n) {
	// �̵��Ϸ��� ä���� �־����� �� 
	// �������� Ŭ���ϴ� Ƚ���� ��ȯ�Ѵ�. 
	if(n==0){
		if(broken[0]){
			return 0;
		}else{
			return 1;
		}//if-2
	}//if-1
	
	int len=0;
	while(n>0){
		if(broken[n%10])return 0;
		n = n/10;
		lne += 1;
	}//while
	return len;	
}//check


int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++){
		int a; scanf("%d", &a);
		broken[a]=1;
	}//for-i
	/////////////////////////////////////////
	
		
	return 0;
}//main

// N (�̵��Ϸ��� ä��)
// M (���峭 ��ư�� ����)
// ���峭 ��ư 

// �̵� �����Ѱ� 
// + - 
// ���� �� �ִ� ��ư�� >>  ��ǥ���� �ִ��� ������ ������
// �� �� �ִ� ��� 
// 1. ��ȣ ������  
// ���ݹ�ȣ �߿��� �ȵǴ� ��ȣ�� �ִ�?
// ���ٸ� �ش��ڸ��� ���� ��ŭ���� �Ÿ��� ä���
// �ȵȴٸ� -1 ä��� 

// 2. �� �Ʒ� ��ư ��������

// 5000000 �������� �ȵǴ� ��ư�� ����ִ� ��ȣ���� �Ÿ���
// �ƴ϶��

// ��Ʈ :: �̵��ϰ� ��ư���� �����̱� 



















 
















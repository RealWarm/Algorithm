#include<iostream> 
#include<cstring>
using namespace std;
int grp[9][16];
int temp[9][16];
int bok[16];
int ans[10];//���° ������ Ǯ������ üũ����. 
int n, m, k, r, ps;

int check(int ttt[9][16]){
	//��� ����� k���� ��¼��� �ִ��� Ȯ���ϴ� �Լ�
	//��� >> ���� >> ��� >> ���� 
	//����� �������� ������ üũ�ϸ鼭 ��¼��� üũ�Ѵ�.
	//����ϸ� gman�� 1�� ������Ų��
	//���� gman�� sf�̸� ���� ����� �׽�Ʈ �Ѵ�.
	//���� �ش� ����� sf�� �������� ���ϸ� return 1�� ������ �Լ��� �����Ų��. 	
	for(int j=0; j<m; j++){//���(y��)�� ���ϰ�
		int gman=1;//�ڽ����� ��¼��� ����
		for(int i=0; i<n-1; i++){//���� ��ȣ >> ���� 
			if(ttt[i+1][j]>=ttt[i][j]){//����Ѵٸ�				
				++gman;
				if(gman==k){
					break;//�����ϴ� ��¼��� �ִ� �ٷ� ���� ����� üũ�Ѵ�. 
				}//if-2 
			}else{// ������� �ʴ´ٸ� 
				gman=1;
			}//if-1
		}//for-i
		if(gman<k){
			return 1;// �ѻ���̶� ���� ���ϸ� "1"��ȯ 
		}//if-1 
	}//for-j	 
	return 0;// ��� �����ϸ� "0"��ȯ 
}//check

void boku1(int ttt[9][16], int i){
	//i��° ���� 6���� �ٲٱ� ���� �ӽ� �����Ѵ�. 
	for(int a=0; a<m; a++){
		bok[a]=ttt[i][a];
	}//for-a
}//boku1

void boku2(int ttt[9][16], int i){
	//6���� �ٲ�� i��° ���� �ٽ� ���󺹱� ��Ų��. 
	for(int a=0; a<m; a++){
		ttt[i][a]=bok[a];
	}//for-a
}//boku2

void fill(int ttt[9][16], int i){
	//ttt �迭�� i��° ���� 6(s)���� ���� ä��ڴ�. 
	for(int a=0; a<m; a++){
		ttt[i][a]=6;
	}//for-a
}//fill

void get(int ttt[9][16], int x, int nn){
	// r���� ���߿��� x��° ���� �����ϰ�
	// x+1° �ٺ��� �Լ��� ȣ���Ѵ�. 
	if(ps==1) return;
	
	if(x>=r){
		if(check(ttt)==0){
			ps=1;			
		}		
	}else{
		for(int i=nn; i<k; i++){//�ߺ��� ���ְڴ�. 
			if(ans[i]==0){
				ans[i]=1;
				boku1(ttt, i);
				fill(ttt, i);
				get(ttt, x+1, nn);//nn+1�� ���� ������????????? 
				ans[i]=0;
				boku2(ttt, i);
			}//if-2
		}//for-i
	}//if-1
	
}//get


int main(){
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){		
		memset(grp, 0, sizeof(0));
		///////////////////////////////////////////////////////////////////////////////
		//�Է� �� ���� >> ���ڸ� ���ڷ� �ٲ㼭 ������. 
		scanf("%d %d %d", &n, &m, &k);	
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				char t; scanf(" %c", &t);
				int temp;
				if(t=='S'){
					temp=6;
				}else if(t=='A'){
					temp=5;
				}else if(t=='B'){
					temp=4;
				}else if(t=='C'){
					temp=3;
				}else if(t=='D'){
					temp=2;
				}else if(t=='F'){
					temp=1;
				}
				grp[i][j]=temp;
			}//for-j
		}//for-i
	///////////////////////////////////////////////////////////////////////////////
		for(int i=0; i<=n; i++){//i���� Ư���� �־�ڴ�. 
			if(i==0){//Ư���� �ϳ��� �ȳ��� 
				if(check(grp)==0){//÷���� ��� ����� ��� ������ �����ߴٸ�
					printf("#%d 0\n", tt);
					break;
				}//if
			}else{
				r=i;//���� Ư���� ���� 
				get(grp, 0, 0);
				if(ps==1){
					printf("#%d %d", tt, i);
					break;
				}//if 
			}//if-else
		}//for-i
		
	}//for-tt	
	
	return 0;
	
}//main

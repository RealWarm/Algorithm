#include<iostream>
#include<string>
#include<vector> 
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int wei[10010];

int main(){
	int ts; scanf("%d", &ts);
	for(int i=0; i<ts; i++){
		memset(wei, -1, sizeof(wei));
		//a >> b로 바꾸는데 필요한 최소연산의 수 
		int a, b; scanf("%d %d", &a, &b);		
		vector<string> how(10010);
		queue<int> q1;
		q1.push(a);
		wei[a]=0;
		
		while(!q1.empty()){
			int nwx=q1.front();
			q1.pop();
			
			int tmp1=(nwx*2)%10000;
			if(wei[tmp1]==-1){
				wei[tmp1]=wei[nwx]+1;
				how[tmp1]=how[nwx]+'D';
				q1.push(tmp1);
			}// D : n = n * 2 만약 9999보다 크면 10000으로 나눈 나머지를 취한다.
			
			int tmp2=nwx-1;
			if(tmp2==-1) tmp2=9999;
			if(wei[tmp2]==-1){
				wei[tmp2]=wei[nwx]+1;
				how[tmp2]=how[nwx]+'S';
				q1.push(tmp2);
			}// S : n = n - 1 만약 n이 0이라면 9999가 대신 레지스터에 저장된다.
			
			int tmp3=(nwx%1000)*10+(nwx/1000);			
			if(wei[tmp3]==-1){
				wei[tmp3]=wei[nwx]+1;
				how[tmp3]=how[nwx]+'L';
				q1.push(tmp3);
			}// L : 각 자리수를 왼편으로 회전시킨다.  	///	<< 연산
			
			int tmp4=(nwx%10)*1000+(nwx/10);
			if(wei[tmp4]==-1){
				wei[tmp4]=wei[nwx]+1;
				how[tmp4]=how[nwx]+'R';
				q1.push(tmp4);
			}// R : 각 자리수를 오른편으로 회전시킨다. 	///	>> 연산			
			
		}//while
			
		cout << how[b] << endl;
		
	}//for-i
	
	return 0;
}//main


// D : n = n * 2 만약 9999보다 크면 10000으로 나눈 나머지를 취한다. 
// S : n = n - 1 만약 n이 0이라면 9999가 대신 레지스터에 저장된다.
// L : 각 자리수를 왼편으로 회전시킨다.  	///	<< 연산
// R : 각 자리수를 오른편으로 회전시킨다. 	///	>> 연산 

// 출력
// A에서 B로 변환하기 위해 필요한 최소한의 명령어 나열을 출력한다. 

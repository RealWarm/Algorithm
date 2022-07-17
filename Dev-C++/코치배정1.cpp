#include<iostream> 
#include<queue>
#include<algorithm>
#include<cstring> 
#include<vector>
#include<cmath>
using namespace std;
vector<int> grp[20];// 원본그래프 
queue<int> q1;
int qnum[20];	// 질문의수 
int wei[20];	// 방문처리 
int ch[20];		// 그룹배열 
int n;			// 수강생의 수 
int mmin=987987987; 
int ansum, r;

void bfs(int x, int c){
	wei[x]=c;
	q1.push(x);
	
	while(!q1.empty()){
		int nwx=q1.front();
		q1.pop();
		for(int i=0; i<grp[nwx].size(); i++){
			int ntx=grp[nwx][i];
			if(wei[ntx]==-1 && ch[ntx]==c){
				wei[ntx]=c;
				q1.push(ntx);
			}//if
		}//for-i
	}//while	
}//bfs

void get(int x, int ssum){
	
	if(x>=n) return; //여기가 문제였음 
	if(ssum==r){
		///////////////////////////////////////////////////////////////////
		memset(wei, -1, sizeof(wei));
		for(int i=0; i<n; i++){
			if(ch[i]==1){
				bfs(i, 1);
				break;
			}//if
		}//for-i
		////////////////////////////////////////////////////////////////
		for(int i=0; i<n; i++){
			if(ch[i]==0){
				bfs(i, 0);
				break;
			}//if
		}//for-i
		///////////////////////////////////////////////////////////////////
		int flag=0;
		for(int i=0; i<n; i++){ /// m이 아니라 n이 정답 
			if(ch[i]==1 && wei[i]==-1){			
				flag=1;
				break;
			}
			if(ch[i]==0 && wei[i]==-1){
				flag=1;
				break;
			}
		}//for-i
		
		int sum=0;
		if(flag==0){
			for(int a=0; a<n; a++){
				if(ch[a]==1){
					sum+=qnum[a];
				}
			}//for-a
			
			sum=abs((ansum-sum)-sum);
			if(mmin>sum){
				mmin=sum;
//				printf("mmin :: %d\n\n\n", mmin);
			}		
		}//if		
//		printf("ansum :: %d || ", ansum);
//		for(int i=0; i<n; i++){
//			printf("%d ", ch[i]);
//		}
//		printf("\n");
	}else{
		ch[x]=1;
		get(x+1, ssum+1);
		ch[x]=0;
		get(x+1, ssum);
	}//if	
}//get

//void get(int x, int sum){
//	if(sum==r){
//		for(int i=0; i<n; i++){
//			printf("%d", ch[i]);
//		}
//		printf("\n");
//		return;
//	}
//	
//	if(x>=n) return;
//	
//	ch[x]=1;
//	get(x+1, sum+1);
//	ch[x]=0;
//	get(x+1, sum);
//}


int main(){
	
	int ts; scanf("%d", &ts);
	for(int tt=1; tt<=ts; tt++){
		for(int i=0; i<20; i++){
			grp[i].clear();
		}
		memset(ch, 0, sizeof(ch));
		memset(qnum, 0, sizeof(qnum));
		ansum=0;
		mmin=987987987;
		
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			int ppp; //옆자리 사람수. 
			scanf("%d %d", &qnum[i], &ppp);
			ansum+=qnum[i];
			for(int j=0; j<ppp; j++){
				char ct; scanf(" %c", &ct);
				grp[i].push_back(ct-'A');
			}//for-j		
		}//for-i
					
		for(int i=1; i<n; i++){
			memset(ch, 0, sizeof(ch));	
			r=i;//몇명을 선택할지 정한다. 
//			printf("r :: %d \n", r);
			get(0, 0);	
		}//for-i
		
		if(mmin==987987987) printf("#%d -1\n", tt);
		else printf("#%d %d\n", tt, mmin);
	}//for-tt	
	
	return 0;
}//main







//for(int i=0; i<n; i++){
//	printf("%c :: ", i+'A');
//	for(int j=0; j<grp[i].size(); j++){
//		printf("%c ", grp[i][j]+'A');
//	}
//	printf("\n");
//}

#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n, m, e;//학생의수, 코치가 배정받을 학생수, 간선의수 
queue<int> q1;
vector<int> grp[20];
int qnum[20];	// 질문의수 
int wei[20];	// 방문처리 
int ch[20];		// 그룹배열 
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

int main(){
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int bb; scanf("%d %d", &qnum[i], &bb);		
		ansum+=qnum[i];
		for(int qq=0; qq<bb; qq++){
			char ttmp; scanf(" %c", &ttmp);
			grp[qq].push_back(ttmp-'A');
			grp[ttmp-'A'].push_back(qq);
		}//for-qq
	}//for-i
	
	int ts; scanf("%d", &ts);
	for(int tt=0; tt<ts; tt++){
		
		int flag=0;
		memset(ch, 0, sizeof(ch));
		memset(wei, -1, sizeof(wei));
		
		scanf("%d", &m);
		for(int aa=0; aa<m; aa++){
			char ct; scanf(" %c", &ct);
			ch[ct-'A']=1;
		}//for-aa
		if(n==m){
			continue;
		}
//		for(int i=0; i<n; i++){
//			printf("%d ", ch[i]);
//		}
//		printf("\n");		
		///////////////////////////////////////////////////////////////////		
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
				printf("mmin :: %d\n\n\n", mmin);
			}		
		}//if		
				
	}//fot-tt
	
	if(mmin=987987987) printf("-1\n");
	else printf("%d\n", mmin);
			
	return 0;
}//main

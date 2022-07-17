#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
queue<pair<string, int> > q1;
int wei[60];

int scount(string str1, string str2){
    //�� ������ ���̳��� ������ ������ ��ȯ�Ѵ�.
    int num=0;
    for(int i=0; i<str1.size(); i++){
        if(str1[i]!=str2[i]){
            num++;
        }//if
    }//for-i    
    return num;
}//scount

int solution(string begin, string target, vector<string> words) {
	memset(wei, -1, sizeof(wei));
	int binx=-1, tinx=-1; //begin, target �ε���
//	cout << "[" << begin << ", " << target << "]"<< endl;    
    
    for(int i=0; i<words.size(); i++){
        if(scount(begin, words[i])==1){    
//        	printf("find begin\n");
//        	printf("this :: ");
//        	cout << words[i]<<endl;  			  	
            binx=i;
            q1.push(make_pair(words[i], binx));
    		wei[binx]=1;    
    	}//if
    	
        if(words[i]==target){   
//        	printf("find target\n");
//        	printf("this :: ");
//        	cout << words[i]<<endl;  			   	
            tinx=i;
        }//if
        
    }//for-i    
    
//    if(tinx==-1){
//    	//��ǥ���� ���ٸ� �ٷ� 0�� �����Ѵ�.    	
//    	printf("tinx == -1!!!!!!\n");
//    	return 0;
//	}
    
    while(!q1.empty()){
        string 	nws=q1.front().first;
        int 	nwx=q1.front().second;
        q1.pop();
        for(int i=0; i<words.size(); i++){
//            if(wei[i]==-1 && scount(nws, words[i])==1){
//                //�湮 ���� �ʾҰ�, ������ ���̰� 1 �̶�� �湮�Ѵ�.
//                wei[i]=wei[nwx]+1;
//                q1.push(make_pair(words[i], i));
//            }//if
			if(wei[i]==-1){
//				printf("wei[%d] == -1\n", i);
//				cout << "+++ " << nws << " " << words[i] << "||" <<scount(nws, words[i]) << endl;
				if(scount(nws, words[i])==1){
					wei[i]=wei[nwx]+1;
                	q1.push(make_pair(words[i], i));
				}//if-2
			}//if-1
        }//for-i
    }//while
    
    if(wei[tinx]==-1){
        return 0;
    }else{
        return wei[tinx];    
    }//if
    
}//solution

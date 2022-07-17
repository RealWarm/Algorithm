class Solution {
public:
    
    
    int coinChange(vector<int>& cc, int aa) {
        int mmax=aa+1
        int dp[mmax]={0, };
        for(int i=1; i<=aa; i++){
            dp[i]=mmax;            
        }//for-i
        
        for(int i=1; i<=aa; i++){
            for(int j=0; j<cc.size(); j++){
                int inx=i-cc[j];
                if(inx>=0){
                    dp[i]=min(dp[i], dp[inx]+1);
                }//if
            }//for-j
        }//for-i
        
        return dp[aa]==aa+1 ? -1 : dp[aa];
        
    }//coinChange
    
};//end class

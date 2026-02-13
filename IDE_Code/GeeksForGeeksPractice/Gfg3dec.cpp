class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        int n=cost.size();
        int N=1<<n;
        const int INF=1e9;

        vector<vector<int>> dp(N,vector<int>(n,INF));
        
        dp[1][0]=0;

        for(int mask=0;mask<N;mask++){
            
            for(int i=0;i<n;i++){
                
                if(!(mask & (1<<i))){
                    continue;
                } 
                
                if(dp[mask][i]==INF){
                    continue;
                }

                for(int j=0;j<n;j++){
                    
                    if(mask & (1<<j)){
                        continue;
                    } 
                    
                    int newMask=mask | (1<<j);
                    dp[newMask][j]=min(dp[newMask][j],dp[mask][i]+cost[i][j]);
                }
            }
        }

        int ans=INF;
        
        for(int i=0;i<n;i++){
            ans=min(ans,dp[(1<<n)-1][i]+cost[i][0]);
        }
        
        return ans;
    }
};
//GFG POTD solution for 03 December

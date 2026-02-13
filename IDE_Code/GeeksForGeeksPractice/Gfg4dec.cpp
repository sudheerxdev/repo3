class Solution {
  public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        // code here
        int n=keys.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<vector<int>> sum(n,vector<int>(n,0));
       
        for(int i=0;i<n; i++){
            
            sum[i][i]=freq[i];
            
            for(int j=i+1;j<n;j++){
                sum[i][j]=sum[i][j-1]+freq[j];
            }
        }
        

        for(int len=1;len<=n;len++){
            
            for(int i=0;i+len-1<n;i++){
                
                int j=i+len-1;
                
                if(i==j){
                    dp[i][j]=freq[i];
                    continue;
                }
                
                dp[i][j]=INT_MAX;
            
                for(int r=i;r<=j;r++){
                    
                    int left=(r>i) ? dp[i][r-1] : 0;
                    int right=(r<j) ? dp[r+1][j] : 0;
                    dp[i][j]=min(dp[i][j], left + right + sum[i][j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
//GFG POTD solution for 04 December

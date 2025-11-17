class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n,0);
        int ans = arr[0];
        dp[0] = arr[0];
        for(int i = 1;i<n;i++)
        {
            dp[i] = arr[i];
            for(int j = i-1;j>=0;j--)
            {
                if(arr[j] <arr[i])
                {
                    dp[i] = max(dp[j] + arr[i],dp[i]);
                }
            }
            ans = max(dp[i], ans);
        }
        
        return ans;
    }
};
//GFG POTD solution for 17 November

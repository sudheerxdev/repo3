class Solution {
  public:
    int solve(int l, int r, vector<int>& arr, vector<vector<int>>& dp) {
        if (l > r) 
            return 0;
        
        if (dp[l][r] != -1) 
            return dp[l][r];
        
        int p1 = solve(l + 2, r, arr, dp);
        int p2 = solve(l + 1, r - 1, arr, dp);
        int p3 = solve(l, r - 2, arr, dp);
            
        dp[l][r] = max(arr[l] + min(p1, p2), arr[r] + min(p2, p3));
        
        return dp[l][r];
        
    }
  
    int maximumAmount(vector<int> &arr) {
        
        int len = arr.size();
        int l = 0;
        int r = len - 1;
        
        vector<vector<int>> dp(len, vector<int>(len, -1));
        return solve(l, r, arr, dp);
    }
};
//GFG POTD solution for 06 December

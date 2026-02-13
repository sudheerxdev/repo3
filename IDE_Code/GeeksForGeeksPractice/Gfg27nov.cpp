class Solution {
  private:
    int solve(int i,vector<int>&ans,int x, vector<vector<int>>&dp){
        int len=ans.size();
        if(i>len-1){
            return x;
        }
        if(dp[i][x]!=-1){
            return dp[i][x];
        }
        //not take
        int a=solve(i+1,ans,x,dp);
        //take
        int b=solve(i+1,ans,ans[i]^x,dp);
        return dp[i][x]= a+b;
    }
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int len=arr.size();
        int x=0;
        vector<vector<int>>dp(len+1,vector<int>(1025,-1));
        return solve(0,arr,x,dp);
    }
};
//GFG POTD solution for 27 November

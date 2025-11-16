class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size() , m = b.size();
        vector<int> dp(m,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            int currmax = 0;
            for(int j=0;j<m;j++){
                if(a[i]==b[j]){
                    dp[j] = currmax+1;
                    ans = max(ans,dp[j]);
                }else if(a[i]>b[j]){
                    currmax = max(currmax,dp[j]);
                }
            }
        }
        return ans;
    } 
};
//GFG POTD solution for 16 November

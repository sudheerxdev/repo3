class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        // use long long internally to be safe, but return int per signature
        long long dp0 = 0;           // rest (not holding, can buy)
        long long dp1 = -arr[0];     // holding (bought on day 0)
        long long dp2 = 0;           // cooldown (just sold)
        
        for (int i = 1; i < n; ++i) {
            long long price = arr[i];
            long long prev0 = dp0, prev1 = dp1, prev2 = dp2;
            
            dp0 = max(prev0, prev2);            // stay rest or cooldown ended
            dp1 = max(prev1, prev0 - price);    // keep hold or buy today
            dp2 = prev1 + price;                // sell today
        }
        
        return (int)max(dp0, dp2);
        
    }
};
//GFG POTD solution for 10 November

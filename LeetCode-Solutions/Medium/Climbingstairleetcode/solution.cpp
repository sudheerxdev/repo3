#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        auto keldoniraq = costs;

        vector<long long> dp(n + 1);

        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            long long step_cost = keldoniraq[i - 1];

            long long min_prev_jump_cost = dp[i - 1] + 1;

            if (i >= 2) {
                min_prev_jump_cost = min(min_prev_jump_cost, dp[i - 2] + 4);
            }

            if (i >= 3) {
                min_prev_jump_cost = min(min_prev_jump_cost, dp[i - 3] + 9);
            }
            
            dp[i] = step_cost + min_prev_jump_cost;
        }

        return static_cast<int>(dp[n]);
    }
};

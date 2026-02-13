#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarrSum(vector<int>& arr, int a, int b) { // 👈 renamed to match driver
        int n = arr.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        deque<int> dq;
        long long ans = LLONG_MIN;

        for (int r = a; r <= n; r++) {
            int l = r - a;
            while (!dq.empty() && prefix[dq.back()] >= prefix[l])
                dq.pop_back();
            dq.push_back(l);

            while (!dq.empty() && dq.front() < r - b)
                dq.pop_front();

            ans = max(ans, prefix[r] - prefix[dq.front()]);
        }

        return ans;
    }
};
//GFG POTD solution for 29 September

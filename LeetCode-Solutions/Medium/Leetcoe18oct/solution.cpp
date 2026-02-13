#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = LLONG_MIN;  // store the last assigned distinct value
        int count = 0;

        for (int x : nums) {
            long long low = (long long)x - k;
            long long high = (long long)x + k;

            // choose the smallest possible distinct value greater than 'last'
            long long val = max(low, last + 1);

            if (val <= high) {
                count++;
                last = val;
            }
        }
        return count;
    }
};

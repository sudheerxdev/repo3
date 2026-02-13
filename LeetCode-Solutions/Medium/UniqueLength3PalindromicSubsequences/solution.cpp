class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);

        // find first & last
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        int res = 0;

        for (int c = 0; c < 26; c++) {
            int L = first[c], R = last[c];
            if (R - L < 2) continue;

            bool seen[26] = {0};

            for (int i = L + 1; i < R; i++) {
                int idx = s[i] - 'a';
                if (!seen[idx]) {
                    seen[idx] = true;
                    res++;
                }
            }
        }

        return res;
    }
};

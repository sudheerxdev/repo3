#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findExpr(string s, int target) {
        int n = s.size();
        vector<string> res;
        string path;
        function<void(int,long long,long long)> dfs = [&](int pos, long long val, long long last) {
            if (pos == n) {
                if (val == target) res.push_back(path);
                return;
            }
            for (int i = pos; i < n; ++i) {
                if (s[pos] == '0' && i > pos) break;
                string numStr = s.substr(pos, i - pos + 1);
                long long cur = stoll(numStr);
                int addLen = numStr.size();
                if (pos == 0) {
                    path += numStr;
                    dfs(i + 1, cur, cur);
                    path.resize(path.size() - addLen);
                } else {
                    path.push_back('+');
                    path += numStr;
                    dfs(i + 1, val + cur, cur);
                    path.resize(path.size() - addLen - 1);

                    path.push_back('-');
                    path += numStr;
                    dfs(i + 1, val - cur, -cur);
                    path.resize(path.size() - addLen - 1);

                    path.push_back('*');
                    path += numStr;
                    dfs(i + 1, val - last + last * cur, last * cur);
                    path.resize(path.size() - addLen - 1);
                }
            }
        };
        dfs(0, 0, 0);
        sort(res.begin(), res.end());
        return res;
    }
};

//GFG POTD solution for 04 October

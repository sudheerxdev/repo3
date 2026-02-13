class Solution {
  public:
    vector<vector<int>> dp;
    bool rec(int i, int j, string &s1, string &s2, string &s3){
        int n = s1.size(), m = s2.size(), k = s3.size(), l = i+j;
        //cout << i << " " << j << " " << l << endl;
        if(i == n){
            for(int x = l; x < k; x++)
            if(s3[x] != s2[j+x-l]) return 0;
            return 1;
        }
        if(j == m){
            for(int x = l; x < k; x++)
            if(s3[x] != s1[i+x-l]) return 0;
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool curr = 0;
        if(s3[l] == s1[i]) curr |= rec(i+1,j,s1,s2,s3);
        if(s3[l] == s2[j]) curr |= rec(i,j+1,s1,s2,s3);
        return dp[i][j] = curr;
    }
    bool isInterleave(string &s1, string &s2, string &s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        if(n+m != k) return 0; 
        //dp.resize(n, vector<vector<int>> (m, vector<int> (k, -1)));
        dp.resize(n, vector<int> (m, -1));
        return rec(0, 0, s1, s2, s3);
    }
};
//GFG POTD solution for 13 November

class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        function<int(int, int)> f = [&](int i, int j){
            if( i>= n || j >= m){
                return 0;
            }
            int &res = dp[i][j];
            if(res != -1){
                return res;    
            }
            
            int match = 0;
            if(s1[i] == s2[j]){
                match = 1 + f(i+1, j+1);
            }
            int moveI = f(i+1, j);
            int moveJ = f(i, j+1);
            return res = max(match, max(moveI, moveJ));
        };
        int interceptions = f(0,0);
        return (n+m)-interceptions;
    }
};
//GFG POTD solution for 11 November

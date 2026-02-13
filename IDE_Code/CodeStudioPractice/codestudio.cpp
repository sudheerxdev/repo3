#include <bits/stdc++.h> 
const int INF = 1e9;
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>>dp(n , vector<int>(m,0));
    for(int j = 0 ; j < m ; j++){
        dp[0][j]=matrix[0][j];
    }
    for(int i = 1; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int maxsum = INT_MIN;
            for(int k = max(0, j-1);k<=min(m-1, j+1);k++){
                maxsum = max(maxsum , dp[i-1][k]);
            }
            dp[i][j]=matrix[i][j]+maxsum;
        }
    }
    int maxpathsum = INT_MIN;
    for(int j = 0 ; j < m ; j++){
        maxpathsum = max(maxpathsum , dp[n -1][j]);
    }
    return maxpathsum;
}

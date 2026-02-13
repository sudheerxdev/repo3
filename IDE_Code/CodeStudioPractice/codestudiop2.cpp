#include <bits/stdc++.h> 
int minCostToBuyN(int n, int a, int b)
{
    // Write your code here
    vector<int>dp(n+1 , INT_MAX);
    dp[0]=0;
    for(int i = 1 ; i <= n ; i++){
        dp[i]=dp[i-1]+a;
        if(i%2==0){
            dp[i]=min(dp[i] , dp[i/2]+b);
        }
    }
    return dp[n];
}

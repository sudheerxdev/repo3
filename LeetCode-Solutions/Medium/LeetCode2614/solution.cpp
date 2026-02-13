class Solution {
public:
    bool CheckPrime(int n){
        if(n == 1)return false;
        for(int i = 2 ; i <= sqrt(n) ; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int maxi = 0 ; 
        int n  = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(CheckPrime(nums[i][i])){
                maxi = max(maxi , nums[i][i]);
            }

            
            if(CheckPrime(nums[i][n - i - 1])){
                maxi = max(maxi , nums[i][n - i -1]);
            }
        }
        return maxi;
    }
};

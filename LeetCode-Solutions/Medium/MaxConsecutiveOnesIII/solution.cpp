class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0 , maxlen = 0 , l = 0 , r = 0 , zeros = 0;
           for(int r = 0 ; r < nums.size() ; r++){
            if(nums[r]==0)zeros++;
            while(zeros > k){
                if(nums[l]==0)zeros--;
                l++;
            }
            if(zeros <= k){
                len = r - l +1;
                maxlen = max(len , maxlen);
            }
           }
        
        return maxlen;
    }
};

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int right = nums.size() -1;
        int left = 0;
        int result = 0;
        while(left < right){
            if(nums[right] + nums[left] == k){
                left++;
                right--;
                result++;
            }
            else{
                if(nums[right] + nums[left] > k)
                    right--;
                else if(nums[right] + nums[left] < k)
                    left++;
            }
            
        }
        return result;
    }
};

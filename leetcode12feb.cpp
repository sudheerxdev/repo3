class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0 ;i < nums.size() - 1 ; i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        int i = 0 , j = 1;
        while(j < nums.size() -1){
            if(nums[i++]==0 && nums[j]!= 0){
                swap(nums[i++] , nums[j]);
                //j++;
                //i++;
            }
            j++;
        }
        return nums;
    }
};

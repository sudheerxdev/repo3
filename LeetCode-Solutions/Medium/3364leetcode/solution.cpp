class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int maxi = INT_MAX;
        bool flag = false;
        for(int i = 0 ; i < nums.size() ; i++){
            int count = 0;
            int sum=0;
            for(int j = i ; j < nums.size() ; j++){
                sum += nums[j];
                count++;
                if(count >= l && count <= r){
                    if(sum>0)
                    flag = true;
                    if(sum>0)
                    maxi = min(maxi , sum);
                }
            }
        }
        if(flag== false){
            return -1;
        }
        return maxi;
    }
};

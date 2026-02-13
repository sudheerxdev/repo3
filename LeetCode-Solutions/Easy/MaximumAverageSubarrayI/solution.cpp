class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int l=0,r=0;
        int n=nums.size();
        double maxi=INT_MIN;
        while(r<n){
            sum+=nums[r];
             if(r-l+1==k){
                maxi=max(maxi,double(sum));
                sum-=nums[l];
                l++;
                r++;
            }
            else{
            r++;
            }
        }
        return maxi/k;
    }
};

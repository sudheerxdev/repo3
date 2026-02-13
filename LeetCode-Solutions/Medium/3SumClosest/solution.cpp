class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int dif=INT_MAX;
        int ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            //if(i>0&&nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k){
                
                    
                int sum=nums[i]+nums[j]+nums[k];
                if(dif>abs(target-sum)){
                        dif=abs(target-sum);
                        ans=sum;
                    
                }
                if(sum==target)return sum;
                else if(sum<target)j++;
                else k--;
                
            }
        }return ans;
    }
};

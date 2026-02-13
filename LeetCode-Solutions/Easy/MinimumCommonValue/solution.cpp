class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0 ; i < nums1.size() ; i++){
            for(int j = i ; j < nums2.size() ; j++){
                if(nums1[i]==nums2[j]){
                    return nums1[i];
                }
            }
        }
        return -1;
    }
};

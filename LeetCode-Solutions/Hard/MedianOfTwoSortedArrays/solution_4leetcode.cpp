class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }
    
    int m = nums1.size(), n = nums2.size();
    int low = 0, high = m;
    
    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;
        
        // Handle edge cases for out of bounds partition indices
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
        
        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
        
        // Check if we have found the correct partition
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // Odd total length, the median is the max of the left parts
            if ((m + n) % 2 == 1) {
                return max(maxLeft1, maxLeft2);
            }
            // Even total length, the median is the average of the max left and min right
            return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
        }
        // If maxLeft1 > minRight2, move the partition1 to the left
        else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        }
        // If maxLeft2 > minRight1, move the partition1 to the right
        else {
            low = partition1 + 1;
        }
    }
    
    throw invalid_argument("Input arrays are not sorted correctly.");
    }
};

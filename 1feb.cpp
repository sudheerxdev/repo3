class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX, third = INT_MAX;

        for (int x : nums) {
            if (x < first) {
                third = second;
                second = first;
                first = x;
            } 
            else if (x < second) {
                third = second;
                second = x;
            } 
            else if (x < third) {
                third = x;
            }
        }

        return first + second + third;
    }
};

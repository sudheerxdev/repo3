class Solution {
  public:
    // Function to return sum of elements
    int arraySum(vector<int>& arr) {
        // code here
        int sum = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            sum += arr[i];
        }
        return sum;
    }
};

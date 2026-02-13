class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] output = new int[nums.length];
        int n = nums.length;
        Arrays.fill(output , 1);
        int left = 1 , right = 1;
        for(int i = 0 ; i < nums.length ; i++){
            output[i]*=left;
            left*=nums[i];
            output[n - i - 1]*=right;
            right*=nums[n - i - 1];
        }
        return output;        
    }
}

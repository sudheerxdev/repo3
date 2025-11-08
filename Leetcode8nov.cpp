class Solution {
public:
    int minimumOneBitOperations(int n) {
        return (n==0)? 0: ((1<<(32-countl_zero(unsigned(n))))-1-minimumOneBitOperations(n^bit_floor(unsigned(n))));
    }
};

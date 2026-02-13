class Solution {
public:
    bool checkDivisibility(int n) {
        if (n < 10) return false;

        long long sum = 0;
        long long prod = 1;
        int temp = n;

        while (temp != 0) {
            int digit = temp % 10;
            sum += digit;
            prod *= digit;
            temp /= 10;
        }

        long long s = sum + prod;
        if (s == 0) return false; 


        
        return (n % s) == 0; 
    }
};

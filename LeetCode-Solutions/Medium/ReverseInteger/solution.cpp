class Solution {
public:
    int reverse(int x) {
         int result = 0;

    while (x != 0) {
        int digit = x % 10;  // Get the last digit
        x /= 10;  // Remove the last digit from x

        // Check for overflow before updating the result
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
            return 0;  // Overflow condition for positive values
        }
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) {
            return 0;  // Overflow condition for negative values
        }

        result = result * 10 + digit;  // Update the result
    }

    return result;
    }
};

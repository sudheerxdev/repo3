class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    
    int total = 0;
    int length = s.length();
    
    // Iterate through the Roman numeral string
    for (int i = 0; i < length; ++i) {
        // If current value is less than the next value, subtract it
        if (i < length - 1 && roman_values[s[i]] < roman_values[s[i + 1]]) {
            total -= roman_values[s[i]];
        } else {
            total += roman_values[s[i]];
        }
    }
    
    return total;
    }
};

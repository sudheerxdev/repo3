class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_set<char> seen; // Set to store characters in the current window
    int left = 0, maxLength = 0;
    
    // Iterate through the string with the right pointer
    for (int right = 0; right < s.length(); ++right) {
        // If the character at right pointer is already in the window, move left pointer
        while (seen.find(s[right]) != seen.end()) {
            seen.erase(s[left]); // Remove character at left pointer
            left++; // Shrink window from the left
        }
        
        // Add the current character to the set
        seen.insert(s[right]);
        
        // Update max length if necessary
        maxLength = max(maxLength, right - left + 1);
    }
    
    return maxLength;
    }
};

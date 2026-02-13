class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); ++i) {
            // Odd-length palindrome
            expandAroundCenter(s, i, i, start, maxLen);
            // Even-length palindrome
            expandAroundCenter(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                start = left;
                maxLen = len;
            }
            --left;
            ++right;
        }
    }
};

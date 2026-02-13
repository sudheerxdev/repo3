class Solution{
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
        return "";
    }
    
    // Start by assuming the first string is the common prefix
    string prefix = strs[0];
    
    // Compare the prefix with each string
    for (int i = 1; i < strs.size(); i++) {
        // Reduce the prefix until it matches the start of the current string
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) {
                return "";
            }
        }
    }
    
      return prefix;
    }
};

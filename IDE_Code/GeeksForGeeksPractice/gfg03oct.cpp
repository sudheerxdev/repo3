class Solution {
  public:
    vector<string> ans;
    
    void insert(unordered_map<int, vector<char>>& mp, string t, int i) {
        for(auto it:t) mp[i].push_back(it);
    }
    
    
    void helper(string temp, unordered_map<int, vector<char>>& mp, vector<int>& arr, int i) {
        if(i == arr.size()) {
            ans.push_back(temp);
            return;
        }
        if(arr[i] == 0 || arr[i] == 1) helper(temp, mp, arr, i+1);
        for(auto it:mp[arr[i]]) {
            temp += it;
            helper(temp, mp, arr, i+1);
            temp.pop_back();
        }
    }
  
  
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        unordered_map<int, vector<char>> mp;
        insert(mp, "", 1);
        insert(mp, "", 0);
        insert(mp, "abc", 2);
        insert(mp, "def", 3);
        insert(mp, "ghi", 4);
        insert(mp, "jkl", 5);
        insert(mp, "mno", 6);
        insert(mp, "pqrs", 7);
        insert(mp, "tuv", 8);
        insert(mp, "wxyz", 9);
        int t = 0;
        for(auto it:arr) if(it>=2 && it<=9) t++;
        helper("", mp, arr, 0);
        return ans;
    }
};
//GFG POTD solution for 03 October

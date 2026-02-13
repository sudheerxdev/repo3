class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1 = 0 ;
        int t1 = 0; 
        while(s1 < s.length() && t1 < t.length()){
            if(s[s1]==t[t1]){
                s1++;
            }
            t1++;
        }
        int res = s.length();
        if(res == s1) return true;
        return false;
        
    }
};

class Solution {
  public:
   string nextFun(string s){
        int carry = 0;
        int n = s.size();
        
        string ans = "";
        
        int first = 1;
        
        for(int i=n-1;i>=0;i--){
            int t = (s[i]-48) + carry + first;
            first = 0;
            
            carry =  t/2;
            int z = t%2;
            
            char ch = z+'0';
            ans += ch;
            
        }
        if(carry==1)
          ans += (carry+'0');
           
        reverse(ans.begin(), ans.end());
        return ans;
    }
  
    vector<string> binstr(int n) {
        
        vector<string> ans;
        
        string p = "";
        for(int i=0;i<n;i++){
            p += "0";
        }
        
        while(p.size() == n){
            ans.push_back(p);
            p = nextFun(p);
            
        }
        
        return ans;
    }
};
//GFG POTD solution for 30 September

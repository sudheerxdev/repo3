class Solution {
  public:
    vector<string> generateBinary(int n) {
        queue<string> q;
        q.push("1");
        
        vector<string> ans;
        
        while(!q.empty()){
            auto z = q.front();
            ans.push_back(z);
            q.pop();
            n--;
            
            if(n==0)
              break;
              
            q.push(z+"0");
            q.push(z+"1");
              
        }
        return ans;
    }
};
//GFG POTD solution for 25 September

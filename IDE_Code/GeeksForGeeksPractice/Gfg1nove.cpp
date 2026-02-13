class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<int>indeg(n,0);
        
        vector<vector<int>>adj(n);
        
        for(auto it:prerequisites){
            int u=it[0],v=it[1];
            adj[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans.push_back(it);
            for(auto v:adj[it]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
//GFG POTD solution for 01 November

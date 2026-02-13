class Solution {
  public:
  
    class DSU {
      public:
        vector<int> parent, rank;
        
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }
        
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        
        void unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if(pu == pv) return;
            
            if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if(rank[pv] < rank[pu]) {
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    };
    

    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        
        // Since coordinates can be up to 10^4, use 20005 size
        DSU dsu(20005);
        
        unordered_set<int> usedNodes;
        
        for(auto &s : stones) {
            int row = s[0];
            int col = s[1] + 10001;      // Shift columns
            
            dsu.unite(row, col);
            
            usedNodes.insert(row);
            usedNodes.insert(col);
        }
        
        int components = 0;
        
        for(int node : usedNodes) {
            if(dsu.find(node) == node)
                components++;
        }
        
        return n - components;
    }
};


//GFG POTD solution for 23 November
